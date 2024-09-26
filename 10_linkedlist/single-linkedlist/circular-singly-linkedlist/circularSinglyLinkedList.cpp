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
        cout<<"node with value "<<this->data<<" created"<<endl;
    }
    ~Node() {
        cout<<"node with value "<<this->data<<" deleted"<<endl;
    }
};

void print(Node* &LAST) {
    if(LAST == nullptr) {
        cout<<"list is empty"<<endl;
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
    int count = 1;
    Node* temp = LAST->next;

    do {
        ++count;
        temp = temp->next;
    } while(temp != LAST->next);

    return count;
}

// INSERT IN EMPTY CIRCULAR LIST
void insertInEmptyList(Node* &LAST, int data) {
    if(LAST != nullptr) {
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = newNode;
    LAST = newNode;
}

// INSERT AT BEGINNING IN LIST
void insertAtBeginning(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) { // if list is empty
        newNode->next = newNode;
        LAST = newNode;
        return;
    }

    newNode->next = LAST->next;
    LAST->next = newNode;
}

// INSERT AT END IN LIST
void insertAtEnd(Node* &LAST, int data) {
    Node* newNode = new Node(data);
    
    if(LAST == nullptr) {
        newNode->next = newNode;
        LAST = newNode;
        return;
    }

    // list is non-empty
    newNode->next = LAST->next;
    LAST->next = newNode;
    LAST = newNode;
}

void insertAtPosition(Node* &LAST, int data, int position) {
    if(LAST == nullptr) {
        if(position == 1) {
            insertAtBeginning(LAST, data);
        } else {
            cout<<"invalid posiiton"<<endl;
            return;
        }
    } else {
        int len = listLength(LAST);
        
        if(position == 1) {
            insertAtBeginning(LAST, data);
        } else if(position - len == 1) {
            insertAtEnd(LAST, data);
        } else if(position - len > 1) {
            cout<<"invalid position"<<endl;
        } else {
            int posCount = 1;
            Node* previous = LAST->next;
            
            while(posCount < position-1) {
                ++posCount;
                previous = previous->next;
            }

            Node* current = previous->next;
            Node* newNode = new Node(data);
            previous->next = newNode;
            newNode->next = current;
        }
    }
}

int main() {

    Node* last = nullptr;
    insertAtPosition(last, 10, 1);



return 0;
}