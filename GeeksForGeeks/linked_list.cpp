#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}NODE;

void append(int num, NODE **head){
	if(*head == NULL){
		*head = (NODE*)malloc(sizeof(NODE));
		(*head) -> data = num;
		(*head) -> next = NULL;
		return;
	}
	NODE *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	NODE *new_node =  (NODE*)malloc(sizeof(NODE));
	new_node -> data = num;
	new_node -> next = NULL;
	temp->next = new_node;
}

int main()
{
	NODE *head = NULL;
	append(3, &head);
	append(5, &head);
	append(8, &head);
	while(head != NULL){
		cout<<(head->data)<<endl;
		head = head->next;
	}
	return 0;
}