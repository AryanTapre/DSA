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

void insertAtEnd(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);

    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
    } else {
        TAIL->next = newNode;
        TAIL = newNode;
    }
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

void insertAtPosition(Node* &HEAD, Node* &TAIL, int data, int position) {
    int len = listLength(HEAD);

    if(position == 0) {
        insertAtBeginning(HEAD, TAIL, data);
        return;
    } else if (position >= len) {
        insertAtEnd(HEAD, TAIL, data);
        return;
    } else {
        int posCount = 0;
        Node* curr = HEAD;
        Node* prev;
        while(posCount < position) {
            ++posCount;
            prev = curr; 
            curr = curr->next;
        }

        Node* newNode = new Node(data);
        newNode->next = curr;
        prev->next = newNode;
    }

}

void print(Node* &HEAD) {
    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {

Node* HEAD = nullptr;
Node* TAIL = nullptr;

insertAtPosition(HEAD, TAIL, 10, 0);
insertAtPosition(HEAD, TAIL, 11, 1);
insertAtPosition(HEAD, TAIL, 0, 1);
insertAtPosition(HEAD, TAIL, 12, 0);
insertAtPosition(HEAD, TAIL, 15, 5);
print(HEAD);

cout<<endl<<"head ->"<<HEAD->data<<endl;
cout<<"tail ->"<<TAIL->data<<endl;

return 0;
}
