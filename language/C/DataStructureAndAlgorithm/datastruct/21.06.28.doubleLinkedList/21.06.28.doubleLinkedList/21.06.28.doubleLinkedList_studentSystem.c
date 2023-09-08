#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct st {
	struct st* before;
	char name[10];
	int age;
	int s_num;
	int score;
	struct st* after;
}st;

st* inputSt(st* node, char* name, int age, int s_num, int score) {
		strcpy_s(node->name, sizeof(name), name);
		node->age = age;
		node->s_num = s_num;
		node->score = score;
		return node;
}

st* newSt(st* node, char* name, int age, int s_num, int score ) {
	if (node != NULL) {
		st* temp = (st*)malloc(sizeof(st));
		st* temp2 = node;
		while (temp2->after != node) temp2 = temp2->after;
		inputSt(temp, name, age, s_num, score);
		temp2->after = temp;
		temp->before = temp2;
		temp->after = node;
		node->before = temp;	
	}
	else {
		node = (st*)malloc(sizeof(st));
		inputSt(node, name, age, s_num, score);
		node->before = node;
		node->after = node;
	}
	return node;
}
char gradeSt(int score) {
	if (100 >= score && score >= 90) {
		return 'A';
	}else if (score >= 80) {
		return 'B';
	}else if (score >= 70) {
		return 'C';
	}else if (score >= 60) {
		return 'D';
	}else if (score >= 50) {
		return 'E';
	}else if (score >= 40) {
		return 'F';
	}
	else return 'X';
}
void printSt(st* node) {
	if (node != NULL) {
		printf("이름:%s, 나이:%d, 학번:%d, 점수:%d, 학점:%c\n", node->name, node->age, node->s_num, node->score, gradeSt(node->score));
	}
	else printf("이름이 없습니다.\n"); 
}

st* searchSt(st* node,char* name) {
		st* temp = node;
		while (strcmp(temp->name, name)) {
			temp = temp->after;
			if (node == temp) return NULL;
		}
		return temp;
}

st* deleteSt(st*node) {
	if (node->after == node) { 
		free(node); 
		return NULL; 
	}
	else if (node != NULL) {
		st* temp = node;
		temp->before->after = node->after;
		temp->after->before = node->before;
		node = node->after;
		free(temp);
		temp = NULL;
	}
	else printf("삭제할 이름이 없습니다.\n"); 
	return node;
}

void writeSt(st* node) {
	FILE* fp;
	st* temp = node;
	if (0 == fopen_s(&fp,"student.txt", "w+")) {
		do {
			fprintf(fp, ("%s %d %d %d %c\n"), temp->name, temp->age, temp->s_num, temp->score, gradeSt(temp->score));
			temp = temp->after;
		} while (temp != node);
		fclose(fp);
	}
}

st* readSt(st* node) {
	FILE* fp;
	char name[10];
	int age, s_num, score;
	if (0 == fopen_s(&fp, "student.txt", "r")) {
		while (1) {
			fscanf_s(fp, "%s %d %d %d %*c", name, sizeof(name), &age, &s_num, &score);
			if (feof(fp)) break;
			node = newSt(node, name, age, s_num, score);
		}
		fclose(fp);
	}
	return node;
}

int main() {
	enum{INPUTST=1,PRINTST,EDITST,INSERTST,DELETEST,WRITE,READ,END,SEARCHST = 1,SEARCHALL	};
	st* node=NULL;
	char name[10];
	int menu,age,s_num,score;
	
	while (1) {
		printf("\n=====================================================================\n");
		printf("1.입력 2.조회 3.편집 4.삽입 5.삭제 6.저장 7.열기 8.종료\n");
		printf("=====================================================================\n");
		scanf_s("%d", &menu);
		switch (menu) {
			case INPUTST: {
				printf("이름, 나이, 학번, 점수를 입력해주세요.\n");
				scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
				node = newSt(node, name, age, s_num, score);
				break; 
			}
			case PRINTST: {
				if (node != NULL) {
					printf("1. 개별 2. 전체\n");
					scanf_s("%d", &menu);
					switch (menu) {
						case SEARCHST: {
							printf("출력할 이름을 입력해주세요.\n");
							scanf_s("%s", name, sizeof(name));
							printSt(searchSt(node, name));
							break;
						}
						case SEARCHALL: {
							st* temp = node;
							do {
								//								printf("temp 순환: %p\n", temp);
								printSt(temp);
								temp = temp->after;
								/*
																printf("node : %p temp : %p temp->after : %p\n", node, temp, temp->after);
																getchar();
								*/
							} while (temp != node);
						break;
						}
						default:printf("잘못입력했습니다.\n"); break;
					}
				}
				else  printf("정보를 입력해주세요.\n ");
				break;
			}
			case EDITST: {
				if (node != NULL) {
					printf("수정할 이름을 적어주세요.\n");
					char editName[10];
					scanf_s("%s", editName, sizeof(editName));
					if (searchSt(node, editName) != NULL) {
						printf("이름, 나이, 학번, 점수를 입력해주세요.\n");
						scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
						inputSt(searchSt(node, editName), name, age, s_num, score);
					}
					else printf("찾는 값이 없습니다.");
				}
				else printf("정보를 입력해주세요.\n");
				break; 
			}
			case INSERTST: {
				if (node != NULL) {
					printf("어느 이름뒤에 삽입하고 싶은지 적어주세요.\n");
					char insertName[10];
					scanf_s("%s", insertName, sizeof(insertName));
					if (searchSt(node, insertName) != NULL) {
						printf("이름, 나이, 학번, 점수를 입력해주세요.\n");
						scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
						newSt(searchSt(node, insertName), name, age, s_num, score);
					}
					else printf("삽입할 이름이 없습니다.\n");
				}
				else printf("정보를 입력해주세요.\n");
				break;
			}
			case DELETEST: {
				printf("삭제할 이름을 알려주세요.\n");
				char deleteName[10];
				scanf_s("%s", deleteName, sizeof(deleteName));
				node = deleteSt(searchSt(node, deleteName));
				break;
			}
			case WRITE: {
				if (node != NULL) {
					writeSt(node);
				}
				else printf("저장할 값이 없습니다.\n");
				break;
			}
			case READ: {
				node = readSt(node);
				break;
			}
			case END: return 0;	break; 
			default: printf("잘못입력하셨습니다."); break;
		}		
	}
	return 0;
}