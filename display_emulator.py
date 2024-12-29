import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageDraw, ImageTk, ImageFont
import logging
import datetime
from udp_server import UDPServer
from command_parser import DisplayCommandParser


class DisplayDrawer:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.image = Image.new('RGB', (width, height), 'black')
        self.draw = ImageDraw.Draw(self.image)
        
        self.default_font_size = 20  
        self.font = ImageFont.truetype("arial.ttf", self.default_font_size) 


    def rgb565_to_rgb888(self, color565):
        r = (color565 >> 11) & 0x1F
        g = (color565 >> 5) & 0x3F
        b = color565 & 0x1F
        
        r = (r * 255) // 31
        g = (g * 255) // 63
        b = (b * 255) // 31
        
        return (r, g, b)

    def clear_display(self, color565):
        # Конвертуємо колір з RGB565 в RGB888
        color = self.rgb565_to_rgb888(color565)
        # Заповнюємо зображення кольором
        self.draw.rectangle([0, 0, self.width, self.height], fill=color)

    def draw_pixel(self, x, y, color):
        color = self.rgb565_to_rgb888(color)
        self.draw.point((x, y), fill=color)

    def draw_line(self, x0, y0, x1, y1, color):
        color = self.rgb565_to_rgb888(color)
        self.draw.line([(x0, y0), (x1, y1)], fill=color, width=2)

    def draw_rectangle(self, x0, y0, w, h, color, filled=False):
        color = self.rgb565_to_rgb888(color)
        if filled:
            self.draw.rectangle([x0, y0, x0 + w, y0 + h], fill=color)
        else:
            self.draw.rectangle([x0, y0, x0 + w, y0 + h], outline=color, width=2)

    def draw_circle(self, x0, y0, radius, color, filled=False):
        color = self.rgb565_to_rgb888(color)
        if filled:
            self.draw.ellipse([x0 - radius, y0 - radius, x0 + radius, y0 + radius], fill=color)
        else:
            self.draw.ellipse([x0 - radius, y0 - radius, x0 + radius, y0 + radius], outline=color, width=2)

    def draw_ellipse(self, x0, y0, w, h, color, filled=False):
        color = self.rgb565_to_rgb888(color)
        if filled:
            self.draw.ellipse([x0, y0, x0 + w, y0 + h], fill=color)
        else:
            self.draw.ellipse([x0, y0, x0 + w, y0 + h], outline=color, width=2)

    def draw_rounded_rectangle(self, x0, y0, w, h, radius, color, filled=False):
        color = self.rgb565_to_rgb888(color)
        if filled:
            self.draw.rounded_rectangle([x0, y0, x0 + w, y0 + h], radius=radius, fill=color)
        else:
            self.draw.rounded_rectangle([x0, y0, x0 + w, y0 + h], radius=radius, outline=color, width=2)

    def draw_text(self, x0, y0, text, color, font_size=None):
        color = self.rgb565_to_rgb888(color)
        
        font = ImageFont.truetype("arial.ttf", font_size) if font_size else self.font
        self.draw.text((x0, y0), text, fill=color, font=font)
 

    def draw_text_with_lines(self, x0, y0, text, color, font_size):
        color = self.rgb565_to_rgb888(color)
    
        # Зберігаємо початкове значення x0
        original_x0 = x0
    
        # Додаємо пробіл перед текстом
        text = " " + text  # Додаємо пробіл перед текстом
    
        # Малюємо текст по рядках
        for i, line in enumerate(text.splitlines()):
            for char in line:
               if char == 'A':
                   # Малюємо букву A
                  self.draw.line([(x0, y0 + 50), (x0 + 15, y0)], fill=color, width=2)  # Ліва діагональна лінія
                  self.draw.line([(x0 + 15, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права діагональна лінія
                  self.draw.line([(x0 + 5, y0 + 25), (x0 + 25, y0 + 25)], fill=color, width=2)  # Горизонтальна лінія
                  x0 += 35  # Зсув для наступної букви
                
               elif char == 'B':
                 # Малюємо букву B
                 self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                 self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                 self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                 self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                 self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 25)], fill=color, width=2)  # Права вертикальна лінія верхньої частини
                 self.draw.line([(x0 + 30, y0 + 25), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права вертикальна лінія нижньої частини
                 x0 += 35  # Зсув для наступної букви
               
               elif char == 'C':
                 # Малюємо букву C
                 self.draw.line([(x0 + 30, y0), (x0, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                 self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                 self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                 x0 += 35  # Зсув для наступної букви

               elif char == 'D':
                    # Малюємо букву D
                    self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                    self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                    self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права вертикальна лінія
                    self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                    x0 += 35  # Зсув для наступної букви

               elif char == 'E':
               # Малюємо букву E
                 self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                 self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                 self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                 self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                 x0 += 35  # Зсув для наступної букви 

               elif char == 'F':
               # Малюємо букву F
                  self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                  self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                  self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                  x0 += 35  # Зсув для наступної букви

               elif char == 'G':
                  # Малюємо букву G із закругленим верхом
                   self.draw.arc([(x0, y0), (x0 + 30, y0 + 50)], start=30, end=300, fill=color, width=2)  # Основна кругова частина G
                   self.draw.line([(x0 + 15, y0 + 25), (x0 + 27, y0 + 25)], fill=color, width=2)  # Проріз у середині
                   self.draw.line([(x0 + 27, y0 + 25), (x0 + 27, y0 + 40)], fill=color, width=2)  # Вертикальна лінія прорізу
                   x0 += 35  # Зсув для наступної букви

               elif char == 'H':
                  # Малюємо букву H
                   self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Горизонтальна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права вертикальна лінія
                   x0 += 35  # Зсув для наступної букви
            
               elif char == 'I':
                # Малюємо букву I
                self.draw.line([(x0, y0), (x0 + 20, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                self.draw.line([(x0 + 10, y0), (x0 + 10, y0 + 50)], fill=color, width=2)  # Центральна вертикальна лінія
                self.draw.line([(x0, y0 + 50), (x0 + 20, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                x0 += 25  # Зсув для наступної букви

               elif char == 'J':
               # Малюємо букву J
                 self.draw.line([(x0 + 10, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                 self.draw.line([(x0 + 20, y0), (x0 + 20, y0 + 40)], fill=color, width=2)  # Центральна вертикальна лінія
                 self.draw.arc([(x0, y0 + 30), (x0 + 20, y0 + 50)], start=0, end=180, fill=color, width=2)  # Закруглена нижня частина
                 x0 += 35  # Зсув для наступної букви

               elif char == 'K':
                   # Малюємо букву K
                   self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0 + 25), (x0 + 30, y0)], fill=color, width=2)  # Верхня діагональна лінія
                   self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня діагональна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'L':
                   # Малюємо букву L
                   self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'M':
                   
                    # Малюємо букву M
                   self.draw.line([(x0, y0 + 50), (x0, y0)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0), (x0 + 15, y0 + 25)], fill=color, width=2)  # Ліва діагональна лінія
                   self.draw.line([(x0 + 15, y0 + 25), (x0 + 30, y0)], fill=color, width=2)  # Права діагональна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права вертикальна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'N':
               # Малюємо букву N
                 self.draw.line([(x0, y0 + 50), (x0, y0)], fill=color, width=2)  # Ліва вертикальна лінія
                 self.draw.line([(x0, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Діагональна лінія
                 self.draw.line([(x0 + 30, y0 + 50), (x0 + 30, y0)], fill=color, width=2)  # Права вертикальна лінія
                 x0 += 35  # Зсув для наступної букви
              
               elif char == 'O':
                   # Малюємо букву O як закруглений прямокутник
                   x1 = x0 + 30  # Правий край
                   y1 = y0 + 50  # Нижній край
                   radius = 10  # Радіус закруглення
                   self.draw.rounded_rectangle([x0, y0, x1, y1], radius=radius, outline=color, width=2)
                   x0 += 35  # Зсув для наступної букви
               
               elif char == 'P':
                   # Малюємо букву P
                     self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                     self.draw.line([(x0, y0), (x0 + 20, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                     self.draw.line([(x0, y0 + 25), (x0 + 20, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                     self.draw.line([(x0 + 20, y0), (x0 + 20, y0 + 25)], fill=color, width=2)  # Права вертикальна лінія для верхньої частини
                     x0 += 25  # Зсув для наступної букви

               elif char == 'Q':
                 
                 x1 = x0 + 30  # Правий край
                 y1 = y0 + 50  # Нижній край
                 radius = 10  # Радіус закруглення
                 self.draw.rounded_rectangle([x0, y0, x1, y1], radius=radius, outline=color, width=2)  # Закруглений прямокутник для основної частини

                 
                 self.draw.line([(x0 + 15, y0 + 25), (x0 + 30, y0 + 50)], fill=color, width=2)  

                  # Зсув для наступної букви
                 x0 += 35
                
               elif char == 'R':
                   # Малюємо букву "R" з діагональною рискою
                   self.draw.line([(x0, y0), (x0, y0 + 50)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                   self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 25)], fill=color, width=2)  # Права вертикальна лінія до середини
                   self.draw.line([(x0 + 15, y0 + 25), (x0 + 30, y0 + 50)], fill=color, width=2)  # Діагональна лінія вниз
                   x0 += 35  # Зсув для наступної букви
                
               elif char == 'S':
                   # Малюємо букву "S"
                   self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                   self.draw.line([(x0, y0), (x0, y0 + 25)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0, y0 + 25), (x0 + 30, y0 + 25)], fill=color, width=2)  # Середня горизонтальна лінія
                   self.draw.line([(x0 + 30, y0 + 25), (x0 + 30, y0 + 50)], fill=color, width=2)  # Права вертикальна лінія
                   self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                   x0 += 35  # Зсув для наступної букви
                
               elif char == 'T':
                   # Малюємо букву "T"
                   self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                   self.draw.line([(x0 + 15, y0), (x0 + 15, y0 + 50)], fill=color, width=2)  # Центральна вертикальна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'U':
                   # Малюємо букву "U" з аркою внизу
                   self.draw.line([(x0, y0), (x0, y0 + 40)], fill=color, width=2)  # Ліва вертикальна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 30, y0 + 40)], fill=color, width=2)  # Права вертикальна лінія
                   self.draw.arc([(x0, y0 + 30), (x0 + 30, y0 + 50)], start=0, end=180, fill=color, width=2)  # Арка внизу
                   x0 += 35  # Зсув для наступної букви  

               elif char == 'V':
                   # Малюємо букву "V"
                   self.draw.line([(x0, y0), (x0 + 15, y0 + 50)], fill=color, width=2)  # Ліва діагональна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 15, y0 + 50)], fill=color, width=2)  # Права діагональна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'W':
                 

                    # Ліва діагональна лінія
                   self.draw.line([(x0, y0), (x0 + 15, y0 + 50)], fill=color, width=2)  # Ліва діагональна лінія
    
                      # Середні дві лінії
                   self.draw.line([(x0 + 15, y0 + 50), (x0 + 30, y0)], fill=color, width=2)  # Перша середня лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 45, y0 + 50)], fill=color, width=2)  # Друга середня лінія
    
                   # Права діагональна лінія
                   self.draw.line([(x0 + 45, y0 + 50), (x0 + 60, y0)], fill=color, width=2)  # Права діагональна лінія

                   
                   x0 += 70

               elif char == 'X':
                   # Малюємо букву "X"
                   self.draw.line([(x0, y0), (x0 + 30, y0 + 50)], fill=color, width=2)  # Ліва діагональна лінія
                   self.draw.line([(x0 + 30, y0), (x0, y0 + 50)], fill=color, width=2)  # Права діагональна лінія
                   x0 += 35  # Зсув для наступної букви

               elif char == 'Y':
                   # Малюємо букву "Y"
                   self.draw.line([(x0, y0), (x0 + 15, y0 + 25)], fill=color, width=2)  # Ліва верхня діагональна лінія
                   self.draw.line([(x0 + 30, y0), (x0 + 15, y0 + 25)], fill=color, width=2)  # Права верхня діагональна лінія
                   self.draw.line([(x0 + 15, y0 + 25), (x0 + 15, y0 + 50)], fill=color, width=2)  # Вертикальна лінія
                   x0 += 35  # Зсув для наступної букви
           
               elif char == 'Z':
                   # Малюємо букву "Z"
                   self.draw.line([(x0, y0), (x0 + 30, y0)], fill=color, width=2)  # Верхня горизонтальна лінія
                   self.draw.line([(x0 + 30, y0), (x0, y0 + 50)], fill=color, width=2)  # Діагональна лінія
                   self.draw.line([(x0, y0 + 50), (x0 + 30, y0 + 50)], fill=color, width=2)  # Нижня горизонтальна лінія
                   x0 += 35  # Зсув для наступної букви              
                   
        # Скидання x0 для наступного рядка
        x0 = original_x0    

    def get_image(self):
        return self.image
    

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
        self.root.geometry(f"{width + 200}x{height}")  
        
        # Налаштування мінімального розміру вікна
        self.root.minsize(width + 200, height)
        
        # Ініціалізація DisplayDrawer
        self.display_drawer = DisplayDrawer(width, height)

        # Обробник закриття вікна
        self.root.protocol("WM_DELETE_WINDOW", self.on_closing)

        # Флаг для контролю роботи сервера
        self.running = True
        
         # Створення UDP сервера
        self.udp_server = UDPServer(self.HOST, self.PORT, self.handle_udp_command)
        self.udp_server.start()
    
        # Словник для зберігання доступних команд
        self.commands = {
            "Clear Display": b'\x01\x00\x00',
            "Draw Pixel": b'\x02\x00\x32\x00\x32\x0F\xFF',
            "Draw Line": b'\x03\x00\x00\x00\x00\x00\x64\x00\x64\x0F\xFF',
            "Draw Rectangle": b'\x04\x00\x32\x00\x32\x00\x64\x00\x64\x0F\xFF',
            "Fill Rectangle": b'\x05\x00\x32\x00\x32\x00\x64\x00\x64\x0F\xFF',
            "Draw Ellipse": b'\x06\x00\x32\x00\x32\x00\x64\x00\x32\x0F\xFF',
            "Fill Ellipse": b'\x07\x00\x32\x00\x32\x00\x64\x00\x32\x0F\xFF',
            "Draw Circle": b'\x08\x00\x64\x00\x64\x00\x32\x0F\xFF',
            "Fill Circle ": b'\x09\x00\x64\x00\x64\x00\x32\x0F\xFF',
            "Draw Rounded Rectangle": b'\x0A\x00\x32\x00\x32\x00\x64\x00\x64\x00\x0A\x0F\xFF',
            "Fill Rounded Rectangle": b'\x0B\x00\x32\x00\x32\x00\x64\x00\x64\x00\x0A\x0F\xFF',
            "Draw Text": b'\x0C\x00\x32\x00\x32\xFF\xFF\x0C\x05Hello',
            "Draw Clock": b'\x0D\x00\x32\x00\x32\xFF\xFF\x10',
            "Draw Text with Lines": b'\x0E\x00\x32\x00\x32\xFF\xFF\x32HELLO WORLD'
        }

        # Створення віджетів
        self.create_widgets()

    def create_widgets(self):
        # Головний контейнер
        main_container = ttk.Frame(self.root)
        main_container.pack(fill=tk.BOTH, expand=True)
        
        # Фрейм для канваса
        self.canvas_frame = ttk.Frame(main_container)
        self.canvas_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Канвас для відображення зображення
        self.canvas = tk.Canvas(self.canvas_frame, width=self.width, height=self.height, bg='black')
        self.canvas.pack(fill=tk.BOTH, expand=True)

        # Фрейм для контролів
        self.control_frame = ttk.Frame(main_container, width=190)  # Фіксована ширина панелі керування
        self.control_frame.pack(side=tk.RIGHT, fill=tk.Y, padx=5, pady=5)
        self.control_frame.pack_propagate(False)  # Заборона зміни розміру фрейму
        
        # Заголовок панелі керування
        control_label = ttk.Label(self.control_frame, text="Control Panel", font=('Arial', 12, 'bold'))
        control_label.pack(pady=10)
        
        # Комбобокс для вибору команди
        command_label = ttk.Label(self.control_frame, text="Select Command:")
        command_label.pack(pady=(5, 0))
        
        self.command_var = tk.StringVar()
        self.command_combo = ttk.Combobox(self.control_frame, textvariable=self.command_var, width=25)
        self.command_combo['values'] = list(self.commands.keys())
        self.command_combo.pack(pady=5)
        
        # Кнопка виконання
        self.execute_button = ttk.Button(self.control_frame, text="Execute Command", 
                                       command=self.execute_command, width=20)
        self.execute_button.pack(pady=5)
        
        # Кнопка очищення
        self.clear_button = ttk.Button(self.control_frame, text="Clear Display", 
                                     command=self.clear_display, width=20)
        self.clear_button.pack(pady=5)
        
        # Додавання роздільника
        ttk.Separator(self.control_frame, orient='horizontal').pack(fill='x', pady=10)
        
        # Інформація про розмір дисплея
        size_info = ttk.Label(self.control_frame, 
                            text=f"Display Size:\n{self.width}x{self.height}",
                            justify=tk.CENTER)
        size_info.pack(pady=5)

        # Кнопка для відображення годинника
        self.clock_button = ttk.Button(self.control_frame, text="Draw Clock", 
                                command=self.draw_clock, width=20)
        self.clock_button.pack(pady=5)
        

    def draw_clock(self):
        # Start the clock drawing process
        self.update_clock()

    def update_clock(self):
        # Clear the area where the clock is drawn
        x0, y0 = 50, 50  # Set the position where the clock is drawn
        width, height = 200, 50  # Set the width and height of the area to clear

        # Clear the previous clock drawing by filling the rectangle with the background color
        self.display_drawer.draw_rectangle(x0, y0, width, height, color=0x0000, filled=True)  # Use filled=True to clear the area

        # Get the current time
        current_time = self.get_current_time()
    
        # Prepare the command bytes for drawing the clock
        command_bytes = self.commands["Draw Clock"]
    
        # Update the command with the current time
        result = self.command_parser.parse(command_bytes)
    
        if result:
            result['text'] = current_time  # Update the text with the current time
            logging.info(f"Parsed command: {result}")
        
            # Execute the command
            self.process_command(result)
        
            # Update the display
            self.update_display()
        
            # Schedule the next update after 1000 milliseconds (1 second)
            self.root.after(1000, self.update_clock)
        else:
           logging.error(f"Failed to parse command: Draw Clock")

    def get_current_time(self):
        """Отримує поточний час у форматі годин:хвилин:секунд."""
        now = datetime.datetime.now()
        return now.strftime("%H:%M:%S")

    def handle_udp_command(self, command_data):
        """Обробка отриманих команд через UDP."""
        # Виконання команди в головному потоці GUI
        self.root.after(0, lambda: self.process_command(command_data))

    def execute_command(self):
        """
        Виконує команду, вибрану через GUI.
        Викликається при натисканні кнопки "Execute Command".
        """
        selected_command = self.command_var.get()
        if selected_command in self.commands:
            try:
                # Отримуємо байти команди
                command_bytes = self.commands[selected_command]
                logging.info(f"Executing {selected_command}: {command_bytes.hex()}")
            
                # Парсимо команду
                result = self.command_parser.parse(command_bytes)
            
                if result:
                    logging.info(f"Parsed command: {result}")
                    # Виконуємо команду
                    self.process_command(result)
                    # Оновлюємо дисплей
                    self.update_display()
                else:
                    logging.error(f"Failed to parse command: {selected_command}")
            except Exception as e:
                logging.error(f"Error executing command {selected_command}: {str(e)}")

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
             
        self.update_display()

    def clear_display(self):
        self.display_drawer.clear_display()
        self.update_display()

    def update_display(self):
        image = self.display_drawer.get_image()
        image_tk = ImageTk.PhotoImage(image)
        self.canvas.delete("all")
        self.canvas.create_image(0, 0, anchor="nw", image=image_tk)
        self.canvas._image = image_tk

    def on_closing(self):
        """Обробник закриття вікна"""
        self.udp_server.stop()  
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
        emulator.run()
    except Exception as e:
        logging.error(f"Fatal error: {str(e)}")