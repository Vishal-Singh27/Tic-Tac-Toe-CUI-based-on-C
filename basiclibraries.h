#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#ifndef BASICLIBRARIES_H
#define BASICLIBRARIES_H

// Declaring the functions first
bool check_int(char *numstr);
int get_int(char* txt);
int get_intfromstart(char *txt, int start);
int get_intfromstarttoend(char *txt, int start, int end);
bool check_float(char *numstr);
float get_float(char *txt);
char *get_string(char *txt, int len);
char get_char(char *txt);
void print_arr(int arrlen, int *arr);
void internalerror(int i);
void free2dchararr(char **arr, int limit);
void free2dintarr(int **arr, int limit);

// Declaring a string type
typedef char * String;

#endif