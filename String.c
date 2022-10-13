#include "String.h"
#include <stdio.h>
void copy_string(char*name, char*newName, int MaxSize)
{
    int i;
    for(i = 0; (name[i]!= 0 && i<MaxSize-1); i++)
    {
        newName[i] = name[i];
    }
    newName[i] = 0;
}

int String_Compare(char*str1,char*str2)
{
    int i;
    for(i=0; str1[i] || str2[i]; i++)
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1;
}

void scan_string(char *str, int MaxSize)
{
    //printf("Maximum Size for string: %d\n", MaxSize-1);

    int i;
    scanf(" %c", &str[i]);
    for(i = 0;(str[i]!='\n' && i<MaxSize-1);)
    {
        i++;
        scanf("%c", &str[i]);

    }

    str[i] = 0;
}

int string_length(char *str)
{
    int i = 0;
    for(i = 0; str[i]; i++);
    return i;
}

int string_compareNotCaseSensetive(char *str1, char *str2)
{
    int i = 0;


    for(i = 0; (str1[i]!=0 || str2[i] != 0); i++)
    {
        if((str1[i] == str2[i]) || (str1[i] == str2[i] + 'A' - 'a')  || (str1[i] == str2[i] - 'A' + 'a'))
        {

        }
        else
        {
            return 0;
        }
    }

    return 1;

}
