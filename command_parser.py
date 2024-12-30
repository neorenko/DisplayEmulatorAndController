import struct
import logging


logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class Command:
    def __init__(self, command_id):
        self.id = command_id

    @staticmethod
    def parse_color(params):
        if len(params) != 2:
            raise ValueError("Invalid color format")
        return struct.unpack(">H", params)[0]


class ClearDisplayCommand(Command):
    def __init__(self, params):
        super().__init__(0x01)
        self.color = self.parse_color(params)
    
    def execute(self):
        logger.info(f"Clear display with color: RGB565({self.color})")
        return {"color": self.color}


class DrawPixelCommand(Command):
    def __init__(self, params):
        super().__init__(0x02)
        self.x, self.y = struct.unpack(">hh", params[:4])
        self.color = self.parse_color(params[4:])
    
    def execute(self):
        logger.info(f"Draw pixel at ({self.x}, {self.y}) with color RGB565({self.color})")
        return {"x": self.x, "y": self.y, "color": self.color}


class DrawLineCommand(Command):
    def __init__(self, params):
        super().__init__(0x03)
        self.x0, self.y0, self.x1, self.y1 = struct.unpack(">hhhh", params[:8])
        self.color = self.parse_color(params[8:])
    
    def execute(self):
        logger.info(f"Draw line from ({self.x0}, {self.y0}) to ({self.x1}, {self.y1}) with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "x1": self.x1, "y1": self.y1, "color": self.color}


class DrawRectangleCommand(Command):
    def __init__(self, params):
        super().__init__(0x04)
        self.x0, self.y0, self.w, self.h = struct.unpack(">hhhh", params[:8])
        self.color = self.parse_color(params[8:])
    
    def execute(self):
        logger.info(f"Draw rectangle at ({self.x0}, {self.y0}), width {self.w}, height {self.h}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "w": self.w, "h": self.h, "color": self.color}


class FillRectangleCommand(Command):
    def __init__(self, params):
        super().__init__(0x05)
        self.x0, self.y0, self.w, self.h = struct.unpack(">hhhh", params[:8])
        self.color = self.parse_color(params[8:])
    
    def execute(self):
        logger.info(f"Fill rectangle at ({self.x0}, {self.y0}), width {self.w}, height {self.h}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "w": self.w, "h": self.h, "color": self.color}


class DrawEllipseCommand(Command):
    def __init__(self, params):
        super().__init__(0x06)
        self.x0, self.y0, self.radius_x, self.radius_y = struct.unpack(">hhhh", params[:8])
        self.color = self.parse_color(params[8:])
    
    def execute(self):
        logger.info(f"Draw ellipse at ({self.x0}, {self.y0}), radius-x {self.radius_x}, radius-y {self.radius_y}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "radius_x": self.radius_x, "radius_y": self.radius_y, "color": self.color}


class FillEllipseCommand(Command):
    def __init__(self, params):
        super().__init__(0x07)
        self.x0, self.y0, self.radius_x, self.radius_y = struct.unpack(">hhhh", params[:8])
        self.color = self.parse_color(params[8:])
    
    def execute(self):
        logger.info(f"Fill ellipse at ({self.x0}, {self.y0}), radius-x {self.radius_x}, radius-y {self.radius_y}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "radius_x": self.radius_x, "radius_y": self.radius_y, "color": self.color}


class DrawCircleCommand(Command):
    def __init__(self, params):
        super().__init__(0x08)
        self.x0, self.y0, self.radius = struct.unpack(">hhH", params[:6])
        self.color = self.parse_color(params[6:])
    
    def execute(self):
        logger.info(f"Draw circle at ({self.x0}, {self.y0}), radius {self.radius}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "radius": self.radius, "color": self.color}


class FillCircleCommand(Command):
    def __init__(self, params):
        super().__init__(0x09)
        self.x0, self.y0, self.radius = struct.unpack(">hhH", params[:6])
        self.color = self.parse_color(params[6:])
    
    def execute(self):
        logger.info(f"Fill circle at ({self.x0}, {self.y0}), radius {self.radius}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "radius": self.radius, "color": self.color}


class DrawRoundedRectangleCommand(Command):
    def __init__(self, params):
        super().__init__(0x0A)
        self.x0, self.y0, self.w, self.h = struct.unpack(">hhhh", params[:8])
        self.radius = struct.unpack(">H", params[8:10])[0]
        self.color = self.parse_color(params[10:])
    
    def execute(self):
        logger.info(f"Draw rounded rectangle at ({self.x0}, {self.y0}), width {self.w}, height {self.h}, radius {self.radius}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "w": self.w, "h": self.h, "radius": self.radius, "color": self.color}


class FillRoundedRectangleCommand(Command):
    def __init__(self, params):
        super().__init__(0x0B)
        self.x0, self.y0, self.w, self.h = struct.unpack(">hhhh", params[:8])
        self.radius = struct.unpack(">H", params[8:10])[0]
        self.color = self.parse_color(params[10:])
    
    def execute(self):
        logger.info(f"Fill rounded rectangle at ({self.x0}, {self.y0}), width {self.w}, height {self.h}, radius {self.radius}, with color RGB565({self.color})")
        return {"x0": self.x0, "y0": self.y0, "w": self.w, "h": self.h, "radius": self.radius, "color": self.color}


class DrawTextCommand(Command):
    def __init__(self, params):
        super().__init__(0x0C)
        logger.info(f"Initializing DrawTextCommand with params: {params.hex()}")
        logger.info(f"Total length of params: {len(params)}")
        
        if len(params) < 8:
            raise ValueError("Insufficient bytes for Draw Text command.")
        
        self.x0, self.y0 = struct.unpack(">hh", params[:4])
        self.color = self.parse_color(params[4:6])
        # Map font size values (1-8) to actual pixel sizes
        font_sizes = {
            1: 8,    
            2: 12,   
            3: 16,   
            4: 20,   
            5: 24,   
            6: 32,   
            7: 48,   
            8: 64    
        }
        raw_font_size = params[6]
        self.font_size = font_sizes.get(raw_font_size, 16)  # Default to 16px if invalid
        self.length = params[7]
        
        logger.info(f"Parsed values: x0={self.x0}, y0={self.y0}, color={self.color}, raw_font={raw_font_size}, font_size={self.font_size}px, length={self.length}")
        logger.info(f"Expected text length: {self.length}")
        logger.info(f"Remaining bytes: {len(params[8:])}")
        
        actual_text_length = min(self.length, len(params) - 8)
        self.text = params[8:8 + actual_text_length].decode('utf-8', errors='ignore')
        logger.info(f"Decoded text: {self.text}")

    def execute(self):
        logger.info(f"Draw text '{self.text}' at ({self.x0}, {self.y0}) with color RGB565({self.color}), font size {self.font_size}")
        return {
            "x0": self.x0,
            "y0": self.y0,
            "color": self.color,
            "font_size": self.font_size,
            "text": self.text
        }


class TextCommandParser:
    def __init__(self):
        self.logger = logging.getLogger('text_command_parser')
        if not self.logger.handlers:
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
            handler.setFormatter(formatter)
            self.logger.addHandler(handler)
            self.logger.setLevel(logging.INFO)

    def validate_and_parse(self, params):
        self.logger.info(f"Processing Draw Text command. Params length: {len(params)}")
        
        if len(params) < 8:
            self.logger.error(f"Invalid number of parameters: expected at least 8, got {len(params)}")
            return False
            
        text_length = params[7]
        self.logger.info(f"Text length from params: {text_length}")
        
        min_expected_length = 8 + text_length - 1  # Мінімальна очікувана довжина
        max_expected_length = 8 + text_length      # Максимальна очікувана довжина
        
        self.logger.info(f"Expected length range: {min_expected_length}-{max_expected_length}")
        
        if len(params) < min_expected_length:
            self.logger.error(f"Invalid number of parameters: expected at least {min_expected_length}, got {len(params)}")
            return False
        
        if len(params) > max_expected_length:
            self.logger.warning(f"More parameters than expected: got {len(params)}, maximum expected was {max_expected_length}")
        
        self.logger.info("Draw Text command validation passed")
        return True


class DrawClockCommand(Command):
    def __init__(self, params):
        super().__init__(0x0D)  
        self.x0, self.y0 = struct.unpack(">hh", params[:4])
        self.color = self.parse_color(params[4:6])
        self.font_size = params[6]  # Розмір шрифту

    def execute(self):
        logger.info(f"Draw clock at ({self.x0}, {self.y0}) with color RGB565({self.color}) and font size {self.font_size}")
        return {
            "x0": self.x0,
            "y0": self.y0,
            "color": self.color,
            "font_size": self.font_size
        }


class DrawTextWithLinesCommand(Command):
    def __init__(self, params):
        super().__init__(0x0E)  # Встановлюємо унікальний ID для команди
        
        if len(params) < 8:
            raise ValueError("Insufficient bytes for Draw Text with Lines command.")
        
        self.x0, self.y0 = struct.unpack(">hh", params[:4])
        self.color = self.parse_color(params[4:6])
        self.font_size = params[6]  # Розмір шрифту
        
        # Визначаємо фактичну довжину тексту
        self.text = params[7:].decode('utf-8', errors='ignore')  # Декодуємо весь текст
        logger.info(f"Parsed values: x0={self.x0}, y0={self.y0}, color={self.color}, font_size={self.font_size}px, text='{self.text}'")

    def execute(self):
        logger.info(f"Draw text with lines '{self.text}' at ({self.x0}, {self.y0}) with color RGB565({self.color}), font size {self.font_size}")
        return {
            "x0": self.x0,
            "y0": self.y0,
            "color": self.color,
            "font_size": self.font_size,
            "text": self.text
        }


class SetOrientationCommand(Command):
    def __init__(self, params):
        super().__init__(0x0F)  # Встановлюємо унікальний ID для команди
        if len(params) != 1:
            raise ValueError("Invalid parameters for Set Orientation command")
        self.orientation = params[0]

    def execute(self):
        logger.info(f"Set orientation to {self.orientation}")
        return {"orientation": self.orientation}


class SetWidthCommand(Command):
    def __init__(self, params):
        super().__init__(0x10)  # Встановлюємо унікальний ID для команди
        if len(params) != 2:
            raise ValueError("Invalid parameters for Set Width command")
        self.width = struct.unpack(">H", params)[0]

    def execute(self):
        logger.info(f"Set width to {self.width}")
        return {"width": self.width}


class SetHeightCommand(Command):
    def __init__(self, params):
        super().__init__(0x11)  # Встановлюємо унікальний ID для команди
        if len(params) != 2:
            raise ValueError("Invalid parameters for Set Height command")
        self.height = struct.unpack(">H", params)[0]

    def execute(self):
        logger.info(f"Set height to {self.height}")
        return {"height": self.height}


class LoadSpriteCommand(Command):
    def __init__(self, params):
        super().__init__(0x12)  
        self.index, self.width, self.height = struct.unpack(">BHH", params[:5])
        self.data = params[5:]

    def execute(self):
        logger.info(f"Load sprite at index {self.index}, size {self.width}x{self.height}")
        return {
            "index": self.index,
            "width": self.width,
            "height": self.height,
            "data": self.data
        }


class ShowSpriteCommand(Command):
    def __init__(self, params):
        super().__init__(0x13)  
        self.index, self.x, self.y = struct.unpack(">Bhh", params[:7])

    def execute(self):
        logger.info(f"Show sprite at index {self.index} at position ({self.x}, {self.y})")
        return {
            "index": self.index,
            "x": self.x,
            "y": self.y
        }


class DrawMarqueeTextCommand(Command):
    def __init__(self, params):
        super().__init__(0x14) 
        if len(params) < 8: 
            raise ValueError("Insufficient bytes for Draw Marquee Text command.")
        
        self.y0 = struct.unpack(">h", params[:2])[0]  # Отримуємо координату y
        self.color = self.parse_color(params[2:4])  # Отримуємо колір
        self.font_size = params[4]  # Розмір шрифту
        text_length = params[5]  # Довжина тексту
        
        if len(params) < 6 + text_length:  # Перевірка на достатню кількість байтів для тексту
            raise ValueError("Insufficient bytes for Draw Marquee Text command, not enough bytes for text.")
        
        self.text = params[6:6 + text_length].decode('utf-8', errors='ignore') 

    def execute(self):
        logger.info(f"Draw marquee text '{self.text}' at y={self.y0} with color RGB565({self.color}), font size {self.font_size}")
        return {
            "y0": self.y0,
            "color": self.color,
            "font_size": self.font_size,
            "text": self.text
        }


class DisplayCommandParser:
    def __init__(self):
        self.logger = logging.getLogger('command_parser')
        if not self.logger.handlers:
            handler = logging.StreamHandler()
            formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
            handler.setFormatter(formatter)
            self.logger.addHandler(handler)
            self.logger.setLevel(logging.INFO)

        self.text_parser = TextCommandParser()
        self.commands = {
            0x01: ClearDisplayCommand,
            0x02: DrawPixelCommand,
            0x03: DrawLineCommand,
            0x04: DrawRectangleCommand,
            0x05: FillRectangleCommand,
            0x06: DrawEllipseCommand,
            0x07: FillEllipseCommand,
            0x08: DrawCircleCommand,
            0x09: FillCircleCommand,
            0x0A: DrawRoundedRectangleCommand,
            0x0B: FillRoundedRectangleCommand,
            0x0C: DrawTextCommand,
            0x0D: DrawClockCommand,
            0x0E: DrawTextWithLinesCommand,
            0x0F: SetOrientationCommand,
            0x10: SetWidthCommand,
            0x11: SetHeightCommand,
            0x12: LoadSpriteCommand,
            0x13: ShowSpriteCommand,
            0x14: DrawMarqueeTextCommand,
        }

        self.expected_lengths = {
            0x01: 2,   
            0x02: 6,   
            0x03: 10,  
            0x04: 10,  
            0x05: 10,  
            0x06: 10,  
            0x07: 10, 
            0x08: 8,   
            0x09: 8,   
            0x0A: 12,  
            0x0B: 12, 
            0x0C: None, 
            0x0D: 7,
            0x0E: None,
            0x0F: 1,  
            0x10: 2,   
            0x11: 2,  
            0x12: None,  
            0x13: 5,
            0x14: None,
        }

    def parse(self, byte_array):
        self.logger.info(f"Received byte array: {byte_array.hex()}")
        if not byte_array:
            raise ValueError("Byte array is empty")
            
        command_id = byte_array[0]
        params = byte_array[1:]
        self.logger.info(f"Command ID: {command_id}, Params: {params.hex()}")

        if command_id not in self.commands:
            self.logger.warning(f"Unknown command ID: {command_id}")
            return None

        if command_id == 0x0C:
            if not self.text_parser.validate_and_parse(params):
                return None
        else:
            expected_length = self.expected_lengths.get(command_id)
            if expected_length is not None and len(params) != expected_length:
                self.logger.error(f"Invalid number of parameters for command ID {command_id}: expected {expected_length}, got {len(params)}")
                return None

        command_class = self.commands[command_id]
        try:
            command_instance = command_class(params)
            result = command_instance.execute()
            result['command_id'] = command_id
            return result
        except Exception as e:
            self.logger.error(f"Error executing command {command_id}: {str(e)}", exc_info=True)
            return None