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

bool isCircular(Node* &HEAD) {
    if(HEAD == nullptr) return false;
    Node* slow = HEAD;
    Node* fast = HEAD;

    while(true) {
        fast = fast->next;
        if(fast == HEAD) return true;
        if(fast == nullptr) return false;

        if(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;

            if(fast == HEAD) return true;
            if(fast == nullptr) return false;
        }
    }

    return false;
}

int main() {

    Node* first = new Node(10); 
    Node* second = new Node(20); 
    Node* third = new Node(30); 
    Node* fourth = new Node(40); 
    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    if(isCircular(first))   
        cout<<"list is circular"<<endl;
    else 
        cout<<"list is not circular"<<endl;

    
return 0;
}