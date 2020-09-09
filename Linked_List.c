#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node *head;

struct Node* Insert(int data, int loc)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = data;
	temp->next = head;
	int i;
	
	if(loc==1)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	struct Node* temp2 = head;
	
	for(i=0; i<loc-2; i++)
	{
		temp2 = temp2->next;
	}
	
    temp->next = temp2->next;
    temp2->next = temp;
	
	return head;
}
void Delete(int loc)
{
	struct Node* temp = head;
	int i;
	if(loc==1)
	{
		head = temp->next;
		free(temp);
		return;
	}
	
	for(i=0; i<loc-2; i++)
	{
		temp = temp->next;
	}
	
	struct Node* temp2 = temp->next;
	temp->next = temp2->next;
	free(temp);
	
}
void Reverse()
{
	struct Node* prev,*curr,*next;
	curr = head;
	prev = NULL;
	
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	head = prev;
}
void Print()
{
	struct Node*temp = head;
	
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	//print with recursion
	/*
	if(temp==NULL)
		return;
	
	print("%d ",temp->data)
	Print(temp->next);
	
	*/
}
int main(int argc, char *argv[]) {
	
	printf("Sort: ");
	head = NULL;
	head = Insert(3,1);
	head = Insert(15,2);
	head = Insert(45,3);
	head = Insert(22,4);
	head = Insert(4,5);
	head = Insert(28,6);
	head = Insert(23,7);
	Print();
	Delete(1);
	printf("Deleted first item\n");
	printf("Sort: ");
	Print();
	printf("\nReverse: ");
	Reverse();
	Print();
	
	return 0;
}
