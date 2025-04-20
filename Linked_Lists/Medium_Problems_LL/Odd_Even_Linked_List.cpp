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
    ListNode* oddEvenList(ListNode* head) {
        // TC: O(n), SC: O(1)
      if(head==NULL)
      {
            return NULL;
      }
      ListNode* evenHead=head->next;
      ListNode* evenCurrent=evenHead;

      ListNode* oddHead=head;
      ListNode* oddCurrent=oddHead;

      while(evenCurrent!=NULL && evenCurrent->next!=NULL) // TC: O(n/2)
      {
            oddCurrent->next=oddCurrent->next->next;
            oddCurrent=oddCurrent->next;  

            evenCurrent->next=evenCurrent->next->next;
            evenCurrent=evenCurrent->next;
      }
      oddCurrent->next=evenHead;
      return oddHead;
    }

    ListNode* oddEvenList1(ListNode* head) { // traverse the ll and make 2 new lls of odd and even pos , connect the lls and return
        // TC: O(n), SC :O(n)
        if (!head || !head->next) return head;
    
        ListNode* head1 = head; // SC: O(n/2)
        ListNode* root1 = head1;
    
        ListNode* head2 = head->next; // SC :O(n/2)
        ListNode* root2 = head2; 
    
        ListNode* current = head->next->next;
        int i = 0;
    
        while (current != NULL) { // TC: O(n)
            if (i % 2 == 0) {
                root1->next = current;
                root1 = root1->next;
            } else {
                root2->next = current;
                root2 = root2->next;
            }
            current = current->next;
            i++;
        }
    
        root1->next = head2;    
        root2->next = NULL; 
    
        return head1;
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
      ListNode* newRoot=sol.oddEvenList(root);
      sol.printLL(newRoot);
      return 0;
}