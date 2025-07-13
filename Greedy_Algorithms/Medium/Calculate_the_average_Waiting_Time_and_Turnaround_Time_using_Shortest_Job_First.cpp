#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int arrivalTime, burstTime, id;
    Job() {}
    Job(int arrivalTime, int burstTime, int id)
    {
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->id = id;
    }

    bool operator<(const Job &other) const // new thingy
    {
        return burstTime > other.burstTime;
    }
};

bool compare(Job a, Job b)
{
    return a.arrivalTime < b.arrivalTime;
}

class Solution
{
public:
    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n)
    {
        // The idea is, sort the jobs based on arrival time, you can also try sorting on both
        // arrival and burst time, one after next, but the problem is it may happen that some 
        // jobs arrive way after some other ones arrive, so calculation gets an error,
        // rather we move through time, whenever we get arrival time same as times,
        // we push it into the minHeap, the minHeap sorts in basis of burst Time so
        // we get the smallest execution task first, we add the time , calculate the 
        // turnaround and waiting times, add them to net turnarounds and waiting times
        // then move until heap is empty, if we never got stuff to heap, we simply move to
        // the arrival time of the first element or next.
        // TC:O(n+nlogn+nlogn)= O(nlogn), SC:O(n+k) = O(n)
        vector<Job> jobs; // SC:O(n)2logn
        for (int i = 0; i < n; i++) // TC:O(n)
        {
            jobs.emplace_back(arrivalTime[i], burstTime[i], i);
        }

        sort(jobs.begin(), jobs.end(), compare); // TC:O(nlogn)

        priority_queue<Job> minHeap; // SC:O(k), where k<=n

        int time = 0;
        int i = 0; 
        int totalTurnaroundTime = 0;
        int totalWaitingTime = 0;
        int completed = 0;

        while (completed < n) // TC:O(n)
        {
            while (i < n && jobs[i].arrivalTime <= time) // TC:O(k)
            {
                minHeap.push(jobs[i]); // TC:O(logk)
                i++;
            }

            if (!minHeap.empty()) 
            {
                Job current = minHeap.top(); // TC:O(logk)
                minHeap.pop(); // TC:O(logk)

                time += current.burstTime;
                int turnaround = time - current.arrivalTime;
                int waiting = turnaround - current.burstTime;

                totalTurnaroundTime += turnaround;
                totalWaitingTime += waiting;
                completed++;
            }
            else
            {
                time = jobs[i].arrivalTime;
            }
        }

        return {(double)totalWaitingTime / n, (double)totalTurnaroundTime / n};
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arrivalTime(n), burstTime(n);
    for (int &it : arrivalTime)
    {
        cin >> it;
    }
    for (int &it : burstTime)
    {
        cin >> it;
    }
    Solution sol;
    vector<double> ans = sol.averageTimes(arrivalTime, burstTime, n);
    for (double &it : ans)
    {
        cout << it << " ";
    }
}