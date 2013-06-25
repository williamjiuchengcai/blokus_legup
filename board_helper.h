#ifndef BOARD_HELPER_H
#define BOARD_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include "hand.h"
#include "tile_array_transform.h"

#define BOARD_ROWS 14
#define BOARD_COLUMNS 14
#define MAX_INPUT_LEN 1000

// Places a tile with a specific orientation on the board array at specific coordinates.
// Returns -1 if failed, 0 if successful.
int placeTile(char board_array[BOARD_COLUMNS][BOARD_ROWS], const char opp_move[4]);

// Updates a 5x5 tile array to contain a specific tile with orientation 0 within it
void getTransformedTileArray(char tile_array[5][5], const char move[4]);

// Converts an array index to board coordinates
char indexToBoardCoord(char index);

// Converts a board coordinate to an array index
char boardCoordToIndex(char coord);

#endif
