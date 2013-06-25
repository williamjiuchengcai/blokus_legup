#include "board.h"
#include "board_helper.h"


int updateMove(char board_array[BOARD_COLUMNS][BOARD_ROWS], Hand *hand, const char move[4])
{
    if(placeTile(board_array, move) == 0)
        return removeTile(hand, move[2]);
}

void getBestMove(char board_array[BOARD_COLUMNS][BOARD_ROWS], Hand *hand, char move[4])
{
    char tile_num = 't';
    char x_coord = 0;
    char y_coord = 0;
    char tile_orient = 0;
    for(; tile_num >= 'a'; tile_num --)
    {
        if(hand->tiles_in_hand[tile_num - 97] != NULL)
        {
            for(; tile_orient < 8; tile_orient ++)
            {
                for(; x_coord < BOARD_COLUMNS; x_coord ++)
                {
                    for(; y_coord < BOARD_ROWS; y_coord ++)
                    {
                        char temp_move[4];
                        temp_move[0] = indexToBoardCoord(x_coord);
                        temp_move[1] = indexToBoardCoord(y_coord);
                        temp_move[2] = tile_num;
                        temp_move[3] = tile_orient + 48;
                        if(canPlace(board_array, temp_move))
                        {
                            move[0] = temp_move[0];
                            move[1] = temp_move[1];
                            move[2] = temp_move[2];
                            move[3] = temp_move[3];
                            printf("Determined that the best move is %c%c%c%c\n",move[0],move[1],move[2],move[3]);
                            return;
                        }
                    }
                    y_coord = 0;
                }
                x_coord = 0;
            }
            tile_orient = 0;
        }
    }
}

/*int getAvailableMoves(char board_array[BOARD_ROWS][BOARD_COLUMNS], )

int getAvailableSquares(char board_array[BOARD_ROWS][BOARD_COLUMNS], )
{

}*/

int canPlace(char board_array[BOARD_COLUMNS][BOARD_ROWS], const char move[4])
{
    // Four step procedure: 1. See if off board
    // 2. See if the coordinates overlap with any existing tiles
    // 3. See if any edges are touching with our blocks
    // 4. See if atleast 1 corner is touching

    char x_centre = boardCoordToIndex(move[0]);
    char y_centre = boardCoordToIndex(move[1]);
    int bounds [4];
    char tile_array[5][5];
    int corner_touching = 0;

    getTransformedTileArray(tile_array, move);
    //printTile(tile_array);
    getTileBoundaries(tile_array, bounds);
    //printf("\n[%d][%d][%d][%d]\n", bounds[0], bounds[1], bounds[2], bounds[3]);

    for(int i = bounds[0]; i <= bounds[1]; i ++)
    {
        for(int j = bounds[2]; j <= bounds[3]; j ++)
        {
            int x_coord = x_centre + i;
            int y_coord = y_centre + j;

            // Check if coordinates are off the board
            if(x_coord >= BOARD_COLUMNS || x_coord < 0 || y_coord >= BOARD_ROWS || y_coord < 0)
                return 0;


            if(tile_array[i + 2][j + 2] != ' ')
            {
                // See if overlap with existing tiles
                if(board_array[x_coord][y_coord] != ' ')
                    return 0;

                // See if any edges are touching with our block
                if(board_array[x_coord + 1][y_coord] == 'X')
                    return 0;

                if(board_array[x_coord - 1][y_coord] == 'X')
                    return 0;

                if(board_array[x_coord][y_coord + 1] == 'X')
                    return 0;

                if(board_array[x_coord][y_coord - 1] == 'X')
                    return 0;

                // See if any corners are touching
                if(x_coord + 1 < BOARD_COLUMNS && y_coord + 1 < BOARD_ROWS && board_array[x_coord + 1][y_coord + 1] == 'X')
                    corner_touching = 1;

                if(x_coord + 1 < BOARD_COLUMNS && y_coord - 1 >= 0 && board_array[x_coord + 1][y_coord - 1] == 'X')
                    corner_touching = 1;

                if(x_coord - 1 >= 0 && y_coord + 1 < BOARD_ROWS && board_array[x_coord - 1][y_coord + 1] == 'X')
                    corner_touching = 1;

                if(x_coord - 1 >= 0 && y_coord - 1 >= 0 && board_array[x_coord - 1][y_coord - 1] == 'X')
                    corner_touching = 1;
            }
        }
    }
    if(corner_touching == 0)
        return 0;

    return 1;
}
