#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
   ListNode* next;
   int val;
   ListNode(int val)
   {
     this->next=NULL;
     this->val=val;
   }
};

class Solution {
    public:
        void deleteNode(ListNode* node) { // This is optimal, we copy the value of next node to the node to be deleted, and change the next pointer to point to next->next
          // TC: O(1), SC: O(1)
          node->val = node->next->val;
          node->next = node->next->next;
        }

        void deleteNode1(ListNode* node) { // Shift the values one step left, delete the last node, also keep prev variable so that last second node now points to NULL
            // TC: O(n), SC: O(1)
            ListNode* current=node;
            ListNode* prev;
            while(current->next!=NULL) // TC: O(n)
            {
               current->val=current->next->val;
               prev=current;
               current=current->next;
            }
            prev->next=NULL;
            delete current;   // delete the object
            current = nullptr; // good practice to avoid dangling pointer as now deleting a nullptr will not cause undefined behavior as it was already deleted
        }

        ListNode* createLL(vector<int> vec)
        {
            int n=vec.size();
            ListNode* head=new ListNode(vec[0]);
            ListNode* current=head;
            ListNode* newNode;
            for(int i=1;i<n;i++)
            {
                newNode=new ListNode(vec[i]);
                current->next=newNode;
                current=current->next;
            }
            return head;
        }

        void printLL(ListNode* head)
        {
            ListNode* current=head;
            while(current!=NULL)
            {
                cout<<current->val<<" ";
                current=current->next;
            }
        }

        ListNode* findNode(ListNode* head, int k)
        {
            ListNode* current=head;
            while(current!=NULL)
            {
                if(current->val==k)
                {
                    return current;
                }
                current=current->next;
            }
        }
};

int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> vec(n);
  for(int &element:vec)
  {
    cin>>element;
  }

  Solution sol;
  ListNode* root=sol.createLL(vec);
  ListNode* nodeToDelete=sol.findNode(root,k);
  sol.deleteNode(nodeToDelete);
  sol.printLL(root);
  return 0;
}
