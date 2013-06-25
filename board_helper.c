#include "board_helper.h"

int placeTile(char board_array[BOARD_COLUMNS][BOARD_ROWS], const char move[4])
{
    char x_centre, y_centre;
    char tile_array[5][5];
    int bounds [4];

    // Convert from ASCII to array indices
    x_centre = boardCoordToIndex(move[0]);
    y_centre = boardCoordToIndex(move[1]);

    getTransformedTileArray(tile_array, move);
    getTileBoundaries(tile_array, bounds);
    for(int i = bounds[0]; i <= bounds[1]; i++)
    {
        for(int j = bounds[2]; j <= bounds[3]; j++)
        {
            int x_coord = x_centre + i;
            int y_coord = y_centre + j;
            // Invalid move! The square isn't empty.
            if(board_array[x_coord][y_coord] != ' ' && tile_array[i + 2][j + 2] != ' ')
            {
                printf("Invalid move, square isn't empty!\n");
                printf("(%d,%d) on the board, (%d,%d) on the tile array", x_coord, y_coord, i + 2, j + 2);
                return -1;
            }


            if(tile_array[i + 2][j + 2] != ' ')
            {
                board_array[x_coord][y_coord] = tile_array[i + 2][j + 2];
                printf("Placing square at (%d,%d)\n", x_coord, y_coord);
            }
        }
    }

    return 0;
}

void getTransformedTileArray(char tile_array[5][5], const char move[4])
{
    char tile_num = move[2];
    char tile_orient = move[3];
    getTileArray(tile_array, tile_num);

    switch(tile_orient)
    {
        case '1':
            flipTileHorizontal(tile_array);
            break;

        case '2':
            rotateTileCW(tile_array);
            break;

        case '3':
            transposeTile(tile_array);
            break;

        case '4':
            rotateTile180(tile_array);
            break;

        case '5':
            flipTileVertical(tile_array);
            break;

        case '6':
            rotateTileCCW(tile_array);
            break;

        case '7':
            rotateAndFlipTile(tile_array);
            break;

        default:
            break;
    }
}

char indexToBoardCoord(char index)
{
    if(index >= 0 && index < 9)
        return index + 49;

    else if(index >= 9 && index <= 13)
        return index + 88;

    else
        return -1;
}

char boardCoordToIndex(char coord)
{
    if(coord >= '1' && coord <= '9')
        return coord - 49;

    else if(coord >= 'a' && coord <= 'u')
        return coord - 88;

    else
        return -1;
}


