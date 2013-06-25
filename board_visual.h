#ifndef BOARD_VISUAL_H
#define BOARD_VISUAL_H

#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "hand.h"

#define RESET		0
#define BRIGHT 		1
#define DIM		2
#define UNDERLINE 	3
#define BLINK		4
#define REVERSE		7
#define HIDDEN		8

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7


void printBoard(const char board_array[BOARD_COLUMNS][BOARD_ROWS]);

void printTilesAvailable(Hand hand);

void printTile(char tile_array[5][5]);

void textcolor(int attr, int fg, int bg);

#endif
