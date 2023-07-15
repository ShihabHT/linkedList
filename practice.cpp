#include <iostream>

using namespace std;

class Node{
    public:
    int value;
    Node* next;
};
void insertAtTheFront(Node** head, int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
void insertAtTheEnd(Node**head, int value){
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    if (*head ==NULL){
        *head = newNode;
        return;
    }
    Node *lastNode = *head;
    while(lastNode->next!=NULL){
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}
void insertAfter(Node *previous, int value){
    if (previous == NULL){
        cout<<"Previous can't be NULL!"<<endl;
        return;
    }
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = previous->next;
    previous->next = newNode;
}

void printNodes(Node* node){
    while(node!=NULL){
        cout<<node->value<<" ";
        node = node->next;
    }
}

int main(){
    Node *head = new Node();
    Node *second = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = NULL;

    insertAtTheFront(&head, 0);
    insertAtTheEnd(&head, 15);
    insertAfter(second, 3);

    printNodes(head);

    return 0;
}