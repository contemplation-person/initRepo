#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Student {
	char name[10];
	int age, s_num, score;
	struct Student* nextNode;
}st;

char grade(int score) {
	if (100 >= score && score > 89) return 'A';
	else if (score > 79) return 'B';
	else if (score > 69) return 'C';
	else if (score > 59) return 'D';
	else if (score > 49) return 'E';
	else if (score >= 0) return 'F';
	else return 'X';
}

void printAllNode(st* node) {
	if(node !=NULL){
		st* temp = node;
		while (temp) {
			printf("%s %d %d %d %c\n", temp->name, temp->age, temp->s_num, temp->score, grade(temp->score));
			temp = temp->nextNode;
		}
	}
	else {
		printf("값이 없습니다.\n");
	}
}

void printStudent(st* node) {
		st* temp = node;
		printf("%s %d %d %d %c\n", temp->name, temp->age, temp->s_num, temp->score, grade(temp->score));
}

st* inputStudent(st* node, char* name, int age, int s_num, int score, st* nextNode) {
	strcpy_s(node->name, sizeof(name), name);
	node->age = age;
	node->s_num = s_num;
	node->score = score;
	node->nextNode = nextNode;
	return node;
}

st* createStudent(char*name, int age, int s_num, int score) {
	st* newNode = (st*)malloc(sizeof(st));
	newNode = inputStudent(newNode, name, age, s_num, score, NULL);
	printStudent(newNode);
	return newNode;
}

st* addStudent(st* node, char* name, int age, int s_num, int score) {
	st* temp = node;
	st* addStudent = (st*)malloc(sizeof(st));
	
	while (temp->nextNode)	temp = temp->nextNode;

	addStudent = inputStudent(addStudent, name, age, s_num, score, NULL);
	
	temp->nextNode = addStudent;
	
	printStudent(addStudent);
	return addStudent;
}

st* searchStudent(st* node, char* name) {
	st* temp = node;
	while (strcmp(temp->name, name)) {
		temp = temp->nextNode;
		if (temp->name == NULL) return NULL;
	}
	return temp;	
}

st* editStudent( st* searchStudent, char *name, int age, int s_num, int score) {
	return inputStudent(searchStudent,name,age,s_num,score,searchStudent->nextNode);
}

st* insertStudent(st* start, char* searchName, char* name, int age, int s_num, int score) {
	st* after, *pre;
	after = pre = start;
	while (strcmp(pre->name, searchName)) {
		after = pre;
		pre = pre->nextNode;
	}
	if (pre == start) {
		start = createStudent(name, age, s_num, score);
		start->nextNode = after;
	}
	else {
		after->nextNode =createStudent(name, age, s_num, score);
		after->nextNode->nextNode = pre;
	}
	return start;
}

st* deleteStudent(st* start,char* name) {
	if (searchStudent(start, name) == start) {
		st* temp = start->nextNode;
		free(start);
		return temp;
	}
	else {
		st* before = start;
		st* pre = before;
		while (strcmp(pre->name, name)) {
			before = pre;
			pre = pre->nextNode;
		}
		before->nextNode = pre->nextNode;
		free(pre);
		return start;
	}
}

void saveStudent(st* node) {
	FILE* fp;
	st* temp=node;
	if (0 == fopen_s(&fp, "a.txt", "w+")) {
		while(temp){
			fprintf(fp, "%s %d %d %d %c\n", temp->name, temp->age, temp->s_num, temp->score, grade(temp->score));
			temp = temp->nextNode;
		}
	fclose(fp);
	}
}

st* openStudent(st* node) {
	FILE* fp;
	char name[10];
	int age, s_num, score,check=1;
	if (0 == fopen_s(&fp, "a.txt", "r")) {
		while (1) {
			fscanf_s(fp, "%s %d %d %d %*c", name, sizeof(name), &age, &s_num, &score);
			if (feof(fp))break; 
			//feof의 오류가 있어서 오랜 시간이 걸렸다. feof는 파일을 끝까지 읽고 한 번 더 출력을 하여 오류가 나오면 값을 도출하는 함수로 파일 끝 +1을 입력한다.
			if (node != NULL) {
				addStudent(node, name, age, s_num, score);
			}
			else {
				node = createStudent(name, age, s_num, score);
			}
		}
		fclose(fp);
	}
	return node;
}

int main(int argc,char * argv[]) {
	st* node= NULL;
	char name[10], searchName[10];
	int choice,age,s_num, score;
	enum { _INPUT = 1, _SEARCH, _EDIT, _INSERT, _DELETE, _SAVE, _OPEN, _END, _EACH = 1, _ALL = 2 };
	while (1) {
		printf("\n==============================================================\n");
		printf("1.입력, 2.검색 3.수정 4.삽입 5.삭제 6.저장 7.불러오기 8.종료\n");
		printf("==============================================================\n\n");
		scanf_s("%d", &choice);
	
		switch (choice) {
			case _INPUT: {
				printf("이름, 나이, 학번, 점수를 입력해주세요.\n");
				scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
				if (node != NULL) {
					addStudent(node, name, age, s_num, score);
				}
				else {
					node = createStudent(name, age, s_num, score);
				}
				break;
			}
			case _SEARCH: {
				printf("1. 개별조회 2. 전체조회\n\n");
				scanf_s("%d", &choice);
				switch (choice) {
					case _EACH: {
						printf("조회할 이름을 입력해주세요.\n");
						scanf_s("%s", name, sizeof(name));
						if (node != NULL) {
							if (!searchStudent(node, name)) {
								printf("찾는 값이 없습니다.\n"); 
							}
							else {
								printStudent(searchStudent(node, name));
							}
						}
						else {
							printf("찾는 값이 없습니다.");
						}
						break;
					}
					case _ALL: {
						if(node != NULL){
							printAllNode(node);
							break;
						}
						else {
							printf("찾는 값이 없습니다.");
							break;
						}
					}
					default: {
						printf("잘못누르셨습니다.\n\n"); break; 
					}
				}
				break;
			}
			case _EDIT: {
				if(node !=NULL){
					printf("변경할 이름을 적어주세요.\n");
					scanf_s("%s", searchName, sizeof(searchName));
					if (!searchStudent(node, searchName)	){
						printf("변경할 이름, 나이, 학번, 점수를 적어주세요.\n");
						scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
						editStudent(searchStudent(node, searchName), name, age, s_num, score);
						break;
					}
					else printf("찾는 값이 없습니다."); break;
				}
				else {
					printf("값을 입력해주세요.");
					break;
				}
			}
			case _INSERT: {
				if(node != NULL){
					printf("어느 이름 앞에 삽입하고 싶습니까?\n");
					scanf_s("%s", searchName, sizeof(searchName));
					if (searchStudent(node,searchName)!=NULL) {
						printf("삽입할 이름, 나이, 학번, 점수를 적어주세요.\n");
						scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
						node = insertStudent(node, searchName, name, age, s_num, score);
					}
					else {
						printf("찾는 정보가 없습니다. 마지막에 정보를 입력합니다.\n");
						printf("삽입할 이름, 나이, 학번, 점수를 적어주세요.\n");
						scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
						addStudent(node, name, age, s_num, score);
					}
				}
				else {
					printf("작성 값이 없습니다. 새로운 정보를 입력합니다.\n\n");
					printf("이름, 나이, 학번, 점수\n");
					scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
					node = createStudent(name, age, s_num, score);
				}
				break;
			}
			case _DELETE: {
				if (node != NULL) {
					printf("지울 이름을 입력해주세요.\n");
					scanf_s("%s", name, sizeof(name));
					if (searchStudent(node, name)!= NULL)	node = deleteStudent(node, name);
					else printf("찾는 이름이 없습니다.\n"); 
					break;
				}
				else {
					printf("입력된 값이 없습니다.\n");
					break;
				}
			}
			case _SAVE: {
				saveStudent(node);
				break;
			}
			case _OPEN: {
				node = openStudent(node);
				break;
			}
			case _END: {
				printf("프로그램을 종료합니다.");
				return 0;
			}
			default: printf("잘못누르셨습니다.\n");
		}
	}
return 0;
}
