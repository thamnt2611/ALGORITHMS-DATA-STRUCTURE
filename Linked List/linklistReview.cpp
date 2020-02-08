#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* head=NULL;
Node* makeNode(int v){
	Node* p= (Node*)malloc(sizeof(Node));
	p->data=v;
	p->next=NULL;
}

Node* push(Node* h, int v){
	Node* p= makeNode(v);
	if(head==NULL){
		head=p;
	}
	else{
		p->next=head;
		head=p;
	}
	return head;
}
void printList(Node* head){
	Node* q=head;
	while(q!=NULL){
		printf("%d ", q->data);
		q=q->next;
	}
}

Node* findBefore(Node* head, int u){
	if(head->data==u) return NULL;
	if(head->next->data==u) return head;
	return findBefore(head->next, u);
}
Node* findAfter(Node* head, int u){
	if(head->data==u) return head->next;
	return findAfter(head->next, u);
}

//Remove duplicates from a sorted linked list

Node* removeDup(Node* head){
	if(head==NULL) return NULL;
	Node* p=head;
	while(p->next!=NULL){
		if(p->next->data==p->data){
			Node* temp=p->next;
			p->next=p->next->next;
			free(temp);
		}
		else{
			p=p->next;
		}
	}
	return head;
}

Node* reversedList(Node* head){
	Node* pre=NULL;
	Node* p=head;
	while(1){
		Node* q=p->next;
		p->next=pre;
		pre=p;
		if(q==NULL) break;
		p=q;
	}
	return p;
}

Node* reversedListRec(Node* cur, Node* pre){
	if(cur==NULL) return pre;
	Node* p=cur->next;
	cur->next=pre;
	p=reversedListRec(p, cur);
}


void printReverse(Node* head){
	if(head==NULL) return;
	if(head->next==NULL){
		printf("%d ", head->data);
	}
	else{
		printReverse(head->next);
		printf("%d ", head->data);
	}
}


int detectLoop(Node* head){
	if(head==NULL) return 0;
	Node* q=head;
	Node* dq=head;
	while(1){
		q=q->next;
		if(q==NULL){
			return 0;
		}
		if(dq->next==NULL) return 0;
		dq=dq->next->next;
		if(dq==NULL){
			return 0;
		}
		if(dq==q){
			return 1;
		}
	}
}


void makeCircleList(Node* head){
	Node* q=head;
	if(head==NULL) return;
	while(q->next!=NULL){
		q=q->next;
	}
	q->next=head;
}

int main(){
	for(int i=300; i>=1; i--){
		head=push(head, i);
	}
	
	makeCircleList(head);

//	printList(head);
//	printf("\n");
	if(detectLoop(head)){
		printf("This list has loop");
	}
	else{
		printf("This list hasn't loop");
	}
	
	
	
//	printReverse(head);
//	printf("\n");
//	printList(reversedListRec(head, NULL));
//	printf("%d\n", findBefore(head, 8)->data);
//	printf("%d\n", findAfter(head, 8)->data);
	
}
