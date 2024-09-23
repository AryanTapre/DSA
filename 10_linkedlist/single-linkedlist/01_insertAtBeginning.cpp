#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
    
        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

void printList(Node* HEAD) {
    Node* temp = HEAD;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtBeginning(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);

    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
        
    } else {
        newNode->next = HEAD;
        HEAD = newNode;
    }
}

int main() {

    Node* HEAD = nullptr;
    Node* TAIL = nullptr;

    insertAtBeginning(HEAD,TAIL,10);
    insertAtBeginning(HEAD,TAIL,20);
    insertAtBeginning(HEAD,TAIL,30);
    insertAtBeginning(HEAD,TAIL,40);
    insertAtBeginning(HEAD,TAIL,50);

    printList(HEAD);

return 0;
}