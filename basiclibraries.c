#include "basiclibraries.h"

// This function checks if a string is a valid int
bool check_int(char *numstr) {
    // Putting the length of the "numstr" in a variable
    int stringlen = strlen(numstr);

    // Checking if the string is an integer
    if (isdigit(numstr[0]) == 0 && numstr[0] != '-') {
        return false;
    }

    for (int i = 1; i < stringlen; i++) {
        if (isdigit(numstr[i]) == 0) {
            return false;
        }
    }

    // Then the string is valid int
    return true;
}

// This function helps in getting input of an integer
int get_int(char *txt) {
    // First the string which will first be used to take the number as a string
    char numstr[20];
    bool status;

    // Getting input of the int and checking if it a valid int
    do {
        printf("%s", txt); 
        scanf("%s", numstr);

        // Checking if it is a valid integer or not
        status = check_int(numstr);
        if (!status) {
            printf("\nNot an integer!!\n\n");
        }
    } while (!status);

    // Returning the int
    return atoi(numstr);
}

// Getting an int from a specific starting number
int get_intfromstart(char *txt, int start) {
    int num;
    char numstr[20];

    loop:
    printf("%s", txt);
    scanf("%s", numstr);

    if (check_int(numstr) == false) {
        printf("\nNot an integer!!\n\n");
        goto loop;
    }

    num = atoi(numstr);
    
    if (num < start) {
        printf("\nEnter a number greater than %i!!\n\n", start);
        goto loop;
    }

    return atoi(numstr);
}

// Getting an int from a specific starting number and an ending number
int get_intfromstarttoend(char *txt, int start, int end) {
    int num;
    char numstr[20];

    loop:
    printf("%s", txt);
    scanf("%s", numstr);

    if (check_int(numstr) == false) {
        printf("\nNot an integer!!\n\n");
        goto loop;
    }

    num = atoi(numstr);
    
    if (num < start || num > end) {
        printf("\nEnter a number greater than %i and less than %i!!\n\n", start, end);
        goto loop;
    }

    return atoi(numstr);
}

// Helps in getting input of a float
bool check_float(char *numstr) {
    int stringlen = strlen(numstr);
    uint16_t dotcount = 0;

    if (isdigit(numstr[0]) == 0 && numstr[0] != '-' && numstr[0] != '.') {
        return false;
    }

    if (numstr[0] == '.') {
        dotcount = 1;
    }

    for (int i = 1; i < stringlen; i++) {
        if (isdigit(numstr[i]) == 0 && (dotcount == 1 && numstr[i] == '.')) {
            return false;
        }

        else if (numstr[i] == '.') {
            dotcount = 1;
        }
    }

    // If program comes to this point then it is a float
    return true;
}

// This function helps in getting input of an float
float get_float(char *txt) 
{
    // First the string which will first be used to take the number as a string
    char numstr[20];

    // The goto type loop that goes on till user inputs an integer
    loop:
    printf("%s", txt); 
    scanf("%s", numstr);


    if (check_float(numstr) == false) {
        printf("\nNot a float!!\n\n");
        goto loop;
    }

    // Returning the float
    return atof(numstr);
}

// This helps in getting input of a string
char *get_string(char *txt, int len)
{
    char *str = calloc(sizeof(char), len + 1);

    printf("%s", txt);
    scanf("%[^\n]", str);
    str[strlen(str)] = '\0';

    // Returning the string
    return str;
}

// This helps in getting input of a char
char get_char(char *txt)
{
    char *str = calloc(sizeof(char), 3);

    // Using goto type loop for making sure user doesnt enter more than 1 character
    loop:
    printf("%s", txt);
    scanf("%s", str);

    if (str[0] == ' ')
    {
        goto loop;
    }

    // If user enter more than one character
    if (strlen(str) > 1) {
        printf("\nJust enter one character!!\n\n");
        goto loop;
    }

    // Returning the character
    char s = str[0];
    free(str);

    return s;
}

// This helps in printing an array
void print_arr(int arrlen, int *arr) {
    printf("[");
    for (int i = 0; i < arrlen; i++) {
        if (i != arrlen - 1 && i != 0) {
            printf(" %i,", arr[i]);
        }
        else if (i == 0) {
            printf("%i,", arr[i]);
        }

        else {
            printf(" %i", arr[i]);
        }
    }
    printf("]\n");
}

void internalerror(int i)
{
    printf("Internal Error...\n");
    exit(i);
}

void free2dintarr(int **arr, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        free(arr[i]);
    }

    free(arr);
}

void free2dchararr(char **arr, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        free(arr[i]);
    }

    free(arr);
}