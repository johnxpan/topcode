/* single linked list practice */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
    struct node *next;
    int data;
};

typedef struct node Node;

Node * newNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    return newNode;
}

Node *buildOne(void){
    Node *head = NULL;

    head = newNode(1);
    head->next = NULL;
    return head;

}

Node *buildOneTwo(void){
    Node *head=NULL;
    Node *second=NULL;

    head   = newNode(1);
    second = newNode(2);

    head->next = second;
    second->next = NULL;

    return head;
}

Node * buildOneTwoThree (void){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    //Node *fourth = NULL;

    head = newNode(1);
    second = newNode(2);
    third = newNode(3);
    //fourth = newNode(4);

    head->next = second;
    //second->next =NULL;
    second->next = third;
    third->next = NULL; // system may not set the third->next to NULL automatically
    //fourth->next =NULL;
    return head;
}

Node * build4(void){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    head = newNode(1);
    second = newNode(2);
    third = newNode(3);
    fourth = newNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth; // system may not set the third->next to NULL automatically
    fourth->next =NULL;
    return head;
}


int linkLength( Node *head){
    Node *node = head;
    int cnt = 0;
    while (node != NULL){
        cnt++;
        node = node->next;
    }
    return cnt; // local variable node is dealloate, but Nodes are still exists in heap
}

void printList(Node *head){
    printf("\nThe list = ");
    while(head!=NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
}

// add new node to the head of LinkedList
void push(Node ** head, int data){
    Node * n = newNode(data);
    n->next = (*head); // not head->next, head is NOT a node, no next
    *head = n;
}

//add node to the end of a list
void append(Node **head, int data){
    Node *curr= *head;
    Node *n = newNode(data);

    if(curr==NULL){
        *head= n;
        return;
    }
    while(curr->next!= NULL){
        curr= curr->next;
    }
    curr->next = n;
    n->next = NULL;
}
Node *copyList(Node *srcHead){
    Node *n=NULL;
    Node *nList = NULL;
    Node *curr= NULL;

    if(srcHead != NULL){
        n = newNode(srcHead->data);
        nList = n;
        curr=nList;
        srcHead=srcHead->next;
    }

    while(srcHead!= NULL){
        n= newNode(srcHead->data);
        curr->next = n;
        srcHead=srcHead->next;
        curr=curr->next;
    }
    curr->next = NULL;
    return nList;

}

// change head using reference Pointer
void changeToNull(Node **headref){
    *headref = NULL;
}

Node *addAtHead(void){
    Node *head = NULL;
    int i=0;

    for(i=1; i< 6; i++){
        push(&head, i);
    }
    return head;
}
Node *buildWithSpecialCase(void){
    int i=0;
    Node *head = NULL;
    Node *tail=NULL;
    Node *n = NULL;
    //special case
    n = newNode(1);
    head=n;
    tail=n;

    for(i=2; i<=5; i++){
        n= newNode(i);
        tail->next = n;
        tail=tail->next;
    }
    tail->next = NULL;
    return head;

}

Node *buildWithDummyNode(void){
    Node dummy;
    Node *tail= & dummy;
    Node *n=NULL;
    int i=0;
    dummy.next = NULL;
    for(i=1; i<10; i++){
        n= newNode(i);
        tail->next = n;
        tail=tail->next;
    }
    tail->next = NULL;
    return (&dummy)->next;
}
//count specific integer inside a  linked list
int countTest(Node *head, int key){
    Node *curr=head;
    int cnt=0;
    while(curr!=NULL){
        if(curr->data == key){
            cnt++;
        }
        curr=curr->next;
    }
    return cnt;
}

//Get the nth element of a linked List
int getNth(Node *head, int n){
    Node *curr= head;
    int index = 0;
    while (curr != NULL){
        if(index == n){
            break;
        }
        curr=curr->next;
        index++;
    }
    return curr->data;
}

//Delete a List
void deleteList(Node **head){
    Node *curr=*head;
    Node *next=NULL;

    while(curr!= NULL){
        next=curr->next;
        free(curr);
        curr=next;
    }
    free(*head);

}
int pop(Node **head){
    Node *curr=NULL;
    int data=0;

    if(*head==NULL)
        return FALSE;
    curr= (*head)->next;
    data = (*head)->data;
    free(*head);
    *head= curr;

    return data;

}

void popTest (){
    Node *head = buildOneTwoThree();
    int a = pop(&head);
    int b= pop(&head);
    int c= pop(&head);

    printf("\na= %d, b= %d, c=%d",a , b ,c);
    printf("\nList len = %d", linkLength(head));
}

void insertNth(Node **head, int n, int data)
{
    Node *curr=NULL;
    Node *currNext=NULL;
    int i = 1;
    Node *new = newNode (data);

    if(*head == NULL){// empty list
        *head = new;
        (*head)->next = NULL;
        return;
    }

    if(n==0) { // insert at head
        new->next = *head;
        *head= new;
        return;
    }


    curr = *head;
    currNext = curr->next;
    while (curr != NULL) {
        if(i==n) {
            new->next = currNext;
            curr->next= new;
            break;
        }
        curr= currNext;
        currNext = curr->next;
        i++;

    }
}

void insertNthTest(void) {

        Node *head = NULL;
        insertNth(&head, 0, 13);
        insertNth(&head, 0, 7);
        insertNth(&head, 1, 42);
        insertNth(&head, 1, 5);
        printList(head);

}

void sortedInsert(Node **headRef, Node *newNode){
    Node *curr = NULL;
    Node *currNext = NULL;

    if(*headRef == NULL){ // empty list
        *headRef = newNode;
        newNode->next = NULL;
        return;
    }

    if((*headRef)->data > newNode->data) { // insert at the head
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    curr= *headRef;
    currNext= curr->next;

    while (currNext != NULL && (newNode->data > currNext->data)){
        curr=curr->next;
        currNext= curr->next;
  //same situation if currNext == NULL
    newNode->next = currNext;
    curr->next = newNode;

}

void insertSort(Node **headRef){
    Node *newList=NULL;

    Node *curr= *headRef;
    Node *next=NULL;

    while(curr!=NULL){
        next=curr->next; //critical,
        sortedInsert(&newList, curr);
        curr=next;
    }
    *headRef = newList;
}

void appendList(Node **aRef, Node **bRef){
    Node *curr = *aRef;
//  Node *currNext = NULL;
    // we shall not care bRef is empty or not
    if(*bRef == NULL) {
        return; // do nothing
    }

    if(*aRef == NULL) { // list a is empty
        *aRef = *bRef;
        return;
    }

    while(curr->next!= NULL){
        curr =curr->next;
    }
    //To the end of a list
    curr->next = *bRef;
    *bRef=NULL; // clear list B

}

//Split list in two, first list shall have the extra
Node *frontBackSplit (Node *a)
{
    Node *curr = a;
    Node *b = NULL; // the second half list
    int len = 0;
    int i=0;

    if(a == NULL) {
        return NULL; // no split
    }

    while(curr != NULL) {
        len++;
        curr=curr->next;
    }

    if(len==1) {
        return NULL; // b is empty
    }
    curr = a;
    if(len%2 == 1){
        for(i=0; i<len/2; i++){
            curr=curr->next;
        }
    } else {
        for(i=0; i<len/2-1; i++){
            curr=curr->next;
        }
    }
    b = curr->next;
    curr->next = NULL;

    return b;
}
void testFrontBackSplit(void){
    Node* a = build4();

    Node* b = NULL;

    printf("\noriginal list = ");
    printList(a);

    b = frontBackSplit(a);
    printf("\nnew List a = ");
    printList(a);
    //b = frontBackSplit(a);
    printf("\nList b = ");
    printList(b);
}

void testAppendList(void){
    Node *a = buildOneTwoThree();
    Node *b = buildOneTwoThree();

    appendList(&a, &b);
    printf("\n List A = ");
    printList(a);
}

void removeDuplicate(Node * head){
    Node *curr =head;
    Node *currNext = NULL;

    while (curr!=NULL){
        if(curr->next ==NULL) {
            return; // done
        }
        if(curr->data == curr->next->data){
            currNext = curr->next;
            curr->next = curr->next->next;
            free(curr->next);
        }
        curr = curr->next;

    }
}
int main(void){
    Node *myList = NULL;
    Node *dupList = NULL;
    Node *nn= newNode(4);
    Node *randomList =NULL;
    append(&myList, 10);
    //append(&myList, 15);
    printList(myList);

    myList= buildOneTwoThree();
    if(myList != NULL){
        printList(myList);
        printf("\nmyList length = %d; ", linkLength(myList));
    }

    push(&myList, 0);
    push(&(myList->next), 42);
    printList(myList);

    append(&myList,5);
    printList(myList);

    dupList = copyList(myList);
    printList(dupList);

    changeToNull(&dupList);
    printList(dupList);

    dupList=addAtHead();
    printList(dupList);

    dupList= buildWithSpecialCase();
    printList(dupList);

    dupList=buildWithDummyNode();
    printList(dupList);

    printf("\n List has %d 5.", countTest(dupList,5));
    printf("\n 3rd Element of list = %d", getNth(dupList, 3));
    //deleteList(&dupList);

    popTest();
    insertNthTest();

    sortedInsert(&dupList, nn);
    printList(dupList);

  // random list
    insertNth(&randomList, 0, 13);
    insertNth(&randomList, 1, 13);
    insertNth(&randomList, 2, 27);
    insertNth(&randomList, 3, 55);
    insertNth(&randomList, 4, 55);

    printList(randomList);
    removeDuplicate(randomList);
    printList(randomList);

    //insertSort(&randomList);
    //printList(randomList);

    //testAppendList();

    //testFrontBackSplit();
    return 0;
}





