#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    vector<int> vec; // SC:O(n)

public:
     minHeap() {
        vec.push_back(-1);
    }

    minHeap(int capacity) {
        vec.reserve(capacity + 1);
        vec.push_back(-1);
    }
    
    int extractMinElement() // The min element is the root, store it, swap it to last position, remove last
    // position, the min element was removed from heap, and currently the last is in the index, keep swapping
    // down until the last element is in it's new correct position.
    {
        if (vec.size() <= 1)
        {
            return -1;
        }
        int minElement = vec[1];
        swap(vec[1], vec[vec.size() - 1]); // TC:O(1)
        vec.pop_back();
        int index = 1;
// The last index in the heap is vec.size() - 1  The last node that has at least a left child is the node where 2 * index < vec.size()
        while (2 * index < vec.size()) // TC:O(logn)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int smallerInd = left;

            if (right < vec.size() && vec[right] < vec[left])
            {
                smallerInd = right;
            }

            if (vec[smallerInd] < vec[index])
            {
                swap(vec[smallerInd], vec[index]);
                index = smallerInd;
            }
            else
            {
                break;
            }
        }
        return minElement;
    }

    void deleteElement(int ind) // Declare the required index as minimum,keep swappin until the minimum
    // reaches the root. Call extractMinelement which removes the min element.
    {
        vec[ind] = INT_MIN;
        while (ind > 1 && vec[ind] < vec[ind / 2]) // TC:O(logn)
        {
            swap(vec[ind], vec[ind / 2]);
            ind = ind / 2;
        }
        extractMinElement(); // TC:O(logn)
    }

    void insert(int val) // 1) insert an element in vector, then keep checking while it is bigger than its
    // parent and keep swapping up
    {
        vec.push_back(val);
        int index = vec.size() - 1;
        int parentIndex = (vec.size() - 1) / 2;
        while (parentIndex >= 1 && vec[index] < vec[parentIndex]) // TC:O(logn)
        {
            swap(vec[index], vec[parentIndex]);
            index = parentIndex;
            parentIndex = parentIndex / 2;
        }
    }

    void printHeap()
    {
        for (int i = 1; i < vec.size(); i++) // TC:O(n)
            cout << vec[i] << " ";
        cout << endl;
    }
};

int main()
{
    int queries;
    cin >> queries;
    minHeap heap;
    for (int i = 0; i < queries; i++)
    {
        int query;
        cin >> query;
        if (query == 0)
        {
            cout << heap.extractMinElement() << endl;
        }
        else if (query == 1)
        {
            int index;
            cin >> index;
            heap.deleteElement(index-1);
        }
        else
        {
            int key;
            cin >> key;
            heap.insert(key);
        }
    }

    return 0;
}