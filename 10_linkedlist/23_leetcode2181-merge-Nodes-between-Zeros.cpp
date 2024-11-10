// leetcode 2181
// merge nodes between Zeros

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data) : data(_data), next(nullptr) {}
};

Node *mergeNodes(Node *head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node *current = head;
    Node *last = current->next;
    int sum = 0;

    while(last->data != 0) {
        Node *nxt = last->next;
        sum += last->data;
        delete last;
        last = nxt;
    }

    current->data = sum;
    if(last->next == nullptr) {
        current->next = nullptr;
        delete last;
    }else {
        current->next = last;
        current = last;
    }

    mergeNodes(current);
    return head;

} 

void print(Node *head) {
    if(!head) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp  = head;
    while(temp != 0) {
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

int main() {

    Node *head = new Node(0);
    Node *one = new Node(1);
    Node *two = new Node(0);

    head->next = one;
    one->next = two;
    two->next = nullptr;

    Node *ans = mergeNodes(head);
    print(ans);

return 0;
}