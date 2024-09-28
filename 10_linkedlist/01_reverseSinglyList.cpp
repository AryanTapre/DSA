#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void print(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"List is empty"<<endl;
        return;
    }

    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int listLength(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"can't find lenght as list is empty"<<endl;
        return 0;
    }

    int length = 0;
    Node* temp = HEAD;

    while(temp != nullptr) {
        ++length;
        temp = temp->next;
    }
    return length;
}

void insertAtBeginning(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);

    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
    } else {
        newNode->next = HEAD;
        HEAD = newNode;
    }
}

void insertAtEnd(Node* &HEAD, Node* &TAIL, int data) {
    Node* newNode = new Node(data);

    if(HEAD == nullptr) {
        HEAD = newNode;
        TAIL = newNode;
    } else {
        TAIL->next = newNode;
        TAIL = newNode;
    }
}

void insertAtPosition(Node* &HEAD, Node* &TAIL, int data, int position) {
    // ACCORDING TO 0-BASED INDEXING    
    int len = listLength(HEAD);

    if(position == 0) {
        insertAtBeginning(HEAD, TAIL, data);
        return;
    } else if (position >= len) {
        insertAtEnd(HEAD, TAIL, data);
        return;
    } else {
        int posCount = 0;
        Node* curr = HEAD;
        Node* prev;
        while(posCount < position) {
            ++posCount;
            prev = curr; 
            curr = curr->next;
        }

        Node* newNode = new Node(data);
        newNode->next = curr;
        prev->next = newNode;
    }
}


Node* reverseUtility(Node* &current, Node* &previous, Node* &head, Node* &tail) {
    if(current == nullptr) {
        head = previous;
        return head;
    }

    if(previous == nullptr) {
        tail = current;
    }
    Node* forward = current->next;
    current->next = previous;

    return reverseUtility(forward,current,head, tail);
}

Node* reverse(Node* &head, Node* &tail) {
    Node* previous = nullptr;
    Node* current = head;

    return reverseUtility(current, previous,head, tail);
}   

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtPosition(head, tail,10,1);
    insertAtPosition(head, tail,20,2);
    insertAtPosition(head, tail,30,3);
    insertAtPosition(head, tail,40,4);

    print(head);

    Node* current = head;
    Node* previous = nullptr;

    reverse(head, tail);

    print(head);


    

return 0;
}