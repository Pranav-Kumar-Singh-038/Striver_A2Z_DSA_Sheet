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
        ListNode *detectCycle(ListNode *head) {
         if(head==NULL)
         {
            return NULL;
         }
         ListNode* tortoise=head;
         ListNode* hare=head;
         while(hare->next && hare->next->next!=NULL)
         {
            tortoise=tortoise->next;
            hare=hare->next->next;
            if(hare==tortoise)
            {
                hare=head;
                while(hare!=tortoise)
                {
                    hare=hare->next;
                    tortoise=tortoise->next;
                }
                return hare;
            }
         }
         return NULL;
        }

        ListNode *detectCycle1(ListNode *head)  // traverse the ll and count the frequency of the address, if anything is found more than 1 that is the required node
        {
            // TC: O(n), SC: O(n)
          if(head==NULL)
          {
            return NULL;
          }
          unordered_map<ListNode*,int> myMap; // SC: O(n)
          ListNode* current=head;
          while(current!=NULL) // TC: O(n)
          {
            if(myMap.find(current)!=myMap.end())
            {
                return current;
            }
            myMap[current]++;
            current=current->next;
          }
          return NULL;
        }


        ListNode* createLL(vector<int> vec,int pos)
        {
            int n=vec.size();
            if(n==0)
            {
                return NULL;
            }
            ListNode* head=new ListNode(vec[0]);
            ListNode* current=head;
            ListNode* newNode,*cycleStart;
            for(int i=1;i<n;i++)
            {
                newNode=new ListNode(vec[i]);
                current->next=newNode;
                current=current->next;
                if(i==pos)
                {
                    cycleStart=newNode;
                }
            }
            if(pos==0)
            {
                current->next=head;
            }
            else if(pos>0 && pos<n)
            {
              current->next=cycleStart;
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
      ListNode* root=sol.createLL(vec,k);
      ListNode* cycleStart=sol.detectCycle(root);
      if(cycleStart==NULL)
      {
        cout<<-1;
      }
      else
      {
        cout<<cycleStart->val;
      }
      return 0;
}


