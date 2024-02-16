#include <cstdio>
#include <cstring>

int main()
{
    char str[1001];
    int cnt;

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", str);
        printf("%c%c\n", str[0], str[strlen(str) - 1]);
    }
}