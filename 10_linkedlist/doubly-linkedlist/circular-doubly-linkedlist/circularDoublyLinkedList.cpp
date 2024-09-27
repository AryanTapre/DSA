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

void print(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"circular-doubly-list is empty"<<endl;
        return;
    }

    Node* HEAD = LAST->next;
    do {
        cout<<HEAD->data<<" ";
        HEAD = HEAD->next;
    }while(HEAD != LAST->next);

    cout<<endl;
}

int listLength(Node* &LAST) {
    int count = 0;
    Node* HEAD = LAST->next;

    do {
        ++count;
        HEAD = HEAD->next;
    }while(HEAD != LAST->next);
    
    return count;

}

void insertAtBeginning(Node* &LAST, int data) {
    Node* newNode = new Node(data);

    if(LAST == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        LAST = newNode;
        return;
    }

    Node* HEAD = LAST->next;
    newNode->next = HEAD;
    HEAD->prev = newNode;

    LAST->next = newNode;
    newNode->prev = LAST; 
}


void insertAtEnd(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        LAST = newNode;
        return;
    }

    Node* HEAD = LAST->next;
    LAST->next = newNode;
    newNode->prev = LAST;
    
    newNode->next = HEAD;
    HEAD->prev = newNode;
    LAST = newNode;

}

int main() {
    
    Node* last = nullptr;
    // insertAtEnd(last, 20);
    insertAtEnd(last, 30);
    insertAtBeginning(last, 10);

    print(last);

    cout<<"head->"<<last->next->data<<" "<<"last->"<<last->data<<endl;
    
return 0;
}