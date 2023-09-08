#define _CRT_SECURE_NO_WARNINGS
/*
	알파벳 소문자로만 이루어진 단어 S가 주어진다. 
	각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 
	포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

	첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

	각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
	만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.

	ex) baekjoon
	a b  c  d e  f  g  h  i j k  l  m n o  p  q  r  s  t  u  v  w  x  y  z
	1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

	단 노드를 사용해 볼 것.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Alphabat {
	char alphabat_name;
	int cnt;	
	struct Alphabat* nextNode; //  노드를 선언할 땐 풀 네임을 써줘야 한다.
} alphabat ;

alphabat* CreateAlpha() {
	alphabat* a = (alphabat*)malloc(sizeof(alphabat));
	a->alphabat_name = 'a';
	a->cnt = -1;
	a->nextNode = NULL;

	return a;
}

alphabat* addAlpha(alphabat* add) {
	alphabat* a = (alphabat*)calloc(1,sizeof(alphabat));
	alphabat* temp = add;

	while (temp->nextNode) {
		temp = temp->nextNode;
	}
	a->alphabat_name = (temp->alphabat_name)+1;
	a->cnt = temp->cnt;
	a->nextNode = temp->nextNode;
	temp->nextNode = a;
	
	return temp;
}

void NodePrint(alphabat* node) {
	alphabat* temp = node;
	do {
		//printf("%d " ,temp->cnt);
		printf("%c:%d " ,temp->alphabat_name,temp->cnt);
		temp = temp->nextNode;
	} while (temp);

}


void cntAlpha(alphabat * node, char * word, int size) {
	alphabat* temp = node;
	for (int i = 0; i < size; i++) {
		temp = node;
		while (temp->alphabat_name != *(word + i)) {
			temp = temp->nextNode;
		}
		if (temp->cnt == -1) temp->cnt = i;
	}
}

int main() {
	alphabat* node;
	char word[100];
	int size=0;
	scanf("%s", word);
	
	while (word[size]) {
		size++;
	}

	node = CreateAlpha();             //header 노드 코드
	
	for (int i = 0; i < 25; i++) {    // node 생성 코드
		addAlpha(node);
	}

	cntAlpha(node, word,size);

	NodePrint(node); //노드 출력 코드;

	return 0;
}
