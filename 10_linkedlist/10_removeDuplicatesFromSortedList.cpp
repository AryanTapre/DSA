//TODO: remove the duplicate nodes from sorted singly linked-list

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

void removeDuplicates(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"List is empty"<<endl;
        return;
    }

    if(HEAD->next == nullptr) {
        return;
    }

    int value;
    Node* temp = HEAD->next;
    Node* previous = HEAD;
    value = HEAD->data;

    while(temp != nullptr) {
        if(temp->data == value) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            previous->next = temp;
            nodeToDelete->next = nullptr;
            delete nodeToDelete;
        } else {
            value = temp->data;
            previous = temp;
            temp = temp->next;
        }
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
    Node* two = new Node(2);
    Node* three = new Node(2);
    Node* four = new Node(2);
    Node* five = new Node(2);
    Node* six = new Node(2);
    Node* seven = new Node(2);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = nullptr;

    removeDuplicates(one);
    print(one);


return 0;
}