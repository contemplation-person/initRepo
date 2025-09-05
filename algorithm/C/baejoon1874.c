#include <stdbool.h>
#include <stdio.h>
/*
문제
        1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
        이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
        임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지,
        있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
        이를 계산하는 프로그램을 작성하라.

입력
        첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다.
        둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
        물론 같은 정수가 두 번 나오는 일은 없다.

출력
        입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다.
        push연산은 +로, pop 연산은 -로 표현하도록 한다.
        불가능한 경우 NO를 출력한다.
*/

// make stack
static int stack[100000];
static int stack_index;
static int n;
static int sequence[100000];
static int sequence_index;
static int target_num;
static char str[1000000];
static int str_index;

int peek() {
    if (stack_index == 0) return -1;
    return stack[stack_index - 1];
}

int pop() {
    int ret = 0;
    if (peek() == -1) return ret;
    ret = stack[stack_index - 1];
    stack_index--;
    str_index += sprintf(str + str_index, "-\n");
    return ret;
}

bool push(int num) {
    if (num > peek()) {
        stack[stack_index] = num;
        stack_index++;
        str_index += sprintf(str + str_index, "+\n");
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", sequence + i);
    }

    target_num = 1;
    while (sequence_index < n) {
        if (peek() == sequence[sequence_index]) {
            pop();
            sequence_index++;
            continue;
        }
        if (target_num > sequence[sequence_index]) {
            goto error;
        }
        while (target_num <= sequence[sequence_index]) {
            push(target_num);
            target_num++;
        }
        continue;
    }

    printf("%s", str);
    return 0;

error:
    printf("NO\n");
    return 0;
}
