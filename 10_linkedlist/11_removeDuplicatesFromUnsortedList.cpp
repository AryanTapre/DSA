// TODO: Remove Dupliactes from unsorted linked list

#include<iostream>
#include<unordered_map>
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
        cout<<"list is empty"<<endl;
        return;
    }

    if(HEAD->next == nullptr) {
        return;
    }

    unordered_map<int, bool> map;
    Node* previous = nullptr;
    Node* current = HEAD;

    unordered_map<int, bool>::iterator ite;

    while(current != nullptr) {
        if(map.find(current->data)  == map.end()) {
            map[current->data] = true;
            previous = current;
            current = current->next;            
        } else {
            Node* deleteNode = current;
            current = current->next;
            previous->next = current;
            deleteNode->next = nullptr;
            delete deleteNode;
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

    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(1);
    Node* four = new Node(2);
    Node* five = new Node(3);
    Node* six = new Node(1);
    

    one->next = two;
    two->next = nullptr;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = nullptr;
    

    removeDuplicates(one);
    print(one);

return 0;
}