// USING FLOYD'S LOOP DETECTION ALGORITMH...

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

bool detectLoop(Node* &HEAD) {  
    if(HEAD == nullptr) {
        cout<<"List is empty"<<endl;
        return false;
    }

    Node* fast = HEAD;
    Node* slow = HEAD;

    while(fast != nullptr) {
        fast = fast->next;

        if(fast!= nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow) return true;
    }
    return false;
}

void removeLoop(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"List is Empty"<<endl;
        return;
    }

    Node* slow = HEAD;
    Node* fast = HEAD;

    while(fast != nullptr) {
        fast = fast->next;

        if(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow) {
            slow = HEAD;
            break;
        }
    }

    if(fast == nullptr) {
        cout<<"There exists no loop"<<endl;
        return;
    }

    // loop is present in the list
    Node* previousOfFast = nullptr;
    while(fast != slow) {
        previousOfFast = fast;
        fast = fast->next;
        slow = slow->next;
    }
    
    if(previousOfFast == nullptr) {
        cout<<"Invalid-list, you have giving Circular linked list"<<endl;
        return;
    }

    previousOfFast->next = nullptr;
    cout<<"LOOP IS REMOVED SUCCESSFULLY!"<<endl;
}
    

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = seventh;  

    removeLoop(head);
    print(head);

    cout<<"is loop removed : "<<detectLoop(head)<<endl;


return 0;
}