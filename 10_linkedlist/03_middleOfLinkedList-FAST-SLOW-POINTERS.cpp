// TODO: find the middle node of Linked list

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

void print(Node* HEAD) {
    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* getMiddleNode(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return nullptr;
    }

    if(HEAD->next == nullptr) { // handling one node case   
        return HEAD;
    } 

    Node* slow = HEAD;
    Node* fast = HEAD;

    // fast = HEAD->next; To change the middle node.
    
    while(slow != nullptr && fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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

    Node* middleNode = getMiddleNode(first);
    cout<<"middle node is :"<<middleNode->data<<endl;

return 0;
}