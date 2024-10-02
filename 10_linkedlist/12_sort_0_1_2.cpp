//TODO: sort zero's, one's and Two's in the linked list

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

void print(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* temp = HEAD;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


void sort012_coutingApproach(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return;    
    }

    if(HEAD->next == nullptr) {
        return;
    }

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = HEAD;

    // couting 0's, 1's & 2's.,
    while(temp != nullptr) {
        if(temp->data == 0) {
            ++zeroCount;
        } else if(temp->data == 1) {
            ++oneCount;
        }else {
            ++twoCount;
        }

        temp = temp->next;
    }

    // overriding the nodes data with repsective counts of 0's, 1's and 2's..
    temp = HEAD;

        while(zeroCount--) {
            temp->data = 0;
            temp = temp->next;
        }

        while(oneCount--) {
            temp->data = 1;
            temp = temp->next;   
        }

        while(twoCount--) {
            temp->data = 2;
            temp = temp->next;
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

// without overriding the nodes data.
Node* sort012(Node* &HEAD) {
    if(HEAD == nullptr) {
        cout<<"list is empty"<<endl;
        return nullptr;
    }
    if(HEAD->next == nullptr) {
        return HEAD;
    }

    // creating pointers..
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = HEAD;
    Node* prev = nullptr;


    while(temp != nullptr) {
        switch (temp->data) {
        case 0:
            cout<<"zero"<<endl;
            insertAtEnd(zeroHead, zeroTail, temp->data);
            break;
        case 1:
            cout<<"one"<<endl;
            insertAtEnd(oneHead, oneTail, temp->data);
            break;
        case 2:
            cout<<"two"<<endl;
            insertAtEnd(twoHead, twoTail, temp->data);
            break;
        
        default:
            break;
        }

        temp  = temp->next;
    }

    if(zeroHead->next != nullptr) {
        if(oneHead->next != nullptr) {
            zeroTail->next = oneHead->next;
            if(twoHead->next != nullptr) {
                oneTail->next = twoHead->next;
            }
        }else if(twoHead->next != nullptr) {
            zeroTail->next = twoHead->next;
        }
        HEAD = zeroHead->next;
    }else {
        if(oneHead->next != nullptr) {
            if(twoHead->next != nullptr) {
                oneTail->next = twoHead->next;
            }
            HEAD = oneHead->next;
        }else {
            // only twoHead is available....
            HEAD = twoHead->next;

        }
    }

    zeroHead->next = nullptr;
    oneHead->next = nullptr;
    twoHead->next = nullptr;
    

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    cout<<"onetail ->"<<oneTail->data<<endl;
    cout<<"zerotail ->"<<zeroTail->data<<endl;
    cout<<"twotail ->"<<twoTail->data<<endl;
    

    return HEAD;
}



int main() {

    Node* one = new Node(0);
    Node* two = new Node(2);
    Node* three = new Node(2);
    Node* four = new Node(0);
    Node* five = new Node(2);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = nullptr;

    // sort012_coutingApproach(one);
    //print(one);
    Node* head = sort012(one);
    
    print(head);

return 0;
}