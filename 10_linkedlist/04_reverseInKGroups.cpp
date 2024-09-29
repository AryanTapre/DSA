// TODO: Reverse Linked list in K Groups

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int length(Node* &HEAD) {
    Node* temp = HEAD;
    int count = 0;
    while(temp != nullptr) {
        ++count;
        temp = temp->next;
    }
    return count;
}

void print(Node* HEAD) {
    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverseInKGroups(Node* &HEAD, int k) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return nullptr;
    }

    
}

int main() {

    Node* first = new Node(10); 
    Node* second = new Node(20); 
    Node* third = new Node(30); 
    Node* forth = new Node(40); 
    Node* fifth = new Node(50); 
    Node* sixth = new Node(60); 

    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = nullptr;

    print(first);

    
    

return 0;
}