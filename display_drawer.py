from PIL import Image, ImageDraw, ImageFont
import logging


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
        color = self.rgb565_to_rgb888(color565)
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
    
        try:
            font = ImageFont.truetype("arial.ttf", font_size) if font_size else self.font
        except IOError:
            logging.error("Font file not found. Using default font.")
            font = self.font  

        
        self.draw.text((x0, y0), text, fill=color, font=font)
        logging.info(f"Drew text '{text}' at ({x0}, {y0}) with color {color} and font size {font_size}")
 

    def draw_text_with_lines(self, x0, y0, text, color, font_size):
        color = self.rgb565_to_rgb888(color)
    
        # Зберігаємо початкове значення x0
        original_x0 = x0
    
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