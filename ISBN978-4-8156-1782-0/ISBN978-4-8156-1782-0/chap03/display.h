#pragma once
#ifndef __DISPLAY
#define __DISPLAY

enum {
	BLACK,
	BLUE,
	RED,
	GREEN,
	MAGENTA,
	CYAN,
	YELLOW,
	WHITE,
	GRAY,
	BRIGHT_BLUE,
	BRIGHT_RED,
	BRIGHT_GREEN,
	BRIGHT_MAGENTA,
	BRIGHT_CYAN,
	BRIGHT_YELLOW,
	BRIGHT_WHITE,
};

// âÊñ è¡ãé
void cls(void);

// 
void locate(int __x, int __y);

void colorx(int __fg, int __bg);

void color(int __col);

#endif // !__DISPLAY
