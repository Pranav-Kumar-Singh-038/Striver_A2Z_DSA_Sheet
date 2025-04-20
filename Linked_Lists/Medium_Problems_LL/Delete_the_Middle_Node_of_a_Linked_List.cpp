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
    ListNode* deleteMiddle(ListNode* head) { // Optimal: Tortoise and Hare
        // TC: O(n/2), SC: O(1)
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
    
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
    
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
    
        prev->next = slow->next;
        delete slow;
    
        return head;
    }
    

        ListNode* deleteMiddle1(ListNode* head) {
         // TC: O(n+n/2), SC: O(1)
         ListNode* current=head;
         int length=0;
         while(current!=NULL) // TC: O(n)
         {
            length++;
            current=current->next;
         }
         if(length==1)
         {
            return NULL;
         }
         int middleNode=length/2;
         current=head;
         while(middleNode!=1) // TC: O(n/2)
         {
            current=current->next;
            middleNode--;
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
      int n;
      cin>>n;
      vector<int> vec(n);
      for(int &element:vec)
      {
        cin>>element;
      }
    
      Solution sol;
      ListNode* root=sol.createLL(vec);
      ListNode* newRoot=sol.deleteMiddle(root);
      sol.printLL(newRoot);
      return 0;
}