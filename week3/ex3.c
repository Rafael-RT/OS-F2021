#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void print_list(struct node *head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	putchar('\n');
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode){
    if(head != NULL){
        struct node* current = prevnode->next;
        prevnode->next = newnode;
        newnode->next = current;
    } else{
        head = newnode;
    }
}

void delete_node(struct node **head, struct node *delnode){
    struct node* next_node = *head;
    
    if(delnode == next_node){
        next_node = (*head)->next;
        (*head) = next_node;
    } else{
        while(next_node->next != delnode){
            next_node = next_node->next;
        }
        
        next_node->next = delnode->next;
    }
    free(delnode);
}

int main(){

	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* n1 = (struct node*)malloc(sizeof(struct node));
	struct node* n2 = (struct node*)malloc(sizeof(struct node));
	struct node* n3 = (struct node*)malloc(sizeof(struct node));
	
	head->data = 5;
	n1->data = 144;
	n2->data = 40;
	n3->data = 25;
	
	printf("Inserting 5 as a head of the list:\n");
	insert_node(NULL, head, NULL);
	print_list(head);
	printf("Inserting 144 to the end of the list:\n");
	insert_node(head, n1, head);
	print_list(head);
	printf("Inserting 40 to the end of the list:\n");
	insert_node(head, n2, n1);
	print_list(head);
	printf("Inserting 25 between 144 and 40:\n");
	insert_node(head, n3, n1);
	print_list(head);
	printf("Deleting 144 from the list:\n");
	delete_node(&head, n1);
	print_list(head);
	
	return 0;
}
