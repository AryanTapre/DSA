// merge sort using linked list
// leetcode: 148

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data): data(_data), next(nullptr) {}
};


Node *getMid(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void insertAtEnd(Node *&head, Node *&tail, Node *current) {
    if(tail == nullptr) {
        head = current;
        tail = current;

    } else {
        tail->next =  current;
        tail = current;
    }
}

Node *merge(Node *head1, Node *head2) {
    if(head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }

    Node *left = head1;
    Node *right = head2;
    Node *ansHead = nullptr;
    Node *ansTail = nullptr;

    while(left && right) {
        if(left->data < right->data) {
            insertAtEnd(ansHead, ansTail, left);
            left=left->next;
        } else {
            insertAtEnd(ansHead, ansTail, right);
            right=right->next;
        } 
    }

    if(left) {
        ansTail->next = left;
    }    

    if(right) {
        ansTail->next = right; 
    }

    return ansHead;
}

Node *sortList(Node *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;

    left = sortList(left); // left call
    right = sortList(right); // right call

    Node * ansHead = merge(left, right);  // merge call
    return ansHead;

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
    cout<<endl;

}

int main() {

    Node *one = new Node(10);
    Node *two = new Node(1);
    Node *three = new Node(0);
    Node *four = new Node(8);
    Node *five = new Node(7);
    Node *six = new Node(1);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = nullptr;

    Node * ans = sortList(one);
    print(ans);
    

return 0;
}