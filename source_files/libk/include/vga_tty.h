#define VGA_DEFAULT_WIDTH	80
#define VGA_DEFAULT_HEIGHT	25
#define VGA_DEFAULT_LOCATION	0xb8000
#define VGA_DEFAULT_COLOR	0x07 // Light gray on black

// This header is part of the compiler and not the C library.
#include <stdint.h>

// 16 colors are supported
enum	e_vga_color
{
	VGA_COLOR_BLACK		=	0,
	VGA_COLOR_BLUE		=	1,
	VGA_COLOR_GREEN		=	2,
	VGA_COLOR_CYAN		=	3,
	VGA_COLOR_RED		=	4,
	VGA_COLOR_MAGENTA	=	5,
	VGA_COLOR_BROWN		=	6,
	VGA_COLOR_LIGHT_GRAY	=	7,
	VGA_COLOR_DARK_GRAY	=	8,
	VGA_COLOR_LIGHT_BLUE	=	9,
	VGA_COLOR_LIGHT_GREEN	=	10,
	VGA_COLOR_LIGHT_CYAN	=	11,
	VGA_COLOR_LIGHT_RED	=	12,
	VGA_COLOR_LIGHT_MAGENTA	=	13,
	VGA_COLOR_LIGHT_BROWN	=	14,
	VGA_COLOR_WHITE		=	15,
};

void set_cursor_x(uint8_t x);
void set_cursor_y(uint8_t y);
const uint8_t get_color(void);
const uint8_t get_cursor_x(void);
const uint8_t get_cursor_y(void);

void terminal_init(void);
void terminal_clear_screen(void);
void terminal_scrollup(uint8_t n);
void terminal_setcolor(uint8_t color);
uint8_t vga_block_color(uint8_t foreground, uint8_t background);

// Put character and increment cursor
void terminal_putchar(unsigned char c);
// Put string and increment cursor
void terminal_putstring(const unsigned char *c);
// Put a block (character + color) at position but does not affect cursor
void terminal_putblock_at(unsigned char c, uint8_t color, uint8_t x, uint8_t y);
