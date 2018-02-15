#ifndef _DRIVER_SCREEN_H_
#define _DRIVER_SCREEN_H_

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

void print(char *msg);
void print_at(char *msg, int col, int row);
void clear_screen();
void print_backspace();

#endif

