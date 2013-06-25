#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "board_visual.h"
#include "hand.h"
#include "tile_array_transform.h"

int main()
{
    // Start at the sametime
    ourTurn = 1;
    // Instantiate and intialize an 2d array to represent the board
    char board_array[BOARD_COLUMNS][BOARD_ROWS] =
    {
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };

    // Instantiate and intialize our hand and the opponents hand.
    Hand our_hand, opp_hand;
    int opp_score, our_score;
    opp_score = 0;
    our_score = 0;
    initialize_hand(&our_hand);
    initialize_hand(&opp_hand);

    char initiate_match[MAX_INPUT_LEN];

    printf("Welcome to Blokus!\n\n");
    printf("Please enter '0' to initiate the match: ");

    /** All gets commands/ user input will be replaced by RS-232 data transfer. **/
    gets(initiate_match);
    if(strcmp(initiate_match, "0"))
    {
        printf("Invalid input! you entered %s which is not the right input\n", initiate_match);
    }

    else
    {

        /** Send over 1XX here to notify the host we have received the 0. **/

        char start_position[MAX_INPUT_LEN];
        printBoard(board_array);
        printf("Send the starting position for the program (either 25 or 2A): ");
        gets(start_position);
        if(!strcmp(start_position, "25"))
        {
            // Our default beginning move will be to place the '+' block's center at the start location

            /** Send over 55u0 to place + block **/
            board_array[4][4] = 'X';
            board_array[5][4] = 'X';
            board_array[4][5] = 'X';
            board_array[4][3] = 'X';
            board_array[3][4] = 'X';
            removeTile(&our_hand, 'u');

        }

        else if(!strcmp(start_position, "2A"))
        {

            /** Send over aau0 to place + block **/
            board_array[9][9] = 'X';
            board_array[9][10] = 'X';
            board_array[10][9] = 'X';
            board_array[8][9] = 'X';
            board_array[9][8] = 'X';
            removeTile(&our_hand, 'u');
        }

        else
        {
            printf("Invalid command!\n");
            return 0;
        }


        while(1)
        {
            opp_score = 89 - opp_hand.squares_left;
            our_score = 89 - our_hand.squares_left;
            printBoard(board_array);

            printf("Here are the available tiles for the computer: \n\n");
            printTilesAvailable(our_hand);

            printf("Here are the opponent's (player's) tiles: \n\n");
            printTilesAvailable(opp_hand);

            printf("Opponent score: %d, Computer score: %d\n\n", opp_score, our_score);
            printf("Make your move (xyto): ");

            char opp_move[4] = {0,0,0,0};
            char our_move[4] = {0,0,0,0};

            /** Replace gets with the move given by the host computer through RS-232 **/
            /** FOR NOW... assume that computer always goes first... and assume player always makes a legal move **/
            gets(opp_move);
            ourTurn = 0;
            if(opp_move[2] == '0')
                printf("Opponent (player) passes\n");

            else if(updateMove(board_array, &opp_hand, opp_move) != 0)
                return -1;

            ourTurn = 1;
            getBestMove(board_array, &our_hand, our_move);
            if(our_move[2] == 0)
                printf("Computer has no available moves\n");

            else if(updateMove(board_array, &our_hand, our_move) != 0)
                return -1;

            /** Send over move to host computer here **/

            // Gameover
            if(opp_move[2] == 0 && our_move[2] == 0)
                break;
        }
        printf("Game Over! Player (Opponent) score: %d, Computer (Our) score: %d\n", opp_score, our_score);
    }

    return 0;
}
