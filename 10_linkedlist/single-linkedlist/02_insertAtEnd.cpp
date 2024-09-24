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

void print(Node* HEAD) {    
    if (HEAD == nullptr) {
        cout<<"List is empty"<<endl;
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
    } else {
        TAIL->next = newNode;
        TAIL = newNode;
    }
}   

int main() {

    Node* HEAD = nullptr;
    Node* TAIL = nullptr;

    insertAtEnd(HEAD, TAIL, 10);
    insertAtEnd(HEAD, TAIL, 20);
    insertAtEnd(HEAD, TAIL, 30);
    insertAtEnd(HEAD, TAIL, 40);

    print(HEAD);

    // cout<<endl<<HEAD->data<<endl;
    // cout<<TAIL->data<<endl;



return 0;
}