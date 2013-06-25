#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include "hand.h"


#define BOARD_ROWS 14
#define BOARD_COLUMNS 14
#define MAX_INPUT_LEN 1000

void getAvailableMoves();
void getAvailableSquares();

// Retrieve the best move and place it in the array "move[4]" in the correct format.

// Note: for now this will just place a random piece/ position but later an algorithm
// will be used to think of the best move.
void getBestMove(char board_array[BOARD_COLUMNS][BOARD_ROWS], Hand *hand, char move[4]);

// Determines if a move can be placed in a corresponding position. Returns a 1 if yes and 0 if not.
int canPlace(char board_array[BOARD_COLUMNS][BOARD_ROWS], const char move[4]);

// Updates a move so that it is shown in the 2d array representing the current board status and removed from your hand.
int updateMove(char board_array[BOARD_COLUMNS][BOARD_ROWS], Hand *hand, const char move[4]);

#endif
