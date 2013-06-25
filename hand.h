#ifndef HAND_H
#define HAND_H

#include <stdio.h>
#include <stdlib.h>

#define NUM_TILES 21
#define MAX_TILE_LEN 5
#define EMPTY_SQUARE ' '
#define OUR_SQUARE 'X'
#define OPP_SQUARE 'O'

typedef struct tile
{
    // Might include the bottom line of code to have a more visual interpretation of the tile...
    // char tile_array[MAX_TILE_LEN][MAX_TILE_LEN];
    int num_squares;
    int num_corners;
    char tile_number;
    int orientation;
} Tile;

typedef struct hand
{
    Tile *tiles_in_hand[NUM_TILES];
    int tiles_left;
    int squares_left;
} Hand;

void initialize_hand(Hand *player_hand);
void initialize_tile(Tile *tile_piece);


#endif
