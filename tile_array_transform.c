#include "tile_array_transform.h"

void getTileArray(char tile_array[5][5], char tile_num)
{
    // initialize array to all empty squares
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = EMPTY_SQUARE;
        }
    }

    // Depending on whose turn, return X's or O's
    char square;
    if(ourTurn)
        square = OUR_SQUARE;
    else
        square = OPP_SQUARE;

    // Always gonna be atleast 1 square in the middle
    tile_array[2][2] = square;

    switch(tile_num)
    {
        case 'a':
            break;

        case 'b':
            tile_array[2][3] = square;
            break;

        case 'c':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            break;

        case 'd':
            tile_array[3][2] = square;
            tile_array[2][1] = square;
            break;

        case 'e':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[2][4] = square;
            break;

        case 'f':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[1][3] = square;
            break;

        case 'g':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[3][2] = square;
            break;

        case 'h':
            tile_array[2][3] = square;
            tile_array[3][3] = square;
            tile_array[3][2] = square;
            break;

        case 'i':
            tile_array[1][2] = square;
            tile_array[2][3] = square;
            tile_array[3][3] = square;
            break;

        case 'j':
            tile_array[2][0] = square;
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[2][4] = square;
            break;

        case 'k':
            tile_array[2][0] = square;
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[1][3] = square;
            break;

        case 'l':
            tile_array[2][0] = square;
            tile_array[2][1] = square;
            tile_array[1][2] = square;
            tile_array[1][3] = square;
            break;

        case 'm':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[1][2] = square;
            tile_array[1][3] = square;
            break;

        case 'n':
            tile_array[2][1] = square;
            tile_array[1][1] = square;
            tile_array[2][3] = square;
            tile_array[1][3] = square;
            break;

        case 'o':
            tile_array[2][1] = square;
            tile_array[3][2] = square;
            tile_array[2][3] = square;
            tile_array[2][4] = square;
            break;

        case 'p':
            tile_array[2][1] = square;
            tile_array[2][3] = square;
            tile_array[1][3] = square;
            tile_array[3][3] = square;
            break;

        case 'q':
            tile_array[2][0] = square;
            tile_array[2][1] = square;
            tile_array[3][2] = square;
            tile_array[4][2] = square;
            break;

        case 'r':
            tile_array[2][1] = square;
            tile_array[1][1] = square;
            tile_array[3][2] = square;
            tile_array[3][3] = square;
            break;

        case 's':
            tile_array[1][1] = square;
            tile_array[1][2] = square;
            tile_array[3][2] = square;
            tile_array[3][3] = square;
            break;

        case 't':
            tile_array[1][1] = square;
            tile_array[1][2] = square;
            tile_array[2][3] = square;
            tile_array[3][2] = square;
            break;

        case 'u':
            tile_array[1][2] = square;
            tile_array[2][1] = square;
            tile_array[3][2] = square;
            tile_array[2][3] = square;
            break;

        default:
            break;
    }
}

// Right now this algorithm creates a new rotated array and copies that array to tile_array.
// I'm sure theres a better way to do this but it shouldn't be too taxing on memory/ time as it is.
void rotateTileCCW(char tile_array[5][5])
{
    char rotated_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            rotated_array[i][j] = tile_array[4-j][i];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = rotated_array[i][j];
        }
    }
}

void rotateTileCW(char tile_array[5][5])
{
    char rotated_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            rotated_array[i][j] = tile_array[j][4-i];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = rotated_array[i][j];
        }
    }
}

void flipTileVertical(char tile_array[5][5])
{
    char flipped_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            flipped_array[i][j] = tile_array[i][4-j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = flipped_array[i][j];
        }
    }
}

void flipTileHorizontal(char tile_array[5][5])
{
    char flipped_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            flipped_array[i][j] = tile_array[4-i][j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = flipped_array[i][j];
        }
    }
}

void transposeTile(char tile_array[5][5])
{
    char transposed_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            transposed_array[i][j] = tile_array[j][i];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = transposed_array[i][j];
        }
    }
}

void rotateTile180(char tile_array[5][5])
{
    char double_rotated_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            double_rotated_array[i][j] = tile_array[4-i][4-j];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = double_rotated_array[i][j];
        }
    }
}

// This function exists simply because a flip, then rotate can be done more efficiently
// than using a flip function, then a rotate function
void rotateAndFlipTile(char tile_array[5][5])
{
    char double_flipped_array[5][5];

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            double_flipped_array[i][j] = tile_array[4-j][4-i];
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            tile_array[i][j] = double_flipped_array[i][j];
        }
    }
}

void getTileBoundaries(char tile_array[5][5], int bounds[4])
{
    find_left_bound:
    // Left bound
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tile_array[i][j] != ' ')
            {
                bounds[0] = i - 2;
                goto find_right_bound;
            }
        }
    }

    find_right_bound:
    // Right bound
    for(int i = 4; i > 1; i--)
    {
        for(int j = 0; j < 5; j++)
        {
            if(tile_array[i][j] != ' ')
            {
                bounds[1] = i - 2;
                goto find_upper_bound;
            }
        }
    }

    find_upper_bound:
    // Upper bound
    for(int j = 0; j < 3; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            if(tile_array[i][j] != ' ')
            {
                bounds[2] = j - 2;
                goto find_lower_bound;
            }
        }
    }

    find_lower_bound:
    // Lower bound
    for(int j = 4; j > 1; j--)
    {
        for(int i = 0; i < 5; i++)
        {
            if(tile_array[i][j] != ' ')
            {
                bounds[3] = j - 2;
                return;
            }
        }
    }
}
