#pragma once
#include "GraphicsLib.h"
#include <vector>
#include <cstdint>
#include <cstring> 
#include <memory>

class GraphicsDrawer : public GraphicsLib {
public:
    GraphicsDrawer(uint_least16_t w, uint_least16_t h) : GraphicsLib(w, h), width(w), height(h) {
        image = new uint8_t[width * height * 3]; // RGB
        std::memset(image, 0, width * height * 3); // Ініціалізація чорним кольором
    }

    ~GraphicsDrawer() {
        delete[] image;
    }

    void convertRGB565ToRGB888(uint_least16_t color, uint8_t& r, uint8_t& g, uint8_t& b) {
        // Extract 5-bit Red, 6-bit Green, and 5-bit Blue components
        r = (color >> 8) & 0xF8;            
        g = (color >> 3) & 0xFC;            
        b = (color << 3) & 0xF8;            
    }

    void fillScreen(uint_least16_t color) override {
        uint8_t r = (color >> 11) & 0x1F;
        uint8_t g = (color >> 5) & 0x3F;
        uint8_t b = color & 0x1F;

        r = (r * 255) / 31;
        g = (g * 255) / 63;
        b = (b * 255) / 31;

        for (int i = 0; i < width * height; ++i) {
            image[i * 3 + 0] = r; // Red
            image[i * 3 + 1] = g; // Green
            image[i * 3 + 2] = b; // Blue
        }
    }

    void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) override {
        if (x0 >= 0 && x0 < width && y0 >= 0 && y0 < height) {
            uint8_t r = (color >> 11) & 0x1F;
            uint8_t g = (color >> 5) & 0x3F;
            uint8_t b = color & 0x1F;

            r = (r * 255) / 31;
            g = (g * 255) / 63;
            b = (b * 255) / 31;

            image[(y0 * width + x0) * 3 + 0] = r;
            image[(y0 * width + x0) * 3 + 1] = g;
            image[(y0 * width + x0) * 3 + 2] = b;
        }
    }

    void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color) override {
        int x = x0;
        int y = y0;
        int dx = x1 - x0;
        int dy = y1 - y0;
        int absDx = abs(dx);
        int absDy = abs(dy);
        int xInc = (dx > 0) ? 1 : -1;
        int yInc = (dy > 0) ? 1 : -1;

        if (x0 == x1 && y0 == y1) {
            // Single point
            drawPixel(x, y, color);
        }
        else if (absDy <= absDx) {
            // Gentle slope
            int d = 2 * absDy - absDx;
            while (x != x1) {
                drawPixel(x, y, color);
                if (d > 0) {
                    y += yInc;
                    d += 2 * (absDy - absDx);
                }
                else {
                    d += 2 * absDy;
                }
                x += xInc;
            }
        }
        else {
            // Sharp slope
            int d = 2 * absDx - absDy;
            while (y != y1) {
                drawPixel(x, y, color);
                if (d > 0) {
                    x += xInc;
                    d += 2 * (absDx - absDy);
                }
                else {
                    d += 2 * absDx;
                }
                y += yInc;
            }
        }
        // Draw the final point
        drawPixel(x1, y1, color);
    }

    void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override {
        // Draw the four sides of the rectangle
        drawLine(x0, y0, x0 + w, y0, color);         // Top
        drawLine(x0, y0, x0, y0 + h, color);         // Left
        drawLine(x0 + w, y0, x0 + w, y0 + h, color); // Right
        drawLine(x0, y0 + h, x0 + w, y0 + h, color); // Bottom
    }

    void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override {
        uint8_t r = (color >> 11) & 0x1F;
        uint8_t g = (color >> 5) & 0x3F;
        uint8_t b = color & 0x1F;

        r = (r * 255) / 31;
        g = (g * 255) / 63;
        b = (b * 255) / 31;

        for (int y = y0; y < y0 + h && y < height; ++y) {
            for (int x = x0; x < x0 + w && x < width; ++x) {
                image[(y * width + x) * 3 + 0] = r;
                image[(y * width + x) * 3 + 1] = g;
                image[(y * width + x) * 3 + 2] = b;
            }
        }
    }

    void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override {
        int x = 0;
        int y = r_y;

        
        long r_x_squared = r_x * r_x;
        long r_y_squared = r_y * r_y;
        long two_r_x_squared = 2 * r_x_squared;
        long two_r_y_squared = 2 * r_y_squared;
        long p = r_y_squared - r_x_squared * r_y + r_x_squared / 4;

        
        long dx = 0;
        long dy = two_r_x_squared * y;

        while (dx < dy) {
            
            drawPixel(x0 + x, y0 + y, color);
            drawPixel(x0 - x, y0 + y, color);
            drawPixel(x0 + x, y0 - y, color);
            drawPixel(x0 - x, y0 - y, color);

            if (p < 0) {
                x++;
                dx += two_r_y_squared;
                p += r_y_squared + dx;
            }
            else {
                x++;
                y--;
                dx += two_r_y_squared;
                dy -= two_r_x_squared;
                p += r_y_squared + dx - dy;
            }
        }

        
        p = r_y_squared * (x + 0.5) * (x + 0.5) + r_x_squared * (y - 1) * (y - 1) - r_x_squared * r_y_squared;

        while (y >= 0) {
            
            drawPixel(x0 + x, y0 + y, color);
            drawPixel(x0 - x, y0 + y, color);
            drawPixel(x0 + x, y0 - y, color);
            drawPixel(x0 - x, y0 - y, color);

            if (p > 0) {
                y--;
                dy -= two_r_x_squared;
                p += r_x_squared - dy;
            }
            else {
                x++;
                y--;
                dx += two_r_y_squared;
                dy -= two_r_x_squared;
                p += r_x_squared + dx - dy;
            }
        }
    }

    void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override {
        int x = 0;
        int y = r_y;

        long r_x_squared = r_x * r_x;
        long r_y_squared = r_y * r_y;
        long two_r_x_squared = 2 * r_x_squared;
        long two_r_y_squared = 2 * r_y_squared;
        long p = r_y_squared - r_x_squared * r_y + r_x_squared / 4;

        long dx = 0;
        long dy = two_r_x_squared * y;

        while (dx < dy) {
        
            for (int i = x0 - x; i <= x0 + x; ++i) {
                drawPixel(i, y0 + y, color);
                drawPixel(i, y0 - y, color);
            }

            if (p < 0) {
                x++;
                dx += two_r_y_squared;
                p += r_y_squared + dx;
            }
            else {
                x++;
                y--;
                dx += two_r_y_squared;
                dy -= two_r_x_squared;
                p += r_y_squared + dx - dy;
            }
        }

      
        p = r_y_squared * (x + 0.5) * (x + 0.5) + r_x_squared * (y - 1) * (y - 1) - r_x_squared * r_y_squared;

        while (y >= 0) {
            
            for (int i = x0 - x; i <= x0 + x; ++i) {
                drawPixel(i, y0 + y, color);
                drawPixel(i, y0 - y, color);
            }

            if (p > 0) {
                y--;
                dy -= two_r_x_squared;
                p += r_x_squared - dy;
            }
            else {
                x++;
                y--;
                dx += two_r_y_squared;
                dy -= two_r_x_squared;
                p += r_x_squared + dx - dy;
            }
        }
    }

    int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) {
        
        extern const uint8_t font[128][5]; 

        if (c < 32 || c > 127) {
            c = '?'; 
        }

        for (int8_t i = 0; i < 5; ++i) { 
            uint8_t line = font[c - 32][i];

            for (int8_t j = 0; j < 8; ++j) { 
                if (line & 0x1) {
                    
                    if (size == 1) {
                        drawPixel(x + i, y + j, color);
                    }
                    else {
                        fillRect(x + i * size, y + j * size, size, size, color);
                    }
                }
                else if (bg != color) {
                    
                    if (size == 1) {
                        drawPixel(x + i, y + j, bg);
                    }
                    else {
                        fillRect(x + i * size, y + j * size, size, size, bg);
                    }
                }
                line >>= 1;
            }
        }

       
        if (bg != color) {
            if (size == 1) {
                drawPixel(x + 5, y, bg);
            }
            else {
                fillRect(x + 5 * size, y, size, 8 * size, bg);
            }
        }

        return x + 6 * size; 
    }

    int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) {
        return drawChar(x, y, static_cast<char>(c), color, bg, size);
    }

    int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size) {
        while (*s) {
            x = drawChar(x, y, *s++, color, bg, size);
        }
        return x;
    }

#define MAX_SPRITES 10
#define DISPLAY_WIDTH 128  // Приклад ширини екрану
#define DISPLAY_HEIGHT 64  // Приклад висоти екрану

    struct Sprite {
        int_least16_t width = 0;
        int_least16_t height = 0;
        std::unique_ptr<char[]> data = nullptr;
    };

    Sprite sprites[MAX_SPRITES];

    void loadSprite(uint_least8_t index, int_least16_t width, int_least16_t height, const char* data) {
        if (index >= MAX_SPRITES || width <= 0 || height <= 0 || !data) {
            return; 
        }

        sprites[index].data.reset();

        sprites[index].width = width;
        sprites[index].height = height;
        sprites[index].data = std::make_unique<char[]>(width * height);
        std::memcpy(sprites[index].data.get(), data, width * height);
    }

    void showSprite(uint_least8_t index, uint_least16_t x, uint_least16_t y) {
        if (index >= MAX_SPRITES || !sprites[index].data) {
            return; // Невірний індекс або спрайт не завантажено
        }

        for (int_least16_t j = 0; j < sprites[index].height; ++j) {
            for (int_least16_t i = 0; i < sprites[index].width; ++i) {
                char pixel = sprites[index].data[j * sprites[index].width + i];

                // Пропустити прозорий піксель (якщо "0" вважається прозорим)
                if (pixel == 0) {
                    continue;
                }

                // Перевірка меж екрану
                if ((x + i) >= DISPLAY_WIDTH || (y + j) >= DISPLAY_HEIGHT) {
                    continue;
                }

                // Відображення пікселя
                drawPixel(x + i, y + j, static_cast<uint_least16_t>(pixel));
            }
        }
    }

    // Очищення пам'яті всіх спрайтів
    void clearAllSprites() {
        for (int i = 0; i < MAX_SPRITES; ++i) {
            sprites[i].data.reset();
        }
    }

private:
    uint_least16_t width, height;
    uint8_t* image; // Зображення в пам'яті
};
