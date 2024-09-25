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

void print(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* HEAD = LAST->next;
    do {
        cout<<HEAD->data<<" ";
        HEAD = HEAD->next;

    }while(HEAD != LAST->next);

    cout<<endl;
}
// INSERT IN EMPTY CIRCULAR LIST
void insertInEmptyList(Node* &LAST, int data) {
    if(LAST != nullptr) {
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = newNode;
    LAST = newNode;
}

// INSERT AT BEGINNING IN LIST
void insertAtBeginning(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) { // if list is empty
        newNode->next = newNode;
        LAST = newNode;
        return;
    }

    newNode->next = LAST->next;
    LAST->next = newNode;
}

// INSERT AT END IN LIST
void insertAtEnd(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) {
        newNode->next = newNode;
        LAST = newNode;
        return;
    }

    // list is non-empty
    newNode->next = LAST->next;
    LAST->next = newNode;
    LAST = newNode;
}

int main() {

    Node* last = nullptr;
    insertAtBeginning(last, 10);
    insertAtBeginning(last, 20);
    
    
    print(last);

    insertAtEnd(last, 100);
    insertAtEnd(last, 1000);
    insertAtBeginning(last, 0);
    print(last);


return 0;
}