//TODO: sort zero's, one's and Two's in the linked list

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

void sort012_coutingApproach(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;    
    }

    if(HEAD->next == nullptr) {
        return;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = HEAD;

    // couting 0's, 1's & 2's.,
    while(temp != nullptr) {
        if(temp->data == 0) {
            ++zeroCount;
        } else if(temp->data == 1) {
            ++oneCount;
        }else {
            ++twoCount;
        }

        temp = temp->next;
    }

    // overriding the nodes data with repsective counts of 0's, 1's and 2's..
    temp = HEAD;
  
        while(zeroCount--) {
            temp->data = 0;
            temp = temp->next;
        }

        while(oneCount--) {
            temp->data = 1;
            temp = temp->next;   
        }

        while(twoCount--) {
            temp->data = 2;
            temp = temp->next;
        }
    
}

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

int main() {

    Node* one = new Node(2);
    Node* two = new Node(1);
    Node* three = new Node(0);
    Node* four = new Node(0);
    Node* five = new Node(0);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    sort012_coutingApproach(one);
    print(one);

return 0;
}