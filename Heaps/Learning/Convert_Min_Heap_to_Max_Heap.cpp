#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &arr, int N, int i)
    {
        // TC:O(1), SC:O(1)
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < N && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        // leaft nodes already satisfy heap property, so start from N/2-1 first parent node from back
        // heapify is heapify bottom here, what it does is, checks if a child is greater
        // than parent node, if yes swaps with greater node.
        // TC:O(n), SC:O(1)
        for (int i = N / 2 - 1; i >= 0; i--)// TC:O(n)
        {
            heapify(arr, N, i);
        }
    }

    void convertMinToMaxHeap1(vector<int> &arr, int N)
    {
        // make a new heap, and keep inserting elements of arr into it
        // and keep doing heapify up.
        // TC:O(nlogn), SC:O(n)
        vector<int> maxHeap; // SC:O(n)
        for (auto &it : arr) // TC:O(n)
        {
            maxHeap.push_back(it);
            int index = maxHeap.size() - 1;
            while (index > 0) // TC:O(logn)
            {
                int parentIndex = index / 2;
                if (maxHeap[parentIndex] < maxHeap[index])
                {
                    swap(maxHeap[parentIndex], maxHeap[index]);
                    index = parentIndex;
                }
                else
                {
                    break;
                }
            }
        }
        arr = maxHeap;
    }

    void printHeap(vector<int> &arr)
    {
        for (auto &it : arr)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &it : arr)
    {
        cin >> it;
    }

    Solution sol;
    sol.convertMinToMaxHeap(arr, n);
    sol.printHeap(arr);
    return 0;
}