// leetcode: 21
// merge two sorted linked list

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int _data): data(_data), next(nullptr) {}
};

void print(Node *&HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = HEAD;
    while(temp != nullptr ) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

void insertAtEnd(Node *&HEAD, Node *&TAIL, Node *current) {
    if(TAIL == nullptr) {
        HEAD = current;
        TAIL = current;
    }else {
        TAIL->next = current;
        TAIL = current;
    }
}

Node * mergeTwoList(Node *list1, Node *list2) {
    if(list1 == nullptr && list2 == nullptr) {
        return nullptr;
    }

    Node *l = list1;
    Node *r = list2;
    Node *ansHead = nullptr, *ansTail = nullptr;

    while(l != nullptr && r != nullptr) {
        if(l->data < r->data) {
            insertAtEnd(ansHead, ansTail, l);
            l=l->next;
        }else {
            insertAtEnd(ansHead, ansTail, r);
            r=r->next;
        }
    }


    // means l pointer is still pointing to valid node / list1 is greater than list2 in context of lengbt
    // while(l != nullptr) {
    //     insertAtEnd(ansHead, ansTail, l);
    //     l=l->next;
    // }

    // while(r != nullptr) {
    //     insertAtEnd(ansHead, ansTail, r);
    //     r=r->next;
    // }

    if(l) {
        ansTail->next = l;
    }
    if(r) {
        ansTail->next = r;
    }

    return ansHead;
}

Node *mergeRecursive(Node *list1, Node *list2) {
    if(list1 == nullptr) {
        return list2;
    }
    if(list2 == nullptr) {
        return list1;
    }

    Node *ans = nullptr;
    if(list1->data < list2->data) {
        ans = list1;
        list1->next = mergeRecursive(list1->next, list2);
    } else {
        ans = list2;
        list2->next = mergeRecursive(list1, list2->next);   
    }
    return ans;
}

int main() {

    Node *list1Head = new Node(1);
    Node *list1Two = new Node(2);
    Node *list1Three = new Node(3);

    Node *list2Head = new Node(1);
    Node *list2Two = new Node(3);
    Node *list2Three = new Node(4);

    list1Head->next = list1Two;
    list1Two->next = list1Three;
    list1Three->next = nullptr;

    list2Head->next = list2Two;
    list2Two->next = list2Three;
    list2Three->next = nullptr;    


    //Node * mergeHead = mergeTwoList(list1Head, list2Head);
    Node * ans = mergeRecursive(list1Head, list2Head);

    print(ans);


return 0;
}