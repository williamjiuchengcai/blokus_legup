#include "hand.h"

void initialize_hand(Hand *player_hand)
{
    player_hand->tiles_left = 21;
    player_hand->squares_left = 89;
    for(int i = 0; i < NUM_TILES; i++)
    {
        player_hand->tiles_in_hand[i] = (Tile *)malloc(sizeof(Tile));
        player_hand->tiles_in_hand[i]->tile_number = i + 97;
        player_hand->tiles_in_hand[i]->orientation = 0;

        initialize_tile(player_hand->tiles_in_hand[i]);
    }
}

void initialize_tile(Tile *tile_piece)
{
    switch (tile_piece->tile_number)
    {
        case 'a':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 1;
            break;

        case 'b':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 2;
            break;

        case 'c':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 3;
            break;

        case 'd':
            tile_piece->num_corners = 5;
            tile_piece->num_squares = 3;
            break;

        case 'e':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 4;
            break;

        case 'f':
            tile_piece->num_corners = 5;
            tile_piece->num_squares = 4;
            break;

        case 'g':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 4;
            break;

        case 'h':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 4;
            break;

        case 'i':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 6;
            break;

        case 'j':
            tile_piece->num_corners = 4;
            tile_piece->num_squares = 5;
            break;

        case 'k':
            tile_piece->num_corners = 5;
            tile_piece->num_squares = 5;
            break;

        case 'l':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 5;
            break;

        case 'm':
            tile_piece->num_corners = 5;
            tile_piece->num_squares = 5;
            break;

        case 'n':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 5;
            break;

        case 'o':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 5;
            break;

        case 'p':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 5;
            break;

        case 'q':
            tile_piece->num_corners = 5;
            tile_piece->num_squares = 5;
            break;

        case 'r':
            tile_piece->num_corners = 7;
            tile_piece->num_squares = 5;
            break;

        case 's':
            tile_piece->num_corners = 6;
            tile_piece->num_squares = 5;
            break;

        case 't':
            tile_piece->num_corners = 7;
            tile_piece->num_squares = 5;
            break;

        case 'u':
            tile_piece->num_corners = 8;
            tile_piece->num_squares = 5;
            break;

        default:
            break;
    }
}

int removeTile(Hand *player_hand, char tile_number)
{
    // tile number to array index conversion
    int tile_index = tile_number - 97;
    printf("tile index is %d\n", tile_index);
    if(player_hand->tiles_in_hand[tile_index] != NULL)
    {
        int squares_removed = player_hand->tiles_in_hand[tile_index]->num_squares;

        free(player_hand->tiles_in_hand[tile_index]);
        player_hand->tiles_in_hand[tile_index] = NULL;
        player_hand->tiles_left = player_hand->tiles_left - 1;
        player_hand->squares_left = player_hand->squares_left - squares_removed;
        return 0;
    }

    printf("The tile has been played already\n");
    // The tile has already been played
    return -1;
}
