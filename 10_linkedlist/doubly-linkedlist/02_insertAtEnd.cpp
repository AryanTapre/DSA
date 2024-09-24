#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    Node() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void print(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtEnd(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);
    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
        return;
    }

    TAIL->next = newNode;
    newNode->prev = TAIL;
    TAIL = newNode;
}


int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);

    print(head);

    cout<<endl<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;

return 0;
}