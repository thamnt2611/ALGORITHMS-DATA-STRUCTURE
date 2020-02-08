// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// A linked list node 
class Node { 
public: 
	int data; 
	Node* next; 
}; 

void append(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 

	Node* last = *head_ref; 
	new_node->data = new_data; 
	new_node->next = NULL; 
	if (*head_ref == NULL) { 
		*head_ref = new_node; 
		return; 
	} 

	// Else traverse till the last node 
	while (last->next != NULL) 
		last = last->next; 

	// Change the next of last node 
	last->next = new_node; 
	return; 
} 

// Function to return the maximum contiguous 
// nodes sum in the given linked list 
int MaxContiguousNodeSum(Node* head){
	Node* p=head;
	int max=0;
	int cur=0;
	while(p!=NULL){
		if(cur<0) cur=p->data;
		else{
			cur+=p->data;
		}
		if(cur>max) max=cur;
		p=p->next;
	}
	return max;
} 

// Driver code 
int main() 
{ 
	// Create the linked list 
	Node* head = NULL; 
	append(&head, -2); 
	append(&head, -3); 
	append(&head, 4); 
	append(&head, -1); 
	append(&head, -2); 
	append(&head, 1); 
	append(&head, 5); 
	append(&head, -3); 

	cout << MaxContiguousNodeSum(head); 

	return 0; 
} 

