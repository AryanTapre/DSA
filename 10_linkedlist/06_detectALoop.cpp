// TODO: Detect A loop ()

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


bool detectLoop(Node* &HEAD) {  
    if(HEAD == nullptr) {
        cout<<"List is empty"<<endl;
        return false;
    }

    Node* fast = HEAD;
    Node* slow = HEAD;

    while(fast != nullptr) {
        fast = fast->next;

        if(fast!= nullptr && fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow) return true;
    }
    return false;
}

int main() {

    Node* first = new Node(10); 
    Node* second = new Node(20); 
    Node* third = new Node(30); 
    Node* forth = new Node(40); 
    Node* fifth = new Node(50); 
    Node* sixth = new Node(60); 
    Node* seventy = new Node(70);
    Node* eighty = new Node(80);


    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventy;
    seventy->next = eighty;
    eighty->next = fifth;

    

    if(detectLoop(first)) {
        cout<<"loop detected"<<endl;
    } else {
        cout<<"Loop not detected"<<endl;
    }



return 0;
}