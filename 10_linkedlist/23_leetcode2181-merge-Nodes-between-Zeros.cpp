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

int main() {

    Node *

return 0;
}