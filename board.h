#include "basiclibraries.h"

#ifndef BOARD_H
#define BOARD_H

typedef struct
{
    char **boardarr;
    bool status;
}
Board;

typedef struct 
{
    int total_actions;
    int **rowcol;
}
actions;


void print_board(Board *board);
char winner(Board *board);
bool terminal(Board *board);
void changeboard(Board *board, int row, int col, char turn);
char turn(Board *board);
int noofplaysof(Board *board, char player);
void print_winner(Board *board);
void internalerror(int i);
Board *result(Board *oldboard, int *action);
int utility(Board *board);
actions *all_actions(Board *board);
Board *newboard(void);

#endif