#ifndef DYNASTRING_H
#define DYNASTRING_H

#include <stdlib.h>
#include <string.h>

struct dstrings {
    char* str;
};
typedef struct dstrings String;

String GetStr(String dynammic_string, int length)
{
    dynammic_string.str = (char*)malloc(length * sizeof(char));
    if (dynammic_string.str == NULL)
    {
        printf("Malloc failed ! Aborted !\n");
        return dynammic_string;
    }
    //get input
    fgets(dynammic_string.str, length, stdin);
    if (dynammic_string.str[0] == '\n')
        dynammic_string.str = " ";

    strtok(dynammic_string.str, "\n");
    length = 0;
    //fine until here
    char *p = dynammic_string.str;
    while (*p != NULL)
    {
        p++;
        length++;
    }
    //realloc the string and return it
    dynammic_string.str = realloc(dynammic_string.str, length * sizeof(char));
    return dynammic_string;
}

void print(String dynammic_string)
{
    printf(dynammic_string.str);
}

void destroy(String dynammic_string)
{
    free(dynammic_string.str);
}

#endif // DYNASTRING_H
