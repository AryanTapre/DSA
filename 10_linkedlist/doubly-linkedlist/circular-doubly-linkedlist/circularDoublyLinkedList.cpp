#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;

        cout<<"created node with value "<<this->data<<endl;
    }

    ~Node() {
        cout<<"deleted node with value "<<this->data<<endl;
    }



};

void print(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"circular-doubly-list is empty"<<endl;
        return;
    }

    Node* HEAD = LAST->next;
    do {
        cout<<HEAD->data<<" ";
        HEAD = HEAD->next;
    }while(HEAD != LAST->next);

    cout<<endl;
}

int listLength(Node* &LAST) {
    int count = 0;
    Node* HEAD = LAST->next;

    do {
        ++count;
        HEAD = HEAD->next;
    }while(HEAD != LAST->next);
    
    return count;

}

void insertAtBeginning(Node* &LAST, int data) {
    Node* newNode = new Node(data);

    if(LAST == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        LAST = newNode;
        return;
    }

    Node* HEAD = LAST->next;
    newNode->next = HEAD;
    HEAD->prev = newNode;

    LAST->next = newNode;
    newNode->prev = LAST; 
}


void insertAtEnd(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        LAST = newNode;
        return;
    }

    Node* HEAD = LAST->next;
    LAST->next = newNode;
    newNode->prev = LAST;
    
    newNode->next = HEAD;
    HEAD->prev = newNode;
    LAST = newNode;

}

void insertAtPosition(Node* &LAST, int data, int position) {
    if(LAST == nullptr) {
        if(position != 1) {
            cout<<"invalid position: "<<position<<endl;
            return;
        }
        insertAtBeginning(LAST, data);
    } else {
        int len = listLength(LAST);

        if(position == 1) {
            insertAtBeginning(LAST, data);
        } else if(position-len == 1) {
            insertAtEnd(LAST, data);
        } else if(position-len > 1) {
            cout<<"invalid position: "<<position<<endl;
        } else {
            int posCount = 1;
            Node* current = LAST->next;

            while(posCount < position) {
                ++posCount;
                current = current->next;
            }

            Node* previousNode = current->prev;
            Node* newNode =  new Node(data);

            current->prev = newNode;
            newNode->next = current;
            newNode->prev = previousNode;
            previousNode->next  = newNode;
        }
    }
}


void deleteAtBeginning(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    if(LAST->next == LAST) { // HANDLING SPECIAL CASE FOR SINGLE NODE IN THE LIST
        cout<<"single node"<<endl;

        LAST->next = nullptr;
        LAST->prev = nullptr;
        delete LAST;
        LAST = nullptr;
        return;
    }

    Node* oldHead = LAST->next;
    Node* newHead = oldHead->next;

    LAST->next = newHead;
    newHead->prev = LAST;
    oldHead->next = nullptr;
    oldHead->prev = nullptr;
    delete oldHead;
}

void deleteAtEnd(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    if(LAST->next == LAST) { // handling single node case..
        LAST->next = nullptr;
        LAST->prev =  nullptr;
        delete LAST;
        LAST = nullptr;
        return;
    }

    // handing multiple nodes case..
    Node* HEAD = LAST->next;
    Node* oldTail = LAST;
    Node* newTail = LAST->prev;

    newTail->next = HEAD;
    HEAD->prev = newTail;

    oldTail->next = nullptr;
    oldTail->prev = nullptr;

    delete oldTail;
    LAST = newTail;
}

void deleteAtPosition(Node* &LAST, int position) {
    if(position <= 0) {
        cout<<"position 0 does not exists"<<endl;
        return;
    }

    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    int len = listLength(LAST);

    if(position == 1) {
        deleteAtBeginning(LAST);
    } else if(position == len) {
        deleteAtEnd(LAST);
    } else if(position > len) {
        cout<<"invalid position"<<endl;
    } else  {
        int posCount = 1;
        Node* previousPointer = LAST->next;

        while(posCount < position-1) {
            ++posCount;
            previousPointer = previousPointer->next;
        }

        Node* currentPointer = previousPointer->next;
        previousPointer->next = currentPointer->next;
        currentPointer->next->prev = previousPointer;
        currentPointer->next = nullptr;
        currentPointer->prev = nullptr;
        delete currentPointer;
    }
}

int main() {
    
    Node* last = nullptr;
//     // insertAtEnd(last, 20);
//     insertAtEnd(last, 30);
//     insertAtBeginning(last, 10);
//
//     print(last);
//
//     cout<<"head->"<<last->next->data<<" "<<"last->"<<last->data<<endl;
    insertAtPosition(last, 10, 1);
    insertAtPosition(last, 20, 2);
    insertAtPosition(last, 30, 3);
    insertAtPosition(last, 310, 2);

    print(last);

    deleteAtPosition(last,4);
    deleteAtPosition(last,3);


    print(last);


return 0;
}