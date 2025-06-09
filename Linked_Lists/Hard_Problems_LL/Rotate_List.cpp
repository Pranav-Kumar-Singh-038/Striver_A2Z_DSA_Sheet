#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    ListNode* rotateRight1(ListNode* head, int k) { // find the ll which needs to be moved to front, take its last node and connect to current head, remove the link from the new last position, handle the edge cases
        // TC: O(2*n), SC: O(1)
        // Edge cases: if head is null, if k=0 if only 1 node in ll, if required shift=0 
        if(head==NULL)
        {
            return NULL;
        }
        if(k==0 || head->next==NULL)
        {
            return head;
        }
        int length=0;
        ListNode* current=head;
        while(current!=NULL) // TC:O(n)
        {
            length++;
            current=current->next;
        }
        int shift=k%length;
        if(shift==0)
        {
            return head;
        }
        int position=length-shift-1;
        current=head;
        while(position!=0) // TC: O(n-1)
        {
            current=current->next;
            position--;
        }
        ListNode* last=current;
        ListNode* newHead=current->next;
        while(last->next!=NULL) // TC: O(n-1)
        {
            last=last->next;
        }
        current->next=NULL;
        last->next=head;
        return newHead;
    }

ListNode* rotateRight(ListNode* head, int k) 
{   // cleaner Version
        // TC: O(2n), SC:O(1)
    if (!head || !head->next || k == 0) return head;

    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k %= length;
    if (k == 0) return head;

    int stepsToNewTail = length - k;
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}



    ListNode *constructLL(vector<int> &arr)
    {
        if (arr.empty())
        {
            return NULL;
        }
        ListNode *head = new ListNode(arr[0]);
        ListNode *current = head;
        for (int i = 1; i < arr.size(); i++)
        {
            ListNode *newListNode = new ListNode(arr[i]);
            current->next = newListNode;
            current = current->next;
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
    cin >> n>>k;
    vector<int> arr(n);
    for(int &it:arr)
    {
        cin>>it;
    }

    Solution sol;
    ListNode *head = sol.constructLL(arr);
    ListNode *newHead= sol.rotateRight(head,k);
    sol.printLL(newHead);
    return 0;
}