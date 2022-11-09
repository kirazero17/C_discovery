#ifndef DYNASTRING_H
#define DYNASTRING_H

#include <stdlib.h>
#include <string.h>

struct dstrings {
    char* str;
};
typedef struct dstrings String;

String* NewString()
{
    String *s = malloc(sizeof(String));
    if (s == NULL)
        return NULL;
    s->str = NULL;
    return s;
}

String* SetStr(char* StringValue)
{
    String *dyns = NewString();
    dyns->str = StringValue;
    return dyns;
}

String* GetStr(int length)
{
    String *strborn = NewString();
    strborn->str = (char*)malloc(length * sizeof(char));
    if (strborn->str == NULL)
    {
        printf("Malloc failed ! Aborted !\n");
        return strborn;
    }
    //get input
    fgets(strborn->str, length, stdin);
    if (strborn->str[0] == '\n')
        strborn->str = " ";

    strtok(strborn->str, "\n");
    length = 0;
    //fine until here
    char *p = strborn->str;
    while (*p != NULL)
    {
        p++;
        length++;
    }
    //realloc the string and return it
    strborn->str = realloc(strborn->str, length * sizeof(char));
    return strborn;
}

void print(String dynamic_string)
{
    printf(dynamic_string.str);
}

void destroy(String** dynamic_string)
{
    free(*dynamic_string);
    *dynamic_string = NULL;
}

#endif // DYNASTRING_H
