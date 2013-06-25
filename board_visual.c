#include "board_visual.h"


void printBoard(const char board_array[BOARD_COLUMNS][BOARD_ROWS])
{
    printf("Here is your board:\n\n");

    printf("   ");
    for(int i = 0; i < BOARD_COLUMNS; i++)
    {
        textcolor(BRIGHT, GREEN, BLACK);
        printf(" %c ", indexToBoardCoord(i));
    }
    printf("\n");
    for(int j = 0; j < BOARD_ROWS; j++)
    {
        textcolor(BRIGHT, GREEN, BLACK);
        printf(" %c ", indexToBoardCoord(j));
        for(int i = 0; i < BOARD_COLUMNS; i++)
        {
            if(board_array[i][j] == 'O')
                textcolor(BRIGHT, RED, BLACK);

            else if(board_array[i][j] == 'X')
                textcolor(BRIGHT, BLUE, BLACK);

            else
                textcolor(RESET, WHITE, BLACK);
            printf("[%c]",board_array[i][j]);

            textcolor(RESET, WHITE, BLACK);

        }
        printf("\n");
    }
}

void printTilesAvailable(Hand hand)
{
    for(int i = 0; i < NUM_TILES; i++)
    {
        if(hand.tiles_in_hand[i] != NULL)
            printf("[%c]",hand.tiles_in_hand[i]->tile_number);
        else
            printf("[ ]");
    }


    printf("\n\n");
}

void printTile(char tile_array[5][5])
{
    printf("Here is your tile:\n\n");
    for(int j = 0; j < 5; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            printf("[%c]", tile_array[i][j]);
        }
        printf("\n");
    }
}

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}
