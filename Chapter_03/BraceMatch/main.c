#include <stdio.h>
#include <string.h>
#include "stack.h"

int is_left(char c)
{
    if (c == '[' || c == '(' || c == '{')
        return 1;
    return 0;
}

int is_right(char c)
{
    if (c == ']' || c == ')' || c == '}')
        return 1;
    return 0;
}

int is_match(char l, int r)
{
    if ((l == '[' && r == ']') ||
        (l == '{' && r == '}') ||
        (l == '(' && r == ')'))
        return 1;
    return 0;
}

int test(Stack stk, char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (is_left(str[i]))
        {
            Push(str[i], stk);
        }

        else if (is_right(str[i]))
        {
            if (!is_match(Pop(stk), str[i]))
            {
                return 0;
            }
        }
    }
    return IsEmpty(stk);
}

int main()
{
    Stack stk = NULL;
    stk = InitStack(stk);
    char *str = "{}[({}[])]()";
    if (test(stk, str))
    {
        printf("Match\n");
    }

    else
    {
        printf("Do not Match\n");
    }
}
