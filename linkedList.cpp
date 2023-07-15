#include <iostream> 
using namespace std;

class Node{
public:
    int Value;
    Node *Next;
};

void printList (Node* n) { 
    while (n!=NULL){
        cout << n->Value << endl;
        n = n->Next;
    }
}

void insertAtTheFront(Node**head, int newValue){ //we took pointer of pointer cause
/*
  cause the newNode should be the head noow. if we take just pointer the head will not
  change as the scope of the head is  within the  function. In order to change the
  head of the main function we need to use the pointer of the pointer.
*/
    //1. Prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    //2. Put it in front of current head
    newNode->Next = *head;
    //3. Move head of the list to point to the newNode
    *head = newNode;
}
void insertAtTheEnd(Node **head, int newValue){
    // 1. Prepare a newNode
    Node *newNode = new Node();
    newNode->Value = newValue;
    newNode->Next = NULL;
    // 2. If Linked list is empty, newNode will be a head node
    if (*head == NULL){
        *head = newNode;
        return;
    }
    // 3. Find the last node
    Node *last = *head;
    while (last->Next != NULL){
        last = last->Next;
    }
    // 4. Insert newNode after last node (at the end)
    last->Next = newNode;
}
void insertAfter(Node *previous, int newValue){
    // 1. Check if previous node is NULL
    if (previous == NULL){
        cout << "Previous can not be NULL";
        return;
    }
    // 2. Prepare a newNode
    Node *newNode = new Node();
    newNode->Value = newValue;
    // 3. Insert newNode after previous
    newNode->Next = previous->Next;
    previous->Next = newNode;
}

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;

    insertAtTheFront(&head, -1);
    insertAtTheFront(&head, -2);
    insertAtTheEnd(&head, 4);
    insertAtTheEnd(&head, 5);
    insertAfter(head, 0);
    insertAfter(second, -5);

    printList(head);

    return 0;
}