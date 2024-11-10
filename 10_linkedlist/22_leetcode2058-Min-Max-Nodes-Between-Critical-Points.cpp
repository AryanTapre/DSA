// leetcode 2058
// Find the minimum and maximum numbers of nodes between critical points

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int _data): data(_data), next(nullptr) {}
};


// TC: O(N)
vector<int> nodesBetweenCriticalPoints(Node *head) {
    vector<int> ans = {-1, -1};

    // checking for 2 nodes in the list
    if(head->next->next == nullptr) return ans;
    Node *previous = head;
    Node *current = previous->next;
    Node *nxt = current->next;

    int firstCP = -1;
    int lastCP = -1;
    int miniDistance = INT_MAX;
    int index = 1;
    while(nxt != nullptr) { 
            // checking for local  minima / maxima
        bool cp = ((current->data < previous->data && current->data < nxt->data) || 
                    (current->data > previous->data && current->data > nxt->data)) ? true: false;

        if(cp && firstCP == -1) { // first critical point found!.
            firstCP = index;
            lastCP = index;
        } else {
            miniDistance = (index-lastCP < miniDistance) ? index-lastCP : miniDistance;
            lastCP = index;
        }

        ++index;
        previous=previous->next;
        current=current->next;
        nxt=nxt->next;
    }

    if(firstCP == lastCP) { // only single critical point exists.
        return ans;
    } else {
        ans.at(0) = miniDistance;
        ans.at(1) = lastCP-firstCP;
    }
    return ans;
    
}

int main() {

    Node *head = new Node(5);
    Node *two = new Node(3);
    Node *three = new Node(1);
    Node *four = new Node(2);
    Node *five = new Node(5);
    Node *six = new Node(1);
    Node *seven = new Node(2);

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = nullptr;

    vector<int> ans = nodesBetweenCriticalPoints(head);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;


return 0;
}