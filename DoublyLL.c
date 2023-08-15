// Implementing Doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *CreateNode() {
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    return new;
}

void Insert(int val) { /*Inserting element at head*/
    struct Node *NewNode = CreateNode(); /*NewNode is created everytime function is called*/
    NewNode->value = val; /*Value assigned to NewNode*/
    NewNode->next = head; /*NewNode's next points to head*/
    NewNode->prev = NULL; /*NewNode's previous points to NULL*/
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n"); /*Printing normally in forward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) { /*Moving to the last node*/
        temp = temp->next;
    }

    printf("\nBackward:\n"); /*Printing in backward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for (int i=0; i<n; i++) {
        printf("Enter element: ");
        scanf("%d",&val);
        Insert(val); /*Inserting value everytime loop executes*/
    }
    Display();
    ReverseDisplay();
    // instead of for loop you can use switch case inside of while loop 
    // like this:
    // int choice,int num; 
    // while(1){
    //     printf("input your choice 1-Add node, 2-Display node, 3-Reverse display: "); 
    //     scanf("%d",&choice);
    //     switch(choice){
    //         case 1: printf("insert element");scanf("%d",&num);insert(num);break;
    //         case 2: Display(); break;
    //         case 3: ReverseDisplay(); break;
    //         case 4: break;
    //     }
    //     if(choice == 4)break; // to break while loop
    // }
    // this way you can add as many elements you want and delete them whenever you want
    // return 0; 
}
