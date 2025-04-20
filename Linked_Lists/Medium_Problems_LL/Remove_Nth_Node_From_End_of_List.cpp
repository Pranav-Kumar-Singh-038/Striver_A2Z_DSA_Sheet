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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC: O(n), SC: O(1)
        ListNode* dummy = new ListNode(0); // handle edge cases like deleting head
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
    
        // Move first pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
    
        // Move both pointers together until first reaches the end
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
    
        // Remove nth node
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
    
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
    

        ListNode* removeNthFromEnd1(ListNode* head, int n) {
            // TC: O(n), SC: O(1)
            ListNode* current=head;
            int length=0;
            while(current!=NULL) // TC: O(n)
            {
                length++;
                current=current->next;
            }
            
            int index=length-n; // 0 based
            if(index==0)
            {
                return head->next;
            }
            current=head;
            while(index!=1) // TC: O(n)
            {
               current=current->next;
               index--;
            }
            ListNode* temp=current->next;
            current->next=current->next->next;
            delete temp;
            return head;

        }

        ListNode* createLL(vector<int> vec)
        {
            int n=vec.size();
            if(n==0)
            {
                return NULL;
            }
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
      ListNode* newRoot=sol.removeNthFromEnd(root,k);
      sol.printLL(newRoot);
      return 0;
}