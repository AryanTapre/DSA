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

int getNodeUtility(Node *temp, int position, int data) {

}

int getNode(Node *&HEAD, int position) {
    Node *temp = HEAD;
    int data = 0;
}

int main() {

return 0;
}