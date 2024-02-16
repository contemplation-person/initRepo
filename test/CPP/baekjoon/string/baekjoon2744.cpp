// #include <cstring>
// #include <cstdio>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char str[101];
    int i = 0;
    memset(str, 0, 101);
    scanf("%s", str);
    while (str[i])
    {
        printf("%c", str[i] >= 'a' ? (str[i] -= 32) : (str[i] += 32));
        i++;
    }
}