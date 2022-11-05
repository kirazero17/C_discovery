#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

//int to bool
const char* toBool(int a)
{
    if (a == 0)
        return "False";
    if (a == 1)
        return "True";
    return "Invalid Boolean";
}

//2nd degree equation with float
float ptb2 (float a, float b, float c)
{
    float dlt = b*b - 4*a*c;
    if (dlt < 0)
    {
        printf("No solution !/n");
        return -1;
    }
    if (dlt == 0)
    {
        float x = -b / 2*a;
        printf("A double solution: %f/n", x);
        return 0;
    }
    float x1 = (-b + sqrt(dlt)) / 2*a;
    float x2 = (-b - sqrt(dlt)) / 2*a;
    printf("Two solutions: %f and %f\n", x1, x2);
    return 1;
}

//finding factors with loops and array
void factor (int n)
{
    int i = 2;
    int c = 0;
    int arr[100];
    while (n > 1)
    {
        if (n%i == 0)
        {
            n /= i;
            arr[c++] = i;
        }
        else {
            i++;
        }
    }
    if (c == 0) {
        arr[c++] = n;
    }
    for (i = 0; i < c-1; i++)
    {
        printf("%d x ", arr[i]);
    }
    printf("%d\n", arr[c-1]);
}

//summing with pointers
int sumptr(int a, int b)
{
    int *p1 = &a;
    int *p2 = &b;
    int s = *p1 + *p2;
    p1 = NULL;
    p2 = NULL;
    return s;
}

// print values and pointers
void ptrnrfc()
{
    int c = 3;
    int *p = &c;
    printf("%d  %p  %d\n", c, p, p);
    *p = NULL;
}

//swapping procedure with pointer
void swapptr(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//array sum with pointer
int arrsum(int arr[], int sz)
{
    int *ptr;
    int sum = 0;
    ptr = arr;
    while (ptr < arr + sz)
    {
        sum += *ptr;
        ptr++;
    }
    ptr = NULL;
    return sum;
}

void notmain1()
{
    printf("Hello world!\n");
    system("PAUSE");
    int a = 0;
    printf("%d to Boolean: %s\n", a, toBool(a));
    system("PAUSE");
    printf("\nEquation result:\t");
    printf("Equation return: %f  \n", ptb2(1, 3, 2));
    printf("Elements of 1000: ");
    factor(1000);
    printf("\n\n");
    ptrnrfc();
    printf("%d\n", sumptr(9, 2));
    int c = 6, b = 7;
    swapptr(&c, &b);
    system("PAUSE");
    printf("\n%d\t%d\n", c, b);
}

void notmain2()
{
    int arr[5] = {1, 2, 3, 4, 5};
    printf("%d", arrsum(arr, 5));
}

//Dynamically allocated string
int notmain3()
{
    char *str = NULL;
    int l = 0;
    printf("Enter the length of your string: ");
    scanf("%d", &l);
    (void)getchar();

    str = (char*)malloc(l * sizeof(char));
    if (str == NULL)
    {
        printf("Malloc failed ! Aborted !\n");
        return -1;
    }
    printf("Enter the string here: ");
    fgets(str, l, stdin);
    strtok(str, "\n");
    //fine until here
    char *p = str;
    l = 0;
    while (*p != NULL)
    {
        p++;
        l++;
    }
    //no need to free p, cuz it's null already
    str = realloc(str, l * sizeof(char));
    printf(str);
    free(str);
    return 0;
}

int main()
{
    notmain1();
    notmain2();
    notmain3();
    printf("\n");
    system("PAUSE");
    return 0;
}
