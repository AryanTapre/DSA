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

Node* reverseInKGroups(Node* HEAD, int k) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return nullptr;
    }

    if(k > length(HEAD)) {
        return HEAD;
    }    

    Node* previous = nullptr;
    Node* current = HEAD;
    Node* forward = nullptr;
    int count = 0;
    
    // Step A;
    while(count < k) {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
        ++count;
    }

    // Step B:
    if(forward != nullptr) {
        HEAD->next =  reverseInKGroups(forward, k);
    }

    //Step C;
    return previous;
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

    Node* head = reverseInKGroups(first, 3);

    print(head);

    
return 0;
}