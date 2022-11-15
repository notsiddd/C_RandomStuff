#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node blah;

blah* lister(int num){
    blah* head;
    blah* temp;
    blah* nextNode;
    int i, value1;

    head = malloc(sizeof(blah));
    printf("Enter data of head.\n");
    scanf("%d",&value1);
    head->data = value1;
    head->next = NULL;

    //This way we can assign the next elements address to head.
    temp = head;

    for(i=2;i<=num;i++){
        nextNode = malloc(sizeof(blah));
        printf("Enter value of node %d.\n",i);
        scanf("%d",&value1);
        nextNode->data = value1;
        nextNode->next = NULL;

        temp->next = nextNode;
        temp = temp->next;
    }

    blah* printer;
    printer = head;

    while(printer!=NULL){
        printf("%d->",printer->data);
        printer = printer->next;
    }
    printf("NULL\n");
    return head;

}
blah* findLast(blah* head)
{
	blah* temp = head;
	while (temp != NULL && temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}
blah* parition(blah* first, blah* last)
{
	blah* pivot = first;
	blah* front = first;
	int temp = 0;
	while (front != NULL && front != last) {
		if (front->data < last->data) {
			pivot = first;
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			first = first->next;
		}
		front = front->next;
	}
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}

void quickSort(blah* first, blah* last)
{
	if (first == last) {
		return;
	}
	blah* pivot = parition(first, last);

	if (pivot != NULL && pivot->next != NULL) {
		quickSort(pivot->next, last);
	}

	if (pivot != NULL && first != pivot) {
		quickSort(first, pivot);
	}
}
int main()
{
	struct Node* head = NULL;
    int n, value;
    printf("Enter the number of elements you want the linked list to have!\n");
    scanf("%d", &n);
    head = lister(n);
	quickSort(head, findLast(head));
	printf("After Sorting:\n");
	blah* printer;
    printer = head;

    while(printer!=NULL){
        printf("%d->",printer->data);
        printer = printer->next;
    }
    printf("NULL\n");
	return 0;
}
