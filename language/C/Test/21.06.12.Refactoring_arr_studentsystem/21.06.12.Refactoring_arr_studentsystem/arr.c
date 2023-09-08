/*review ver.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[10];
	int age, s_num, score;
}student;
/* 반복 코드 함수화 */
student* arrInput(student* swap, char* name, int age, int s_num, int score) {
	strcpy_s(swap->name, sizeof(name), name);
	swap->age = age;
	swap->s_num = s_num;
	swap->score = score;
	return swap;
}

/* 
	중복로직을 제거하여 createStudent로 통합.
*/
student* createStudent(student* arr,char* name, int age, int s_num, int score, int idx) {
	student* swap = (student*)malloc(sizeof(student)*(idx+1));
 
	for (int i = 0; i < idx; i++) {
		arrInput((swap+i), arr[i].name, arr[i].age, arr[i].s_num, arr[i].score);
	}
	arrInput((swap+idx), name, age, s_num, score);

	free(arr);

	return swap;
}

char grade(int score) {
	if (100 >= score && score > 89) return 'A';
	else if (score > 79) return 'B';
	else if (score > 69) return 'C';
	else if (score > 59) return 'D';
	else if (score > 49) return 'E';
	else if (score >= 0) return 'F';
	else return 'X';
}

/*
	개별 검색하는 함수.
	pk가 이름이므로 student* 를 이름으로 돌린 후 맞으면 그 student* 을 리턴.
*/
int searchIdxArr(student* arr, char* name, int idx) {
	
	int tagetIdx=0;
	for (int i = 0; i < idx; i++) {
		if (!strncmp(arr[i].name, name,sizeof(name))) {
			return tagetIdx;
		}
		tagetIdx++;
	}	
	return -1;
}

/*
	함수의 시그니처가 동일하여 구분하기 쉽도록 수정.
*/

void eachArrPrint(student each) {
	printf("이름 : %s, 나이 : %d, 학번 : %d, 점수 : %d, 학점 : %c\n", each.name, each.age, each.s_num, each.score, grade(each.score));
}

student* insertArr(student* arr, char* searchName, char* name, int age, int s_num, int score, int idx) {
	int targetIdx = searchIdxArr(arr, searchName, idx);
	arrInput((arr + targetIdx), name, age, s_num, score);
	return arr;
}

student* deleteArr(student* arr, char* name, int idx) {
	if (idx != 0) {
		student* swap = (student*)malloc(sizeof(student) * idx);

		int targetIdx = searchIdxArr(arr, name, idx);
		for (int i = 0; i < targetIdx; i++) {
			arrInput((swap + i), arr[i].name, arr[i].age, arr[i].s_num, arr[i].score);
		}

		for (int i = targetIdx; i < idx - 1; i++) {
			int nextIndex = i + 1;
			arrInput((swap + i), arr[nextIndex].name, arr[nextIndex].age, arr[nextIndex].s_num, arr[nextIndex].score);
		}
		free(arr);
		return swap;
	}
	else return NULL;
}

void writeArr(student* arr,int idx) {
	FILE* fp;
	if (0 == fopen_s(&fp, /* ??? */, "w+")) {
		for(int i = 0; i<idx;i++){
		fprintf(fp, "%s %d %d %d %c\n", arr[i].name, arr[i].age, arr[i].s_num, arr[i].score, grade(arr[i].score));
		}
	fclose(fp);
	}
}

student* readArr(student* arr,int *idx) {
	FILE* fp;
	char name[10];
	int age, s_num, score;
	if (0 == fopen_s(&fp, /* ??? */, "r")) { // fopen_s(파일포인터의 주소값,"저장경로","방식") 
		while (!feof(fp)){
			fscanf_s(fp, "%s %d %d %d %*c\n", &name,sizeof(name), &age, &s_num, &score);
			arr = createStudent(arr, name, age, s_num, score, *(idx));
			(*idx)++;
		}
	fclose(fp);
	}
	return arr;
}

int main() {
	student* arr = NULL;
	char name[10];
	int choice = 0, age = 0, s_num = 0, score = 0, idx = 0;
	enum { INPUT = 1, SEARCH, INSERT, DELETE, SAVE, OPEN, END, EACH = 1, ALL };

	while (1) {

		printf("\n====================================================\n");
		printf("1.입력, 2.검색 3.수정 4.삭제 5.저장 6.불러오기 7.종료\n");
		printf("======================================================\n\n");
		scanf_s("%d", &choice);
		
		switch (choice) {
			case INPUT: {
				printf("이름, 나이, 학번, 점수\n");
				scanf_s("%s %d %d %d", name,sizeof(name), &age, &s_num, &score);
				arr = createStudent(arr, name, age, s_num, score, idx);
				idx++;
				break;
			}
			case SEARCH: {
				printf("1. 개별조회 2. 전체조회\n\n");
				scanf_s("%d", &choice);
				switch (choice) {
					case EACH: {
						printf("조회할 이름을 입력해주세요.\n");
						scanf_s("%s", name, sizeof(name));
						if (searchIdxArr(arr, name, idx) >= 0) eachArrPrint(arr[searchIdxArr(arr, name, idx)]);
						else printf("조회할 값이 없습니다.\n");
						break; 
					}
					case ALL: {
//						searchAllArr(arr,idx);
						for (int i = 0; i < idx; i++) 	eachArrPrint(arr[i]);
						break;
					}
					default: printf("잘못누르셨습니다.\n\n");
				}
				break;
			}
			case INSERT: {
				char searchName[10];
				printf("변경할 이름을 적어주세요.\n");
				scanf_s("%s", searchName, sizeof(searchName));
				if (searchIdxArr(arr, searchName, idx) >= 0) {
					printf("변경할 이름, 나이, 학번, 점수를 적어주세요.\n");
					scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
					insertArr(arr, searchName, name, age, s_num, score, idx);
					break;
				}
				else printf("존재하지 않는 이름입니다.\n"); break;
			}
			case DELETE: {
				if (idx > 0) {
					printf("지울 이름을 입력해주세요.\n");
					scanf_s("%s", name, sizeof(name));
					if (searchIdxArr(arr, name, idx) >= 0) {
						arr = deleteArr(arr, name, idx);
						idx--;
						break;
					}
					else printf("존재하지 않는 이름입니다.\n"); break;
				}
				else {
					printf("저장된 값이 없습니다.\n");
					idx = 0; 
					break;
				}
			}
			case SAVE: {
				writeArr(arr,idx);
				break;
			}
			case OPEN: {
				arr = readArr(arr,&idx);
				break;
			}
			case END: {
				printf("프로그램을 종료합니다.");
				return 0;
			}
			default: printf("잘못누르셨습니다.\n");
		}
	}

	return 0;
}
