import tkinter as tk
import logging
import datetime
import struct
from tkinter import ttk
from PIL import Image, ImageDraw, ImageTk, ImageFont
from udp_server import UDPServer
from command_parser import DisplayCommandParser
from display_drawer import DisplayDrawer


class DisplayEmulator:
    def __init__(self, width=1024, height=768):
        self.width = width
        self.height = height

        # Налаштування UDP сервера
        self.HOST = '127.0.0.1'
        self.PORT = 12345

        # Ініціалізація парсера команд
        self.command_parser = DisplayCommandParser()
        
        # Створення головного вікна
        self.root = tk.Tk()
        self.root.title("Display Emulator")
        
        # Встановлення розміру вікна
        self.root.geometry(f"{self.width}x{self.height}") 
        
        # Ініціалізація DisplayDrawer
        self.display_drawer = DisplayDrawer(self.width, self.height)

        self.canvas = tk.Canvas(self.root, width=self.width, height=self.height, bg='black')
        self.canvas.pack(fill=tk.BOTH, expand=True)

        # Обробник закриття вікна
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

        self.udp_server_running = False  
        
        # Створення UDP сервера
        self.udp_server = UDPServer(self.HOST, self.PORT, self.handle_udp_command)
        self.udp_server.start()
        self.udp_server_running = True  

    def set_display_size(self, width, height):
        self.width = width
        self.height = height
        self.update_display()

    def set_orientation(self, orientation):
  
       if orientation == 0:  
          self.width, self.height = 768, 1024
       elif orientation == 1: 
          self.width, self.height = 1024, 768
       elif orientation == 2:  
           self.width, self.height = 640, 960  
       elif orientation == 3:  
           self.width, self.height = 960, 640 
       
       self.root.geometry(f"{self.width}x{self.height}")
       self.update_display()

    def set_width(self, width):
       """Встановлює ширину дисплея."""
       command_bytes = struct.pack(">BH", 0x10, width) 
       self.process_command({"command_id": 0x10, "width": width})

    def set_height(self, height):
       command_bytes = struct.pack(">BH", 0x11,  height) 
       self.process_command({"command_id": 0x11, "width": height}) 

    def change_orientation(self, new_orientation):
        print(f"Changing orientation to {new_orientation}")
        self.orientation = new_orientation
        self.update_display()
 
    def get_current_time(self):
        """Отримує поточний час у форматі годин:хвилин:секунд."""
        now = datetime.datetime.now()
        return now.strftime("%H:%M:%S")

    def handle_udp_command(self, command_data):
        """Обробка отриманих команд через UDP."""
        self.root.after(0, lambda: self.process_command(command_data))

    def process_command(self, command_data):
        command_id = command_data['command_id']
        
        if command_id == 0x01:  # Clear Display
             color565 = command_data.get("color")  # Отримуємо колір з параметрів команди
             self.display_drawer.clear_display(color565)  # Передаємо колір у форматі RGB565
            
        elif command_id == 0x02:  # Draw Pixel
            x, y = command_data['x'], command_data['y']
            color = command_data['color']
            self.display_drawer.draw_pixel(x, y, color)
            
        elif command_id == 0x03:  # Draw Line
            x0, y0 = command_data['x0'], command_data['y0']
            x1, y1 = command_data['x1'], command_data['y1']
            color = command_data['color']
            self.display_drawer.draw_line(x0, y0, x1, y1, color)
            
        elif command_id == 0x04:  # Draw Rectangle
            x0, y0 = command_data['x0'], command_data['y0']
            w, h = command_data['w'], command_data['h']
            color = command_data['color']
            self.display_drawer.draw_rectangle(x0, y0, w, h, color)
            
        elif command_id == 0x05:  # Fill Rectangle
            x0, y0 = command_data['x0'], command_data['y0']
            w, h = command_data['w'], command_data['h']
            color = command_data['color']
            self.display_drawer.draw_rectangle(x0, y0, w, h, color, filled=True)

        elif command_id in (0x06, 0x07):  # DrawEllipse, FillEllipse
            x0, y0 = command_data['x0'], command_data['y0']
            radius_x, radius_y = command_data['radius_x'], command_data['radius_y']
            color = command_data['color']
            filled = command_id == 0x07
            self.display_drawer.draw_ellipse(x0, y0, radius_x, radius_y, color, filled)

        elif command_id in (0x08, 0x09):  # Draw/Fill Circle
            x0, y0 = command_data['x0'], command_data['y0']
            radius = command_data['radius']
            color = command_data['color']
            self.display_drawer.draw_circle(x0, y0, radius, color, filled=(command_id == 0x09))

        elif command_id in (0x0A, 0x0B):  # DrawRoundedRectangle, FillRoundedRectangle
            x0, y0 = command_data['x0'], command_data['y0']
            w, h = command_data['w'], command_data['h']
            radius = command_data['radius']
            color = command_data['color']
            filled = command_id == 0x0B
            self.display_drawer.draw_rounded_rectangle(x0, y0, w, h, radius, color, filled)
        
        elif command_id == 0x0C:  # Draw Text
            x0, y0 = command_data['x0'], command_data['y0']
            color = command_data['color']
            font_size = command_data['font_size']
            text = command_data['text']
            self.display_drawer.draw_text(x0, y0, text, color, font_size)

        elif command_id == 0x0D:  # Draw Clock
             x0, y0 = command_data['x0'], command_data['y0']
             color = command_data['color']
             font_size = command_data['font_size']
             self.display_drawer.draw_text(x0, y0, self.get_current_time(), color, font_size)
        
        elif command_id == 0x0E:  # Draw Text with Lines
             x0, y0 = command_data['x0'], command_data['y0']
             color = command_data['color']
             font_size = command_data['font_size']
             text = command_data['text']
             self.display_drawer.draw_text_with_lines(x0, y0, text, color, font_size)

        elif command_id == 0x0F:  # Set Orientation
            orientation = command_data.get("orientation")  
            self.set_orientation(orientation)  

        
        elif command_id == 0x10:  # Set Width
            width = command_data.get("width")
            self.width = width  
            self.update_display()  

        elif command_id == 0x11:  # Set Height
            height = command_data.get("height")
            self.height = height  
            self.update_display()  
        
        self.update_display()

    def update_display(self):
        print(f"Updating display to size: {self.width}x{self.height}")
        
        self.root.geometry(f"{self.width}x{self.height}")
        
        self.canvas.config(width=self.width, height=self.height)
        
        self.canvas.delete("all")

        image = self.display_drawer.get_image()
        image_tk = ImageTk.PhotoImage(image)
        
        self.canvas.create_image(0, 0, anchor="nw", image=image_tk)
        self.canvas._image = image_tk  
    
    def on_closing(self):
        """Обробник закриття вікна"""
        if self.udp_server_running:  
            self.udp_server.stop()  
            self.udp_server_running = False  
        self.root.quit()
        self.root.destroy()

    def run(self):
        try:
            self.root.mainloop()
        except KeyboardInterrupt:
            self.on_closing()
        except Exception as e:
            logging.error(f"An error occurred: {str(e)}")
        finally:
            self.running = False

if __name__ == "__main__":
    try:
        logging.basicConfig(level=logging.INFO, 
                          format='%(asctime)s - %(levelname)s - %(message)s')
        emulator = DisplayEmulator()
        emulator.set_orientation(1) 
        emulator.run()
    except Exception as e:
        logging.error(f"Fatal error: {str(e)}")


