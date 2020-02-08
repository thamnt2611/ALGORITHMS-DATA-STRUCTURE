#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i;

struct DNode{
	int data;
	struct DNode* next;
	struct DNode* prev;
};
DNode* head=NULL; 
DNode* tail=NULL;

DNode* makeDNode(int v){
	DNode* p= (DNode*)malloc(sizeof(DNode));
	p->next=NULL; p->prev=NULL;
	p->data=v;
	return p;
}

void append(int v){
	DNode* p=makeDNode(v);
	if (head==NULL){
		head=p;
		tail=p;
	}
	else{
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
}

void printList(){
	DNode* q=head;
	while (q!=NULL){
		printf("%d ", q->data);
		q=q->next;
	}
}

int main(){
	for(i=1; i<11; i++){
		append(i);
	}
	printList();
	
}
