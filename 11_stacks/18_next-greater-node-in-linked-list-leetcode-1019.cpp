// leetcode 1019
// next greater node in linked list

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node {
    public: 
        int val;
        Node* next;
    
        Node() {
            this->val = 0;
            this->next = nullptr;
        }

        Node(int data) {
            this->val = data;
            this->next = nullptr;
        }
};

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

vector<int> nextLargerNodes(Node *head) {
  vector<int> input;
      Node *temp = head;

      while(temp != 0) {
        input.push_back(temp->val);
        temp=temp->next;
      }

      vector<int> ans(input.size());
      stack<int> st;
      st.push(input.back());
      ans[input.size()-1] = 0;

      for(int i=input.size()-2; i>=0; i--) {
        while(!st.empty() && st.top() <= input[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = 0;
        }else {
            ans[i] = st.top();
        }
        st.push(input[i]);
      }

      return ans;  
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtBeginning(head, tail,5);
    insertAtBeginning(head, tail,3);
    insertAtBeginning(head, tail,4);
    insertAtBeginning(head, tail,8);
    insertAtBeginning(head, tail,7);
    insertAtBeginning(head, tail,1);
    insertAtBeginning(head, tail,2);


    vector<int> ans = nextLargerNodes(head);
    
    cout<<"printing the ans =>\n";
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;

    
return 0;
}