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

Node *copyRandomListHelper(Node *temp, unordered_map<Node*, Node*> &map) {
    if(temp == nullptr) return nullptr;

    Node *brandNewNode = new Node(temp->val);
    map.insert(make_pair(temp, brandNewNode));
    
    brandNewNode->next = copyRandomListHelper(temp->next, map);

    unordered_map<Node*, Node*> :: iterator ite;
    ite = map.find(temp->random);
    if(ite == map.end()) { // temp->random = BULL
        brandNewNode->random = nullptr;
    }else {
        brandNewNode->random = ite->second;
    }

    return brandNewNode;

}

Node *copyRandomList(Node *head) {
    if(head == nullptr) return nullptr;

    // stores mapping of oldptr --> newptr
    unordered_map<Node*, Node*> map;
    Node *temp = head;
    return copyRandomListHelper(temp, map);
}

void print(Node *&head) {
    if(!head) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node *temp = head;
    while(temp) {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {

    Node *head = new Node(7);
    Node *two = new Node(13);
    Node *three = new Node(11);
    Node *four = new Node(10);
    Node *five = new Node(1);

    head->next = two;
    head->random = nullptr;
    two->next = three;
    two->random = head;
    three->next = four;
    three->random = five;
    four->next = five;
    four->random = three;
    five->next = nullptr;
    five->random = head;

    Node *ansHead = copyRandomList(head);
    
    print(ansHead);

return 0;
}