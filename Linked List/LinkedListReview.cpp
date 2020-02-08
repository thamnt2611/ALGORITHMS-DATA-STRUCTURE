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
	if(head==NULL){
		DNode* p= makeDNode(v);
		head=p;
		tail=p;
	}
	else{
		DNode* p=makeDNode(v);
		tail->next=p;
		p->prev=tail;
		tail=p;
	}
}


int findSize(DNode* head){
	if(head==NULL){
		return 0;
	}
	DNode* p=head;
	int size=0;
	while(p!=NULL){
		size=size+1;
		p=p->next;
	}
	
	return size;
}

DNode* removeIthNode(int i){
	if(head==NULL) return NULL;
	if(i==1){
		DNode* p=head;
		head=head->next;
		head->prev=NULL;
		free(p);
		return head;
	}
	if(i==findSize(head)){
		DNode* p=tail;
		tail->prev->next=NULL;
		tail=tail->prev;
		free(p);
		return head;
	}
	DNode* p=head;
	int k=1;
	while(p->next!=NULL){
		k++;
		if(k==i) break;
		p=p->next;
	}
	DNode* q=p->next;
	p->next=p->next->next;
	p->next->prev=p;
	free(q);
	return head;
}

void printList(DNode* head){
	DNode* q=head;
	while (q!=NULL){
		printf("%d ", q->data);
		q=q->next;
	}
	printf("\n");
}


int main(){
	for(i=1; i<11; i++){
		append(i);
	}
	printList(head);

//	head=removeIthNode(10);
//	printList(head);
	
}
