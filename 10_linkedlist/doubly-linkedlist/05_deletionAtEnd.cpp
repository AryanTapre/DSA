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

int listLength(Node* &HEAD) {
    int length = 0;
    Node* temp = HEAD;

    while(temp != nullptr) {
        ++length;
        temp = temp->next;
    }
    return length;
}

void insertAtBeginning(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);
    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
        return;
    }

    newNode->next = HEAD;
    HEAD->prev = newNode;
    HEAD = newNode;
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

void insertAtPosition(Node* &HEAD, Node* &TAIL, int data, int position) {
    int len = listLength(HEAD);

    if(position == 1) {
        insertAtBeginning(HEAD, TAIL, data);
    } else if(position > len) {
        insertAtEnd(HEAD, TAIL, data);
    } else {

        Node* newNode = new Node(data);
        int i = 1;
        Node* T = HEAD;

        while(i < position-1) {
            ++i;
            T = T->next;
        }

        // newNode->next = T->next;
        // T->next->prev = newNode;
        // T->next = newNode;
        // newNode->prev = T;

        Node* previousPointer = T;
        Node* currentPointer = T->next;

        previousPointer->next = newNode;
        newNode->prev = previousPointer;
        currentPointer->prev = newNode;
        newNode->next = currentPointer;
    }
}

void deletionAtEnd(Node* &HEAD, Node* &TAIL) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    // handling special case of one element
    if(listLength(HEAD) == 1) {
        Node* temp = TAIL;
        HEAD = nullptr;
        TAIL = nullptr;
        delete temp;
        return;
    }

    Node* temp = TAIL;
    TAIL = temp->prev;
    TAIL->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    //insertAtEnd(head, tail, 10);
    // insertAtEnd(head, tail, 20);
    // insertAtPosition(head, tail, 21, 1);
    // insertAtPosition(head, tail, 30, 3);
    insertAtPosition(head, tail, 31, 4);
    deletionAtEnd(head, tail);
    print(head);

    cout<<head<<" "<<tail<<endl;

    
    
return 0;
}