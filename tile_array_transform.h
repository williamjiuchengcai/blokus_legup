#ifndef TILE_ARRAY_TRANSFORM_H
#define TILE_ARRAY_TRANSFORM_H

#include <stdio.h>
#include <stdlib.h>
#include "hand.h"

// ourTurn is 1 if it's our turn and 0 if it's the opponent's (player's) turn
int ourTurn;

// Updates a 5x5 tile array to contain a specific tile with orientation 0 within it
void getTileArray(char tile_array[5][5], char tile_num);

// Rotate the parameter 5x5 square array 90 degrees clockwise
void rotateTileCW(char tile_array[5][5]);

// Rotate the parameter 5x5 square array 90 degrees clockwise
void rotateTileCCW(char tile_array[5][5]);

// Flip the parameter 5x5 square array horizontally (along the y axis)
void flipTileHorizontal(char tile_array[5][5]);

// Flip the parameter 5x5 square array vertically (along the x axis)
void flipTileVertical(char tile_array[5][5]);

// Matrix transpose the parameter 5x5 square array
void transposeTile(char tile_array[5][5]);

// Rotate the parameter 5x5 square array by 180 degrees
void rotateTile180(char tile_array[5][5]);

// Flip the parameter 5x5 square array once vertically and rotate 90 degrees CW
void rotateAndFlipTile(char tile_array[5][5]);

// Alters the integer array "bounds[4]" to contain the left, right, upper, lower bounds of the tile, respectively.
// Note that that the values in bounds are the offsets from the centre of the array (i.e. can be negative)
void getTileBoundaries(char tile_array[5][5], int bounds[4]);

#endif
