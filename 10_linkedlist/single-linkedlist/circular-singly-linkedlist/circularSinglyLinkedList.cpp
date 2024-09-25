#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void print(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* HEAD = LAST->next;
    do {
        cout<<HEAD->data<<" ";
        HEAD = HEAD->next;

    }while(HEAD != LAST->next);

    cout<<endl;
}
// INSERT IN EMPTY CIRCULAR LIST
Node* insertInEmptyList(Node* &LAST, int data) {
    if(LAST != nullptr) return LAST;

    Node* newNode = new Node(data);
    newNode->next = newNode;
    LAST = newNode;
    return LAST;
}


int main() {

    Node* last = nullptr;
    last = insertInEmptyList(last,10);
    print(last);

return 0;
}