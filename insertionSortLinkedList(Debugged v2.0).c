#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
typedef struct Node blah;
blah* sorted = NULL;
blah* headoh = NULL;


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
    headoh = head;
    return head;

}
void sortedInsert(blah* inserter)
{
    //For head element
    if (sorted == NULL || sorted->data >= inserter->data) {
        inserter->next = sorted;
        sorted = inserter;
    }
    else {
        blah* current = sorted;
        while (current->next != NULL
               && current->next->data < inserter->data) {
            current = current->next;
        }
        inserter->next = current->next;
        current->next = inserter;
    }
}
 
void insertionSort(blah* head)
{
  
    blah* current = headoh;
    while (current != NULL) {
        blah* next = current->next;
  
        // insert current in sorted linked list
        sortedInsert(current);
  
        // Update current
        current = next;
    }
    headoh = sorted;
}
int main()
{
    int n, value;
    printf("Enter the number of elements you want the linked list to have!\n");
    scanf("%d", &n);
    headoh = lister(n);
	insertionSort(headoh);
	printf("After Sorting:\n");
	blah* printer;
    printer = headoh;

    while(printer!=NULL){
        printf("%d->",printer->data);
        printer = printer->next;
    }
    printf("NULL\n");
	return 0;
}
