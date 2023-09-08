#include "grade.h"
#include "menu.h"
#include "struct.h"
#include "node.h"
#include "searchNode.h"
#include "insertNode.h"
#include "deleteNode.h"
enum { input=1, search, insert, del, searchAll, read, end };

char name[10];
int age, s_num, score;
student* header=NULL;
student* node;

int main() {
	int choice;
	while (1) {
		printf("\n========================================================================\n");
		printf("|1. 입력 | 2. 검색 | 3. 삽입 | 4. 삭제 | 5. 전체조회 | 6. 저장 |7. 종료|\n");
		printf("========================================================================\n\n");
		scanf_s("%d", &choice);

		switch (choice) {
			case(input): {
				printf("이름, 나이, 학번, 성적을 입력해주세요.\n");
				scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
				
				if (header==NULL) header = node = CreateNode(name, age, s_num, score);
				else node = addNode(node, name, age, s_num, score);
				break;
			}
			case (search):{
				if (header != NULL) {
					printf("찾을 이름을 입력해주세요.\n");
					scanf_s("%s", name, sizeof(name));
					searchNode(header, name);
					break;
				}else{
					printf("값이 없습니다.\n"); 
					break;
				}
			}
			case (insert): {
				printf("수정 할 이름을 입력해주세요.\n");
				scanf_s("%s", name, sizeof(name));
				printf("수정 할 이름, 나이, 학번, 성적을 입력해주세요.\n");
				scanf_s("%s %d %d %d", name, sizeof(name), &age, &s_num, &score);
				insertNode(header, name, age, s_num, score);
				break;
			}
			case (del): {
				printf("삭제 할 이름을 입력해주세요.\n");
				scanf_s("%s", name, sizeof(name));
				deleteNode(header, name);
				break;
			}
			case(searchAll): {
				nodeAllPrint(header);
				break;
			}
			case(read): {

				break; 
			}
			case (end): return 1;  break;
			default: printf("잘못입력하셨습니다.\n다시 입력해주세요\n"); break;
		}
	





	}
return 0;
}
