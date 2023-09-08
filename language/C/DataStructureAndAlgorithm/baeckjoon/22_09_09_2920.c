/*
다장조는 c d e f g a b C, 총 8개 음으로 이루어져있다. 
이 문제에서 8개 음은 다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, ..., C를 8로 바꾼다.

1부터 8까지 차례대로 연주한다면 ascending, 
8부터 1까지 차례대로 연주한다면 descending, 
둘 다 아니라면 mixed 이다.

연주한 순서가 주어졌을 때, 이것이 ascending인지, 
descending인지, 아니면 mixed인지 판별하는 프로그램을 작성하시오.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
typedef enum bool
{
	TRUE = -1,
	FALSE = 0,
}bool;

typedef enum direction
{
	REVERSE,
	FORWARD,
}direction;

bool is_sort(int *arr, int size, direction direction)
{
	if (direction == FORWARD)
	{
		for (int i = 0, j = 1; i < size; j++, i++)
		{
			if (arr[i] != j)
				return FALSE;
		}
	}
	else
		for (int i = 0, j = 8; i < size; j--, i++)
		{
			if (arr[i] != j)
				return FALSE;
		}
	return TRUE;
}

int main()
{
    int c,d,e,f,g,a,b,C;

    scanf("%d %d %d %d %d %d %d %d", &c,&d,&e,&f,&g,&a,&b,&C);
    
	if ((c != 1 && c != 8))
	{
		write(1, "mixed",strlen("mixed"));
		return (0);
	}
	int arr[] = {c, d, e, f, g, a, b, C};

	if (is_sort(arr, 8, FORWARD))
		write(1, "ascending",strlen("ascending")); 
	else if (is_sort(arr, 8, REVERSE))
		write(1, "descending",strlen("descending"));
	else
		write(1, "mixed",strlen("mixed"));
	return (0);
}
