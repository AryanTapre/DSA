// palindrome check in singly linked -list..

#include<iostream>
#include<vector>
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

Node* reverseListUtlilty(Node* &current, Node* &previous) {
    if(current == nullptr) {
        return previous;
    }

    Node* forward = current->next;
    current->next = previous;
    previous = current;
    current = forward;

    return reverseListUtlilty(current, previous);
}

Node* reverseList(Node* &HEAD) {
    Node* current = HEAD;
    Node* previous = nullptr;

    return reverseListUtlilty(current, previous);
}

void print(Node* &HEAD) {
    if(HEAD == nullptr) {
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

bool isPalindrome(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return false;
    }

    if(HEAD->next == nullptr) {
        return true;
    }

    // logic for finding the middle node
    Node* fast = HEAD->next;
    Node* slow = HEAD;

    while(fast != nullptr) {
        fast = fast->next;
        if(fast != nullptr) {
            fast =  fast->next;
            slow = slow->next;
        }
    }

    Node* middleNode = slow;

    // reverse the node after middle node
    middleNode->next = reverseList(middleNode->next);
    

    // start comparing halves
    Node* front = HEAD;
    Node* rear = middleNode->next;

    while(rear != nullptr) {
        if(front->data != rear->data) {
            return false;
        }
        front = front->next;
        rear = rear->next;
    }
    return true;
}


    

int main() {

    Node* head = new Node(20);
    Node* second = new Node(10);
    // Node* third = new Node(30);
    // Node* fourth = new Node(20);
    // Node* fifth = new Node(10);
    


    head->next = second ;
    second->next = nullptr;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = nullptr;


    
    if(isPalindrome(head)) {
        cout<<"yes, it's palindrome"<<endl;
    } else {
        cout<<"no, it's not palindrome"<<endl;
    }

return 0;
}