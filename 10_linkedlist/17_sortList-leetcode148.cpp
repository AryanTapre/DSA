// merge sort using linked list
// leetcode: 148

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data): data(_data),next(nullptr) {}
};

Node *getMid(Node *HEAD) {
    Node *slow = HEAD;
    Node *fast = HEAD->next;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


void insertAtEnd(Node *&head, Node *&tail, Node *current) {
    if(tail == nullptr) {
        head = current;
        tail = current; 
    } else {
        tail->next = current;
        tail = current;
    }
}

Node *merge(Node *head1, Node *head2) {
    if(head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }

    Node *left = head1;
    Node *right = head2;
    Node *mergeHead = nullptr, *mergeTail = nullptr;

    while(left != nullptr && right != nullptr) {
        if(left->data < right->data) {
            insertAtEnd(mergeHead, mergeTail, left);
            left=left->next;
        } else {
            insertAtEnd(mergeHead, mergeTail, right);
            right=right->next;
        }
    }

    if(left != nullptr) {
        mergeTail->next = left;
    }

    if(right != nullptr) {
        mergeTail->next = right;
    }
    
    return mergeHead;
}

Node *sortList(Node *HEAD) {
    if(HEAD == nullptr && HEAD->next == nullptr) {
        return HEAD;
    }   

    Node *mid = getMid(HEAD);
    Node *left = HEAD;
    Node *right = mid->next;
    mid->next = nullptr;

    // left
    left = sortList(left);
    // right
    right = sortList(right);

    // merge
    Node* ansHead = merge(left, right);
    return ansHead;
    
}

void print(Node *&HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node * temp = HEAD;
    while(temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main() {

    Node *one = new Node(1);
    Node *two = new Node(10);
    Node *three = new Node(9);
    Node *four = new Node(0);
    Node *five = new Node(8);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    Node * newHead = sortList(one);
  //  print(newHead);



return 0;
}