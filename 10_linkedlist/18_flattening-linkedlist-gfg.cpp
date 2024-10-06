// GFG practce: Flattening a Linked List..

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *bottom;

        Node(int _data) : data(_data),next(nullptr), bottom(nullptr) {}
};

Node *merge(Node *a, Node *b) {
    if(a == nullptr) return b;
    if(b == nullptr) return a;

    Node *ans = nullptr;
    if(a->data < b->data) {
        ans = a;
        a->bottom = merge(a->bottom, b);
    } else {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node *flattenUtility(Node *l1, Node *l2) {
    if(l2 == nullptr) return l2;
    Node *mergeHead = merge(l1, l2);
    return flattenUtility(mergeHead, l2);
}

Node *flatten(Node *root) {
    if(root == nullptr) return root;
    return flattenUtility(root, root->next);
}

void print(Node *root) {
    if(!root) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = root;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp=temp->bottom;
    }
    cout<<endl;
}

int main() {

    Node *one = new Node(1);
    Node *two = new Node(2);
    Node *three = new Node(3);
    Node *four = new Node(8);
    Node *five = new Node(9);
    Node *six = new Node(16);

    one->bottom = two;
    two->bottom = three;
    
    four->bottom = five;

    one->next = four;
    four->next = six;
    six->next = nullptr;

    Node *ans = flatten(one);
    print(ans);

return 0;
}