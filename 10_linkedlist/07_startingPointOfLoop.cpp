// Find the starting point of the loop
// link to article: https://www.geeksforgeeks.org/how-does-floyds-slow-and-fast-pointers-approach-work/

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

Node* detectStartingPointLoop(Node* &HEAD) {
    if (HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return nullptr;
    }

    Node* fast = HEAD;
    Node* slow = HEAD;

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
        return nullptr;
    }

    // loop detected..
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
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
    Node* seventy = new Node(70);
    Node* eighty = new Node(80);


    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventy;
    seventy->next = eighty;
    eighty->next = first;


    Node* point  = detectStartingPointLoop(first);
    if(point == nullptr) 
        cout<<"loop not detected"<<endl;
    else 
        cout<<"staring point of loop is : "<<point->data<<endl;
    

return 0;
}