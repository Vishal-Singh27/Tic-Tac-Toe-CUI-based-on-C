#include "basiclibraries.h"
#include "board.h"
#include "minimax.h"

int main(void)
{
    Board *board = malloc(sizeof(Board));
    newboard(board);

    int gamemode = get_intfromstarttoend("Select a gamemode:\n1: Play with AI\n2: PVP\nAnswer: ",1, 2);

    int mainplayer;

    if (gamemode == 1)
    {
        do
        {
            mainplayer = get_char("What do you wanna play as (X / O): ");
        }
        while (mainplayer != 'X' && mainplayer != 'O');
    }

    else
    {
        mainplayer = 3;
    }
    
    while(true)
    {
        printf("\n");
        char player = turn(board);

        int row, col;
        if (player == mainplayer || mainplayer == 3)
        {
            do 
            {
                printf("Move of %c\n", turn(board));
                print_board(board);
                
                printf("Enter row and column (rows and columns are zero indexed): \n");
                row = get_int("Row: ");
                if (row > 3 || row < 0)
                {
                    printf("\nEnter a row no. in the range of 0 - 2!\n\n");
                    continue;
                }
                col = get_int("Column: ");
                if (col > 3 || col < 0)
                {
                    printf("\nEnter a row no. in the range of 0 - 2!\n\n");
                    continue;
                }

                if (board->boardarr[row][col] != ' ')
                {
                    printf("\nThat space is occupied!!\n\n");
                }
            } 
            while (board->boardarr[row][col] != ' ');
        }

        else
        {
            printf("AI is thinking...\n");
            int *rowcol = minimax(board);
            row = rowcol[0];
            col = rowcol[1];
        }

        changeboard(board, row, col, player);
        if (terminal(board))
        {
            print_winner(board);
            printf("Thnx for playing!\n");
            return 0;
        }
    }
}