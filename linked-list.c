#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

// 노드 타입을 구조체로 정의한다.
typedef struct _ListNode { 
  element data;
  struct _ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->link = head;
	p->data = value;
	head = p;
	return head;
}

ListNode *insert(ListNode *head, ListNode *pre, element value) // 노드 pre 뒤에 새로운 노드 삽입
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->link = pre->link;
	p->data = value;
	pre->link = p;
	return head;
}

ListNode *delete_first(ListNode *head)
{
	ListNode *removed;
	if (head==NULL){
		return NULL;
	}
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode *delete(ListNode *head, ListNode *pre) // pre가 가리키는 노드의 다음 노드를 삭제.
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode *search(ListNode *head, element x)
{
	ListNode *p = head;
	while (p!=NULL) {
		if (p->link==x) {
			return p;
		}
		p = p->link;
	}
	return NULL; //fail
}

void print(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link) {
		printf("%d - ", p->data);
	}
	printf("NULL \n");
}

// 메인
int main(void)
{
	ListNode *head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	if (search_list(head, 30)!=NULL)
		printf("리스트에서 30을 찾았습니다. \n");
	else
		printf("리스트에 30가 없습니다. \n");

	return 0;
}