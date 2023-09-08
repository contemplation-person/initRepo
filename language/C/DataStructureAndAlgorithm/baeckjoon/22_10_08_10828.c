#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* 
     문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. error -1
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. error -1

	입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

*/

typedef struct node
{
	int	data;
	struct node *next;
}t_node;

typedef struct stack
{
	int counting_node;
	t_node *node;
}t_stack;

// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
int	is_empty(t_stack stack)
{
	return (stack.counting_node == 0);
}

// size: 스택에 들어있는 정수의 개수를 출력한다.
int cnt_size(t_stack stack)
{
	return (stack.counting_node);
}

// top: 스택의 가장 위에 있는 정수를 출력한다. error -1
int peek_top(t_stack stack)
{
	if (is_empty(stack)) return (-1);
	else return stack.node->data;
}

t_node	*new_node(int data)
{
	t_node *node;
	if(node = malloc(sizeof(t_node)))
		exit(-1);
	node->data = data;
	node->next = NULL;
	return (node);
}

// push X: 정수 X를 스택에 넣는 연산이다.
int	push(t_stack *stack, int data)
{
	t_node *node = stack->node;
	t_node *front_node = new_node(data);

	stack->node = front_node;
	front_node->next = node;
	stack->counting_node++;	
	return (data);
}

// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. error -1
int	pop(t_stack *stack)
{
	t_node *front_node;
	int	ret;
	t_node *new_front_node;

	if (stack->counting_node > 0)
	{
		t_node *front_node = stack->node;
		int	ret = front_node->data;
		t_node *new_front_node = front_node->next;
	}
	else
		return (-1);
	stack->node = new_front_node;
	(stack->counting_node)--;
	free(front_node);
	return (ret);
}

int main (int argc, char **argv)
{
	t_stack stack;
	int		cnt = argc - 1;

	while(*(++argv))
	{
		switch (1)
		{
		case !strncmp(*argv, "push", 4):
			
			break;
		
		default:
			break;
		}

		printf("%s\n", *argv);
		printf("%d\n",strncmp(*argv, "pop", 3));
		if (!strncmp(*argv, "push", 4))
			printf("%d\n",push(&stack, atoi(strdup((*argv) + 5))));
		else if (!strncmp(*argv, "pop", 3))
			printf("%d\n", pop(&stack));
		else if (!strncmp(*argv, "size", 4))
			printf("%d\n", cnt_size(stack));
		else if (!strncmp(*argv, "empty", 5))
			printf("%d\n", is_empty(stack));
		else if (!strncmp(*argv, "top", 3))
			printf("%d\n", peek_top(stack));
	}
	return (0);	
}
