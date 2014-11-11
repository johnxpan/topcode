/* single linked list practice */
/* Source: Stanford CS library , code interview book */
/* They are short to write, and people like it during  interview  */
/* Noboday care you can build linked list, but they care if you   */
/* can do complex algorithm and pointer manipulation  */
/* linked list is a good practice for complex algorithm & pointer */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

/* put data after next pointer, so future data change */
/* won't affect the pointer */
struct node {
    struct node *next;
    int data;
};

typedef struct node Node;

/*******************************************************/
/* basic linked list utility, create new node, add it  */
/* from front & end, print list, build a list, check   */
/* list length                                         */
/*******************************************************/
Node * newNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode!=NULL)
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

    head = newNode(1);
    second = newNode(2);
    third = newNode(3);
    //fourth = newNode(4);

    head->next = second;
    second->next = third;
    third->next = NULL; // system may not set the third->next to NULL automatically
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
// no special case for empty list 
// it also works on any node in the middle of list
void push(Node ** headref, int data){
    Node * n = newNode(data);
    if(n != NULL) {
       n->next = (*headref); // not head->next, head is NOT a node, no next
       *headref = n;
    }
}
//add node to the end of a list
//special case for empty list
void append(Node **head, int data){
    Node *curr= *head;
    Node *n = newNode(data);

    if(curr==NULL){ // empty list
        *head= n;
        n->next= NULL;
    } else {
       while(curr->next!= NULL){
          curr= curr->next;
       }
       curr->next = n;
       n->next = NULL;
    }
}

/* done with basic utility */

/*************************************************************/
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
            return (curr->data);
        }
        curr=curr->next;
        index++;
    }
    assert(0); // non-exist element
}

//Delete a List, need to record curr->next before free(curr)
void deleteList(Node **headref){
    Node *curr=*headref;
    Node *next=NULL;

    while(curr!= NULL){
        next=curr->next;
        free(curr);
        curr=next;
    }
    *headref= NULL;

}

//extract data from head node, delete node.
int pop(Node **headref){
    Node *curr =NULL;
    int result =0;

    if(*headref==NULL)
        return FALSE;

curr= *headref;
    *headref = curr->next;
    result = curr->data;
    free(curr);

    return result;

}
// use push() which works both at the head and middle
void insertNth(Node **headref, int index, int data) {
   if(index==0)
       push(headref, data);
   else {
       Node *curr = *headref;
       int i;
       for(i=0; i<index-1; i++) {
          assert(curr!= NULL);
          curr= curr->next;
       }
       assert(curr!=NULL);
       push(&(curr->next), data);
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

//insert element in a sorted list
void sortedInsert(Node **headRef, Node *newNode){
    Node *curr = *headRef;

    if(curr== NULL || newNode->data< curr->data){ // empty list, or new node is smallest
        *headRef = newNode;
        newNode->next = NULL;
        return;
    }

    while (curr->next != NULL && (newNode->data > curr->next->data)){
        curr=curr->next;
    }

newNode->next = curr->next;
    curr->next = newNode;
}

//sort a linkedlist, by insert one by one
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

//append list b to the end of list a. we need to pass reference 
//of both a & b because a maybe empty, b needs to be nullify
void appendList(Node **aref, Node **bref) {
  Node *curr=*aref;

  if(*aref==NULL) {
     *aref=*bref;
     return;
  }

  while (curr->next!= NULL) {
     curr=curr->next;
  }

  curr->next=*bref;
  *bref=NULL; // null the original b, since it is appended to a now

}

//Split a list in two, first list shall have the extra Node
void frontBackSplit(Node *source, Node **aref, Node **bref) {
     Node *curr = NULL;
     int i = 0;

     int len = linkLength(source);
     if(len<=1) {
         *aref = source;
         *bref =NULL;
         return;
     }
    *aref=source;
     curr=source;
     // figure (len-1)/2 by a few drawing
     while(i< (len-1)/2) {
        curr=curr->next;
        i++;
     }
     *bref=curr->next;
     curr->next= NULL;
}
//remove duplicate from a sorted list
void removeDuplicates(Node *headref) {

  Node *curr =headref;
  Node *currNext = NULL;
  if(curr==NULL)  // empty list
    return;
  currNext = curr->next;

  while (currNext != NULL) {
     if(curr->data == currNext->data) {
        curr->next = currNext->next;
        free(currNext);
        currNext=curr->next;
     } else {
        curr=currNext;
        currNext=curr->next;
     }
  }
}

//move the first element of list B to the front of list A 
//This routine is extremely help when you split list
// if a={1,2} b={3,4.5} then a={3,1,2} b={4,5}
void moveNode (Node **aref, Node **bref) {
    Node *ahead = *aref;
    Node *bhead = *bref;
    //make sure list b has an element
    assert(bhead !=NULL);

    *bref = bhead->next;
    *aref = bhead;
    bhead->next = ahead;
}

Node *shuffleMerge(Node *a, Node *b) {
  Node *result= NULL;
  Node **lastPtrRef= &result;

  while (a!=NULL && b != NULL) {
     moveNode(lastPtrRef, &a);
     lastPtrRef = &((*lastPtrRef)->next);
     moveNode(lastPtrRef, &b);
     lastPtrRef = &((*lastPtrRef)->next);
  }
  if(a==NULL) { // append the rest of b
     *lastPtrRef =b;
  }
  if(b==NULL) {
     *lastPtrRef=a;
  }

  return result;
}

//recursive shuffle merge
Node *rsMerge(Node *a, Node *b) {
   Node *result;
   Node *recur;

   if(a ==NULL)
     return(b);
   else if(b==NULL)
     return (a);
   else {  // do recursive call first, so we do not need temp store for a/b->next 
     recur=rsMerge(a->next, b->next);
     result=a;
     a->next = b;
     b->next = recur;
     return(result);
   }
}

// take 2 sorted list, and merge 2 into one list, sorted
Node *sortedMerge(Node *a, Node *b) {
  Node *result = NULL;
  Node **lastPtrRef = &result;

  while( a!=NULL && b!=NULL) {
     if(a->data<=b->data) {
         moveNode(lastPtrRef, &a);
     } else {
         moveNode(lastPtrRef, &b);
     }

   lastPtrRef = &((*lastPtrRef)->next);
  }
  if(a==NULL) {
     *lastPtrRef=b;
  }
  if(b==NULL) {
     *lastPtrRef=a;
  }
  return result;
}

//merge sort for linked list
void mergeSort(Node **headRef) {
  Node *head = *headRef;
  Node *a;
  Node *b;

  if((head ==NULL)||(head->next==NULL)) {
     return;
  }
  frontBackSplit (head, &a, &b); // split head into a, b sublists
  mergeSort(&a);
  mergeSort(&b);

  *headRef = sortedMerge(a,b); // merge to sorted list
}
// reverse a linked list, one pass
// you need 3 pointers, result(init to null), curr, and currnext
void reverseList(Node **headRef) {
    Node *result =NULL;
    Node *curr = *headRef;
    Node *currNext =NULL;

    while(curr!=NULL) {
       currNext=curr->next;
       curr->next= result;
       result = curr;
       curr=currNext;
    }
    *headRef = result;
}

//recursive reverse list
void recursiveReverse(Node **headRef) {
   Node *first;
   Node *rest; // rest of list

   if(*headRef == NULL)
      return;  // empty list base case
   first = *headRef; // assume first = {1,2,3}

rest = first->next; // rest = {2,3} 

   if(rest ==NULL)
      return;  // empty rest base case

   recursiveReverse(&rest);

   first->next->next =first;
   first->next =NULL;
   *headRef = rest; // fix head pointer
}

int main(void){
    Node *myList = NULL;
    Node *dupList = NULL;
    //Node *nn= newNode(4);
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

    insertNthTest();

    //sortedInsert(&dupList, nn);
    printList(dupList);

    // random list
    insertNth(&randomList, 0, 13);
    insertNth(&randomList, 1, 13);
    insertNth(&randomList, 2, 27);
    insertNth(&randomList, 3, 55);
    insertNth(&randomList, 4, 55);

    printList(randomList);
    removeDuplicates(randomList);
    printList(randomList);

    //insertSort(&randomList);
    //printList(randomList);

    //testAppendList();

    //testFrontBackSplit();
    return 0;
}

#if 0
/*https://www.youtube.com/watch?v=KYH83T4q6Vs*/
/* Function to reverse the linked list */
static void reverse(Node** head_ref)
{
    Node * prev   = NULL; // save the prev for single link next
    Node * next;   // save next before cut off the curr->next link
    Node * current = *head_ref;

    while (current != NULL)
    {
        next  = current->next; //save the next of current node; 
        current->next = prev;   //change current next to prev
        prev = current;   // now prev = current
        current = next;   // current points to next now
    }
    *head_ref = prev;
}
// recursive version
// assume head is global
// Node *head;
Node * rreverse(Node *p ) {
    if(p->next==NULL) {
        head=p;  // base condition
        return;
    }
    rreverse(p->next); 
    // it will execute only after reach the end of list
    assume p before q
    Node * q= p->next;
    q->next=p;
    p->next =NULL;
}
#endif






