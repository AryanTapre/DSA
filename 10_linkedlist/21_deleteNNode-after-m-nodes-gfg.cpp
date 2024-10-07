// GFG:
// delete N nodes after M nodes of a linked list

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data) : data(_data), next(nullptr) {}
};


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


 Node* linkdelete(Node* head, int n, int m) {
        if(head == nullptr) return nullptr;
        
        Node *temp = head;
        for(int i=0; i<m-1; i++) {
            if(temp == nullptr) return head;
            temp=temp->next;
        }
        
        if(temp == nullptr) return head;
        
        Node *nthNode = temp->next;
        for(int i=0; i<n; i++) {
            if(nthNode == nullptr) break;
            Node *del = nthNode;
            nthNode=nthNode->next;
            del->next=nullptr;
            delete del;
        }
        
        
        temp->next = nthNode;
        if(nthNode == nullptr) {
            return head;
        }
        
         linkdelete(nthNode,n,m); 
         return head;
      
    }

int main() {

    Node *head = new Node(1);
    Node *two = new Node(5);
    Node *three = new Node(12);
    Node *four = new Node(9);
    Node *five = new Node(16);
    Node *six = new Node(6);
    Node *seven = new Node(13);
    Node *eight = new Node(5);
    Node *nine = new Node(9);
    Node *ten = new Node(8);
    Node *eleven = new Node(9);

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = eleven;
    eleven->next = nullptr;

    Node *ansHead = linkdelete(head,3,1);
    print(ansHead);

return 0;
}