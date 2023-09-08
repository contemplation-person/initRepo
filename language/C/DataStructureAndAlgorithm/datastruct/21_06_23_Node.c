#include "21_06_23_Node.h"

void main() {
	linkedList_h* L;
	L = createLinkedList_h();
	
	printf("(1) 공백 리스트 생성하기\n");
	printList(L); getchar();

	printf("(2) 리스트에 [수] 노드 삽입하기!\n");
	insertFirstNode(L, "수");
	printList(L); getchar();

	printf("(3) 리스트 마지막에 [금] 삽입하기\n");
	insertLastNode(L, "금");
	printList(L); getchar();

	printf("(4) 리스트 첫번째에 [월] 노드 삽입하기\n");
	insertFirstNode(L, "월");
	printList(L); getchar();
	
	printf("(5) 리스트의 공간을 해제하여 공백리스트 만들기\n");
	freeLinkedList_h(L);
	printList(L); getchar();
/*--------------------------------------------------------------------------------------*/
	listNode* p;
	L = createLinkedList_h();
	printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기\n");
	insertLastNode(L, "월");	insertLastNode(L, "수");	insertLastNode(L, "일");
	printList(L); getchar();

	printf("(2) 리스트에서 [수] 노드 탐색하기!\n");
	p = searchNode(L, "수");
	if (p == NULL)printf("찾는 데이터가 없습니다.\n");
	else printf("[%s]를 찾았습니다.\n", p->data);
	getchar();

	printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기!\n");
	insertMiddleNode(L, p, "금");
	printList(L); getchar();
	
	printf("(4) 리스트에서 [일] 노드 삭제하기	\n");
	p = searchNode(L, "일");
	deleteNode(L, p);
	printList(L); getchar();

	printf("(5) 리스트 순서를 역순으로 바꾸기	\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();
}