#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:

    Node* reverseList(Node* head) // helper function to reverse list
    {
      Node* current=head;
      Node* prev=NULL;
      Node* next=NULL;
      while(current!=NULL)
      {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
      }
      return prev;
    }

    bool isPalindrome(Node* head) // Using floyd's for middle node and then reversing the second half, then check(note: floyd's always give midpoint either middle or later so second half is always smaller)
    {
        //TC : O(n) SC:O(1)
        if(head==NULL && head->next==NULL)
        {
            return true;
        }

        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        Node* secondHalf=reverseList(slow);

        Node* firstHalf=head;
        while(secondHalf!=NULL)
        {
         if(firstHalf->data!=secondHalf->data)
         {
            return false;
         }
         secondHalf=secondHalf->next;
         firstHalf=firstHalf->next;
        }
        return true;
    }

    bool isPalindrome2(Node* head) // Using an extra vector
    { 
        // TC: O(n), SC: O(n)
        vector<int> vec;
        Node* current=head;
        while(current!=NULL)
        {
          vec.push_back(current->data);
          current=current->next;
        }
        int start=0;
        int last=vec.size()-1;
        while(start<last)
        {
            if(vec[start]!=vec[last])
            {
                return 0;
            }
            start++;
            last--;
        }
        return 1;
    }

    Node *constructLL(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        Node *head = new Node(vec[0]);
        Node *current = head;
        for (int i = 1; i < vec.size(); i++)
        {
            Node *newNode = new Node(vec[i]);
            current->next = newNode;
            current = current->next;
        }
        return head;
    }

    void printLL(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    Solution sol;
    Node *head = sol.constructLL(vec);
    // sol.printLL(head);
    bool ans = sol.isPalindrome(head);
    cout << ans;
}