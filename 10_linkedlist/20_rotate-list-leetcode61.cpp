// leetcode 61
// rotate a list with k places/rounds

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data) : data(_data), next(nullptr) {}
};

int getLength(Node *head) {
    int count = 0;
    Node *temp = head;
    
    while(temp != nullptr) {
        ++count;
        temp=temp->next;
    }
    return count;
}

Node *rotateList(Node *head, int k) {
    if(head == nullptr || head->next == nullptr) return head;

    int places = k % getLength(head);

    if(places == 0) return head;

    while(places--) {
        Node *temp = head;
        Node *prev = nullptr;

        while(temp->next != nullptr) {
            prev=temp;
            temp=temp->next;
        }
        temp->next = head;
        head = temp;
        prev->next = nullptr;
    } 

    return head;
}

void print(Node *head) {
    if(head == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main() {

    Node *head = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(4);
    Node *five = new Node(5);

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    Node *ansHead = rotateList(head, 5);
    print(ansHead);

return 0;
}