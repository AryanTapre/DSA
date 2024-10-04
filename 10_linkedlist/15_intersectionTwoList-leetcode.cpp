// leetcode: 160
// intersection of two linked list

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

Node *getIntersectionNode(Node *headA, Node *headB) {
    Node *a = headA;
    Node *b = headB;

    while(a!=nullptr && b!=nullptr) {
        if(a == b) {
            return a;
        }
        a=a->next;
        b=b->next;
    }

    if(a==nullptr && b==nullptr && a!=b) {
        return nullptr;
    }

    if(a == nullptr) {
        // headB is greater than headA
        int blen = 0;
        while(b == nullptr) {
            ++blen;
            b=b->next;
        }

        while(blen--) {
            headB=headB->next;
        }
    } else {
        // headA is greater than headB
        int alen = 0;
        while(a == nullptr) {
            ++alen;
            a=a->next;
        }

        while(alen--) {
            headA=headA->next;
        }
    }

    while(headA != headB) {
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}

int main() {

    Node *oneA = new Node(1);
    Node *twoA = new Node(2);
    
    Node *oneB = new Node(1);
    Node *twoB = new Node(2);
    Node *threeB = new Node(3);

    Node *oneC = new Node(10);
    Node *twoC = new Node(20);
    Node *threeC = new Node(30);
    
    oneA->next=twoA;
    twoA->next=oneC;
    oneC->next=twoC;
    twoC->next=threeC;

    oneB->next=twoB;
    twoB->next=threeB;
    threeB->next=oneC;

    Node* intersectionNode = getIntersectionNode(oneA, oneB);
    cout<<intersectionNode->data<<endl;





return 0;
}