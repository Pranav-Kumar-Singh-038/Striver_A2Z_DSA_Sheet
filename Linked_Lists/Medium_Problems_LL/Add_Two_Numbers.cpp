#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) { // loop through both lls add the nodes, make a new ll of the last digit of the sum and take the first digit as carry, then continue adding with the carry, if a list is over take them as 0, if carry remains add it as a new node at last;
        // TC: O(max(m,n)), SC:O(max(m,n))
        int value=l1->val+l2->val;
        int digit=value%10;
        int carry = value/10;
        ListNode* newHead=new ListNode(digit);
        ListNode* current=newHead;
        ListNode* current1=l1->next;
        ListNode* current2=l2->next;
        while(current1!=NULL || current2!=NULL)
        {
            int val1=current1?current1->val: 0;
            int val2=current2?current2->val: 0;
            value=val1+val2+carry;
            digit=value%10;
            carry=value/10;
            ListNode* newNode=new ListNode(digit);
            current->next=newNode;
            current=current->next;
            if (current1) current1 = current1->next;
            if (current2) current2 = current2->next;

        }
        if(carry!=0)
            {
                ListNode* newNode=new ListNode(carry);
                current->next=newNode;
                current=current->next;
            }
        return newHead;
    }

      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // cleaner code
        // TC: O(max(n,m)), SC: O(max(n,m))
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }

    ListNode *constructLL(vector<int> vec)
    {
        if (vec.empty())
        {
            return NULL;
        }
        ListNode *head = new ListNode(vec[0]);
        ListNode *current = head;

        for (int i = 1; i < vec.size(); i++)
        {
            ListNode *newNode = new ListNode(vec[i]);
            current->next = newNode;
            current = current->next;
        }
        return head;
    }

    void printLL(ListNode *head)
    {
        ListNode *current = head;
        while (current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
    }
};

int main()
{
    int n,m;
    cin >> n>>m;
    vector<int> vec1(n),vec2(m);
    for (auto &it : vec1)
    {
        cin >> it;
    }
    for(auto &it:vec2)
    {
        cin>>it;
    }
    Solution sol;
    ListNode *head1 = sol.constructLL(vec1);
    ListNode *head2 = sol.constructLL(vec2);
    ListNode *newHead = sol.addTwoNumbers(head1,head2);
    sol.printLL(newHead);
    return 0;
}