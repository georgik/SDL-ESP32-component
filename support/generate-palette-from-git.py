import sys
from PIL import Image
import struct

def convert_color(c):
    """Convert 6-bit color to 8-bit color using the trick described."""
    return min(max((c << 2) | (c >> 4), 0), 255)

def generate_palette_from_gif(gif_file, output_file):
    # Open the GIF image
    with Image.open(gif_file) as img:
        if img.mode != 'P':
            raise ValueError('Image is not in 8-bit palette mode')
        
        # Extract the palette
        palette = img.getpalette()
        
        # Ensure the palette has 256 colors (768 values: 256 * 3)
        if len(palette) != 256 * 3:
            raise ValueError('Palette does not contain 256 colors')
        
        # Convert the palette colors
        converted_palette = []
        for i in range(256):
            r = convert_color(palette[i * 3])
            g = convert_color(palette[i * 3 + 1])
            b = convert_color(palette[i * 3 + 2])
            converted_palette.append((r, g, b))
        
        # Write the converted palette to a binary file
        with open(output_file, 'wb') as f:
            for color in converted_palette:
                f.write(struct.pack('BBB', color[0], color[1], color[2]))
    
    print(f'Converted palette written to {output_file}')

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_palette.py <input_gif_file> <output_palette_file>")
        sys.exit(1)
    
    input_gif_file = sys.argv[1]
    output_palette_file = sys.argv[2]
    
    generate_palette_from_gif(input_gif_file, output_palette_file)

