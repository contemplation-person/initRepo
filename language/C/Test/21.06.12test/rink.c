#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student {
	char name[10];
	int age, s_num, score;
	struct Student* nextNode;
}st;

char grade(int num) {
	if (100 >= num && num > 89) return 'A';
	else if(num > 79) return 'B';
	else if(num > 69) return 'C';
	else if(num > 59) return 'D';
	else if(num > 49) return 'E';
	else if(num > 49&&num>=0) return 'F';
	else return 'X';
	
}

st* Create(char* name, int age, int s_num, int score) {
	st* create = (st*)malloc(sizeof(st));
	strcpy_s(create->name, sizeof(name),name);
	create->age = age;
	create->s_num = s_num;
	create->score = score;
	create->nextNode = NULL;
	
	return create;
}

st* add(st* first, char* name, int age, int s_num, int score) {
	st* newNode = (st*)malloc(sizeof(st));
	strcpy_s(newNode->name, sizeof(name), name);
	newNode->age = age;
	newNode->s_num = s_num;
	newNode->score = score;
	newNode->nextNode = NULL;
	first->nextNode = newNode;

	return newNode;
}

st* search_(st* node, char * s_name) {
	st* temp = node;
	//printf("node: %d", node->age);
	while (!strcmp(s_name, temp->name)){
		temp = temp->nextNode;
	} 

	return temp;
}

st* insert_(st* node, char* searchname, char*name,int age,int s_num,int score ) {
	st* temp = node;
	temp = search_(temp, searchname);
	strcpy_s(temp->name, sizeof(name), name);
	temp->age = age;
	temp->s_num = s_num;
	temp->score = score;

	return temp;

}
st* del(st* node,char *name) {
	st* atemp = node;
	st* pre = node;
	st* btemp = node->nextNode;
	while (!strcmp(name, node->name)) {
		atemp = pre;
		pre = btemp;
		btemp = pre->nextNode;
	}
	printf("%s %d %d %d %c", pre->name, pre->age, pre->s_num, pre->score, grade(pre->score));
	free(pre);
	pre = NULL;
	atemp->nextNode = btemp;
	return pre;
}

void main() {
	st* node = NULL;
	while (1) {
		char searc[10];	
		char name[10];
		int choice,age, s_num, score;
		enum{input=1, search,insert,dele};
		printf("\n====================================\n");
		printf("1. 입력 2.검색 3. 수정 4.삭제\n");
		printf("====================================\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case input: {

			printf("이름, 나이, 학번, 점수를 입력해주세요\n");
			scanf_s("%s %d %d %d", name,sizeof(name), &age, &s_num, &score);
			if (node == NULL) node = Create(name, age, s_num, score);
			else add(node,name, age, s_num, score);	
			//printf("Node: %d\n", node->age);
			break;
		}
		case search: {
			st* temp = NULL;
			printf("찾을 이름을 입력해주세요.\n");
			scanf_s("%s", searc, sizeof(searc));
			temp = search_(node, searc);
			printf("%s %d %d %d %c", temp->name, temp->age, temp->s_num, temp->score, grade(temp->score));
			
			break;
		}
		case insert: {
			printf("찾을 이름을 입력해주세요.\n ");
			scanf_s("%s", searc, sizeof(searc));
			printf("%s", searc);
			printf("이름, 나이, 학번, 점수를 입력해주세요\n");
			scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
			insert_(node, searc, name, age, s_num, score);
			break;
		}
		case dele: {
			printf("찾을 이름을 입력해주세요.\n ");
			scanf_s("%s", name, sizeof(name));
			del(node, name);
			break;
		}
		default:
			printf("잘못입력했습니다.\n");
		}
	}
}