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

void deleteAtBeginning(Node* &HEAD, Node* &TAIL) {
    if(HEAD == nullptr)  {
        cout<<"List is empty"<<endl;
        return;
    }

    // handling special case of one node..
    if(listLength(HEAD) == 1) {
        Node* temp = HEAD;
        HEAD = nullptr;
        TAIL = nullptr;
        delete temp;
        return;
    }

    Node* oldHead = HEAD;
    HEAD = oldHead->next;
    oldHead->next = nullptr;
    delete oldHead;
}

void deleteAtEnd(Node* &HEAD, Node* &TAIL) {
    if(TAIL == nullptr) {
        cout<<"List is empty";
        return;
    }

    Node* T = HEAD;
    while(T->next->next != nullptr) {
        T = T->next; 
    }

    Node* oldTail = T->next;
    TAIL = T;
    TAIL->next = nullptr;
    delete oldTail;
}

void deleteAtPosition(Node* &HEAD, Node* &TAIL, int position) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    // handling special case of one node..
    if(listLength(HEAD) == 1) {
        Node* temp = HEAD;
        HEAD = nullptr;
        TAIL = nullptr;
        delete temp;
        return;
    }

    int len = listLength(HEAD);
    if(position == 1) {
        deleteAtBeginning(HEAD, TAIL);
    } else if(position == len) {
        deleteAtEnd(HEAD, TAIL);
    } else {
        int i = 1;
        Node* T = HEAD;

        while(i < position - 1) {
            ++i;
            T = T->next;
        }

        Node* nodeToDelete = T->next;
        T->next = nodeToDelete->next;
        nodeToDelete->next = nullptr;
        delete nodeToDelete;
    }
}

int main() {

    Node* HEAD = nullptr;
    Node* TAIL = nullptr;

    insertAtBeginning(HEAD, TAIL, 10);
    insertAtEnd(HEAD, TAIL, 20);
    insertAtPosition(HEAD, TAIL, 30, 1); // according to 0-based indexing

    print(HEAD);
    deleteAtPosition(HEAD,TAIL,2);
    print(HEAD);

return 0;
}