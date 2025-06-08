#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long data;
    Node* next;

    Node(long long x){
        this->data = x;
        this->next = NULL;
    }
};


class Solution {
  public:
Node* reverse(Node* head) { // To reverse, first find the prev, curr and next nodes, then make curr->next to be prev, update prev and curr and next
    // TC: O(n), SC: O(1)
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* addOne(Node* head) { // First reverse the ll, then iterate it, take a carry variable which decides what to add to the next node, initially it will be one, at each node add the carry, recalculate the node value if the it exceeds 10, recalculate the carry as well, if the current becomes NULL then check if carry is there, if it is then add a new node with the carry value, finally reverse the LL
    // TC: O(n), SC: O(1)
    head = reverse(head); // TC: O(n)

    Node* curr = head;
    int carry = 1;

    while (curr != nullptr && carry > 0) { // TC: O(n)
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;

        if (curr->next == nullptr && carry > 0) {
            curr->next = new Node(carry);
            carry = 0;
        }
        curr = curr->next;
    }

    return reverse(head);
}


    Node *constructLL(vector<long long> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        Node *head = new Node(vec[0]);
        Node *current = head;

        for (long long i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            current = current->next;
        }
        return head;
    }

    void printLL(Node *head)
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
  long long n;
  cin>>n;

  vector<long long> vec(n);
  for(auto &it:vec)
  {
    cin>>it;
  }

  Solution sol;
  Node* head=sol.constructLL(vec);
  Node* newHead=sol.addOne(head);
  sol.printLL(newHead);
  return 0;
}