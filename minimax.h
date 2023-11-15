#include "basiclibraries.h"
#include "board.h"

#ifndef MINIMAX_H
#define MINIMAX_H

int *minimax(Board *board);
int find_max(Board *board);
int find_min(Board *board);

int *minimax(Board *board)
{
    int *act = malloc(sizeof(int) * 2);
    int ans;

    if (turn(board) == 'X')
    {
        ans = -2;
        actions *action = all_actions(board);

        for (int i = 0; i < action->total_actions; i++)
        {
            Board *resultboard = result(board, action->rowcol[i]);


            int tmp = find_min(resultboard);

            if (tmp > ans)
            {
                ans = tmp;
                act[0] = action->rowcol[i][0];
                act[1] = action->rowcol[i][1];
            }
            free2dchararr(resultboard->boardarr, 3);
            free(resultboard);
        }
        free2dintarr(action->rowcol, action->total_actions);
        free(action);
    }

    else if (turn(board) == 'O')
    {
        ans = 2;
        actions *action = all_actions(board);

        for (int i = 0; i < action->total_actions; i++)
        {
            Board *resultboard = result(board, action->rowcol[i]);


            int tmp = find_max(resultboard);

            if (tmp < ans)
            {
                ans = tmp;
                act[0] = action->rowcol[i][0];
                act[1] = action->rowcol[i][1];
            }

            free2dchararr(resultboard->boardarr, 3);
            free(resultboard);
        }
        free2dintarr(action->rowcol, action->total_actions);
        free(action);
    }

    return act;
}

int find_min(Board *board)
{
    if (terminal(board))
    {
        return utility(board);
    }

    actions *action = all_actions(board);
    int ans = 2;

    for (int i = 0; i < action->total_actions; i++)
    {
        Board *resultboard = result(board, action->rowcol[i]);


        int tmp = find_max(resultboard);

        if (tmp < ans)
        {
            ans = tmp;
        }

        free2dchararr(resultboard->boardarr, 3);
        free(resultboard);
    }

    free2dintarr(action->rowcol, action->total_actions);
    free(action);

    return ans;
}

int find_max(Board *board)
{
    if (terminal(board))
    {
        return utility(board);
    }

    actions *action = all_actions(board);
    int ans = -2;

    for (int i = 0; i < action->total_actions; i++)
    {
        Board *resultboard = result(board, action->rowcol[i]);


        int tmp = find_min(resultboard);

        if (tmp > ans)
        {
            ans = tmp;
        }

        free2dchararr(resultboard->boardarr, 3);
        free(resultboard);
    }
    free2dintarr(action->rowcol, action->total_actions);
    free(action);

    return ans;
}

#endif