#include "board.h"

void print_board(Board *board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            printf(" %c ", board->boardarr[i][f]);

            if (f != 2)
            {
                printf("|");
            }
        }
        printf("\n");

        // Printing a line
        if (i != 2)
        {
            for (int f = 0; f < 11; f++)
            {
                printf("-");
            }
        }

        printf("\n");
    }
}

Board *newboard(void)
{
    Board *board = malloc(sizeof(board));

    board->boardarr = malloc(sizeof(char *) * 3);
    
    for (int i = 0; i < 3; i++)
    {
        board->boardarr[i] = malloc(sizeof(char) * 3);

        for (int f = 0; f < 3; f++)
        {
            board->boardarr[i][f] = ' ';
        }
    }

    return board;
}

void changeboard(Board *board, int row, int col, char turn)
{
    board->boardarr[row][col] = turn;
}

char turn(Board *board)
{
    if (terminal(board))
    {
        printf("Internal error!\n");
        exit(1);
    }

    if (noofplaysof(board, 'X') == noofplaysof(board, 'O'))
    {
        return 'X';
    }

    return 'O';
}

bool terminal(Board *board)
{
    if (winner(board) != 'N')
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            if (board->boardarr[i][f] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int noofplaysof(Board *board, char player)
{
    if (player != 'X' && player != 'O')
    {
        printf("Internal Error..");
        exit(1);
    }
    
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            if (board->boardarr[i][f] == player)
            {
                count++;
            }
        }
    }
    
    return count;
}

char winner(Board *board)
{
    // Temporary character and int
    char tmp; 
    int status;
    int tmpi;
    int tmpf;

    // Checking horizontally
    for (int i = 0; i < 3; i++)
    {
        status = 0;
        tmp = board->boardarr[i][0];
        
        if (tmp != ' ')
        {
            for (int f = 1; f < 3; f++)
            {
                if (tmp != board->boardarr[i][f])
                {
                    status = 1;
                    break;
                }
            }
            
            if (status == 0)
            {
                return tmp;
            }
        }
    }

    // Checking vertically
    for (int f = 0; f < 3; f++)
    {
        status = 0;
        tmp = board->boardarr[0][f];

        if (tmp != ' ')
        {
            for (int i = 1; i < 3; i++)
            {
                if (tmp != board->boardarr[i][f])
                {
                    status = 1;
                    break;
                }
            }

            if (status == 0)
            {
                return tmp;
            }
        }
    }

    // Checking diagonally
    tmp = board->boardarr[0][0];
    status = 0;

    if (tmp != ' ')
    {
        for (int i = 1; i < 3; i++)
        {
            if (tmp != board->boardarr[i][i])
            {
                status = 1;
                break;
            }
        }

        if (status == 0)
        {
            return tmp;
        }
    }


    tmp = board->boardarr[0][2];
    status = 0;
    tmpi = 1; 
    tmpf = 1;

    if (tmp != ' ')
    {
        while (tmpi < 3 && tmpf > -1)
        {
            if (board->boardarr[tmpi][tmpf] != tmp)
            {
                status = 1;
                break;
            }

            tmpi++;
            tmpf--;
        }

        if (status == 0)
        {
            return tmp;
        }
    }

    return 'N';
}

void print_winner(Board *board)
{  
    char winnerplayer = winner(board);
    if (winnerplayer != 'N')
    {
        printf("The winner is: %c\n", winnerplayer);
    }

    else
    {
        printf("\nThe game is a tie!\n");
    }

    printf("\nFinal Board: \n");
    print_board(board);
}

actions *all_actions(Board *board)
{
    actions *action;

    action = malloc(sizeof(actions));
    action->total_actions = 0;
    action->rowcol = malloc(sizeof(int *) * 9);

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            if (board->boardarr[i][f] == ' ')
            {
                action->rowcol[action->total_actions] = malloc(sizeof(int) * 2);
                action->rowcol[action->total_actions][0] = i;
                action->rowcol[action->total_actions][1] = f;
                action->total_actions++;
            }
        }
    }
    
    return action;
}

int utility(Board *board)
{
    if (!terminal(board))
    {
        internalerror(1);
    }

    char winnerplayer = winner(board);
    
    if (winnerplayer == 'X')
    {
        return 1;
    }
 
    else if (winnerplayer == 'O')
    {
        return -1;
    }

    else
    {
        return 0;
    }
}

Board *result(Board *oldboard, int *action)
{
    Board *Newboard = newboard();

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            Newboard->boardarr[i][f] = oldboard->boardarr[i][f];
        }
    }
    Newboard->boardarr[action[0]][action[1]] = turn(oldboard);

    return Newboard;
}