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
        cout<<"list is empty"<<endl;~
        return;
    }

    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {



return 0;
}