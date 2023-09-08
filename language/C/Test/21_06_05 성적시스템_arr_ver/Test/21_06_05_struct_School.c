/*
성적 입력 프로그램 작성

구조체 작성
1-1. 학생

이름(unique), 나이, 학번

1-2. 성적
과목, 성적을 입력하면 학점출력(학점 A B C D F)

학생 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
성적 정보를 입력, 검색, 삭제, 수정 할 수 있어야 한다.
학생 검색시 학생의 성적이 조회 같이 조회 되어야 한다.

모든 기능은 아래의 인터페이스를 만족해야 한다.
5-1. 1)입력, 2)검색, 3)수정, 4)삭제 5)검색 6)종료

5-2. 입력, 검색, 수정, 삭제는 연속적으로 이루어 져야 한다.

즉, 프로그램 기능이 한번 진행한 이후 끝나는 것이 아니라 계속적으로 진행 되어야 한다.

제한시간 3시간
*/
#include "menu.h"
#include "struct.h"
#include "s_arrAdd.h"
#include "s_arrSearch.h"
#include "s_arrInsert.h"
#include "s_arrDelete.h"


int main() {
	student* s_arr=NULL;
	char name[10];
	int cnt=0;

	while (1) {
		printf("=====================================================================\n");
		printf("메뉴: 1)입력, 2)검색, 3)수정, 4)삭제  5) 전체성적조회 6)종료\n");
		printf("=====================================================================\n");
		switch (menu()-48) {
			case(1): {
				
				cnt++;
				printf_s("이름, 나이, 학번, 점수를 입력해 주세요\n");
				
				if (cnt == 1) s_arr = s_arrCreate(s_arr, cnt);
				else s_arr = s_arrAdd(s_arr, cnt);
/*
				if (flag == 0) first = createStudent(name, age, s_num, score);
				else newStudent(nextStudent(first), name, age, s_num, score);
				printf("%s %d %d %d\n", nextStudent(first)->name, nextStudent(first)->age, nextStudent(first)->s_num, nextStudent(first)->score);
				flag++;
*/
				break; 
			}
			case(2): {
				if (s_arr != NULL) {
						printf("검색할 이름을 입력해 주세요.\n");
						scanf_s("%s", name, sizeof(name));
					if (!s_search(name, s_arr, cnt)) {
						printf("값이 존재하지 않습니다.\n");
						break;
					}
					else {
						s_output(s_arr, s_search(name, s_arr, cnt));
					}
				}
				else {
					printf("데이터가 없습니다.\n 입력항목을 선택해 주세요.\n");
					continue;
				}
				break; 
			}
			case(3): {
				printf("수정할 이름을 입력해 주세요.\n");
				scanf_s("%s", name, sizeof(name));	
				if (!s_search(name, s_arr, cnt)) { 
					printf("이름이 없습니다.\n"); break; 
				}
				printf("새로운 이름, 나이, 학번, 성적을 입력해 주세요.\n");
				s_arr = s_insert(s_arr, s_search(name, s_arr, cnt),cnt);
				break;
			}
			case(4): {
				if (s_arr == NULL) {
					printf("값이 없습니다.\n");
					break;
				}
				printf("삭제할 이름을 입력해 주세요.\n");
				scanf_s("%s", name, sizeof(name));
				if (!s_search(name, s_arr, cnt)) {
					printf("이름이 없습니다.\n"); break;
				}
				s_arr = s_delete(s_arr, s_search(name, s_arr, cnt), cnt);
				cnt--;
				break;
			}
			case(5): {
				s_outputAll_grade(s_arr, cnt); 
				break;
			}
			case(6): {
				printf("프로그램을 종료합니다."); 
				free(s_arr);
				return 0; 
			}
			default:{ 
				printf("잘못 입력하셨습니다.\n"); 
				continue;
			}
		}
	}
	free(s_arr);
}
		
