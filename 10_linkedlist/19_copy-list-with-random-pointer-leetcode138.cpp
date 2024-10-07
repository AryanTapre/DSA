// leetcode 138
// copy list with Random Pointer..

#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
    public:
        int val;
        Node *next;
        Node *random;

        Node(int _val): val(_val), next(nullptr), random(nullptr) {}
};

Node *copyRandomList(Node *head) {
    if(head == nullptr) return nullptr;

    unordered_map<Node*, Node*> map;
}

int main() {

return 0;
}