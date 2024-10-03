// find kth node from end:
// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=false

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next =  nullptr;
        }

};

int getNodeUtility(Node *temp, int position, int &data) {
    if(temp == nullptr) {
        return -1;
    }

    int countPosition = getNodeUtility(temp->next, position, data);
    ++countPosition;
    if(countPosition == position) {
        data = temp->data;
    }        

    return countPosition;

}

int getNode(Node *&HEAD, int position) {
    Node *temp = HEAD;
    int data = -1;

    int x = getNodeUtility(temp, position, data);
    return data;
}

int main() {

    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);
    Node* five = new Node(5);
    Node* six = new Node(6);
    

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = nullptr;


    cout<<getNode(one, 6)<<endl;

return 0;
}