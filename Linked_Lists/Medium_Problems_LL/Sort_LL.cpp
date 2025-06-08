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
    ListNode *sortList1(ListNode *head)
    {
        // TC: O(n^2), SC: O(1)
        ListNode *targetNode = head;
        while (targetNode != NULL) // TC: O(n^2)
        {
            ListNode *current = targetNode;
            ListNode *currentSmallest = targetNode;
            int smallest = INT_MAX;
            while (current != NULL) // TC: O(n)
            {
                int currentVal = current->val;
                if (smallest > currentVal)
                {
                    smallest = currentVal;
                    currentSmallest = current;
                }
                current = current->next;
            }

            int temp = targetNode->val;
            targetNode->val = smallest;
            currentSmallest->val = temp;

            targetNode = targetNode->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) { // Used a merge sort, nothing new
        // TC: O(nlogn), SC:O(logn) (recursion stack size)
        if (!head || !head->next)
        {
                return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left, right);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
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
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    Solution sol;
    ListNode *head = sol.constructLL(vec);
    ListNode *newHead = sol.sortList(head);
    sol.printLL(newHead);
    return 0;
}