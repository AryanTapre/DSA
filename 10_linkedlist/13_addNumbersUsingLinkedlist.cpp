// TODO: Add numbers represented using singly linked list
#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

Node* reverseList(Node* previous, Node* current) {
    if(current == nullptr) {
        return previous;
    }

    Node* forward = current->next;
    current->next = previous;

    return reverseList(current, forward);
}

void insertAtBeginning(Node *&HEAD, int data) {
    Node *newNode = new Node(data);
    if(HEAD == nullptr) {
        HEAD = newNode;
    } else {
        newNode->next = HEAD;
        HEAD = newNode;
    }
}

Node* addList(Node* &HEAD1, Node* &HEAD2) {
    if(HEAD1 == nullptr && HEAD2 == nullptr) {
        cout<<"both the list are empty"<<endl;
        return nullptr;
    }

    Node *current = HEAD1, *previous = nullptr;
    HEAD1 = reverseList(previous, current);
    current = HEAD2;
    HEAD2 = reverseList(previous, current);

    Node *temp1 = HEAD1, *temp2 = HEAD2;
    int carry = 0;
    Node* ansHead = nullptr;

    while(temp1 != nullptr && temp2 != nullptr) {
        int firstVal = temp1->data;
        int secondVal = temp2->data;
        int sum = firstVal + secondVal + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtBeginning(ansHead, digit);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while(temp1 != nullptr) {
        int sum  = temp1->data + 0 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtBeginning(ansHead, digit);
        temp1 = temp1->next; 
    }

    while(temp2 != nullptr) {
        int sum  = temp2->data + 0 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtBeginning(ansHead, digit);
        temp2 = temp2->next; 
    }

    if(carry) {
        insertAtBeginning(ansHead, carry);
        carry = 0;
    }

    // Looking for extra zeros in the beginning of the ansHead linked list
    Node *temp  =  ansHead;
    while(temp->data == 0) {
        Node * del = temp;
        temp = temp->next;
        ansHead = temp;
        del->next = nullptr;
        delete del;
    }

    return ansHead;

}

void print(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {

    Node *head1 = new Node(0);
    Node *two = new Node(0);
    Node *three = new Node(7);
    head1->next = two;
    two->next = three;
    three->next = nullptr;

    Node *head2 = new Node(8);
    Node* head2Two = new Node(9);
    head2->next = head2Two;
    head2Two->next = nullptr;

    Node* ansHead = addList(head1, head2);

    print(ansHead);

return 0;
}