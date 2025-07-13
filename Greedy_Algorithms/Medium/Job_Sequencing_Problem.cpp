#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int id;
    int deadline;
    int profit;
    Job() {}
    Job(int id, int deadline, int profit)
    {
        this->deadline = deadline;
        this->profit = profit;
        this->id = id;
    }
    //   static bool compare(Job jobA,Job jobB) // same work
    //   {
    //      return jobA.profit>jobB.profit;
    //   }
};

class DSU // haven't understood yet, will do later
{
public:
    vector<int> parent;

    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Find the latest available slot
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
    }

    // Merge this slot with the previous slot
    void merge(int u, int v)
    {
        parent[u] = v;
    }
};

bool compare(Job jobA, Job jobB)
{
    // Return true if you want the first argument to come earlier in the sorted result.
    return jobA.profit > jobB.profit;
}

class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        // this is the dsu based approach, it is  similar to the boolean array approach
        // the difference is that dsu give near constant time to find next open date in schedule
        // so the complexity decreases drastically
        // TC:O(3n+nlogn), SC:O(n)
        int n = deadline.size();
        int maxDeadline = *max_element(deadline.begin(), deadline.end()); // TC:O(n)

        vector<Job> jobs; // SC:O(n)
        for (int i = 0; i < n; i++) // TC:O(n)
        {
            jobs.emplace_back(i, deadline[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end(), compare); // TC:O(nlogn)

        DSU dsu(maxDeadline);

        int totalProfit = 0, jobsDone = 0;

        for (Job &job : jobs) // TC:O(n)
        {
            int availableSlot = dsu.find(job.deadline); 

            if (availableSlot > 0)
            {
                dsu.merge(availableSlot, dsu.find(availableSlot - 1));
                totalProfit += job.profit;
                jobsDone++;
            }
        }

        return {jobsDone, totalProfit};
    }
    vector<int> jobSequencing2(vector<int> &deadline, vector<int> &profit)
    {
        // this is the minheap approach, we make pairs of jobs and sort them based on deadline
        // so now the earliest jobs are front, we take a minheap it represents are capacity
        // like how many days ahead are we, we traverse the jobs, naturally we push the
        // starting jobs in the heap, and at some point the minheap get full, i.e more than
        // the deadline of the next job, now since this minheap takes profit, we have the
        // lowest profit job at top, if the next job is more profitable than this, we pop the top
        // and push that, this goes on for all jobs are checked.
        // TC:O(5nlogn), SC:O(2n)
        int n = deadline.size();
        vector<int> ans = {0, 0};

        vector<pair<int, int>> jobs; // SC:O(n)
        for (int i = 0; i < n; i++) // TC:O(n)
        {
            jobs.push_back({deadline[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end()); // TC:O(nlogn)

        priority_queue<int, vector<int>, greater<int>> minHeap; // SC:O(n)

        for (auto &job : jobs) // TC:O(n)
        {

            // if job can be scheduled within its deadline
            if (job.first > minHeap.size())
            {
                minHeap.push(job.second); // TC:O(logn)
            }

            // Replace the job with the lowest profit
            else if (!minHeap.empty() && minHeap.top() < job.second)
            {
                minHeap.pop(); // TC:O(logn)
                minHeap.push(job.second); // TC:O(logn)
            }
        }

        while (!minHeap.empty()) // TC:O(n)
        {
            ans[1] += minHeap.top();
            minHeap.pop(); // TC:O(logn)
            ans[0]++;
        }

        return ans;
    }

    vector<int> jobSequencing2(vector<int> &deadline, vector<int> &profit)
    {
        // The idea is, we need to do maximum profit jobs first, and do the jobs at the last
        // deadline to maximize profit because doing at deadline leaves space to do the job at
        // earlier days, so we make a jobs array, sort them in descending order, make a
        // boolean array of days, which denotes what day is free, now loop the jobs array
        // find the day in the schedule is free or not, if not find if any earlier date is free
        // if yes do it add profit, if not move to the next job.
        // TC:O(2n+nlogn+n*maxDeadline) = O(n*maxDeadline)=O(n^2)(our case), SC:O(n+maxDeadline) =O(n)(our case )
        int n = deadline.size();
        int totalProfit = 0, profitCount = 0;
        vector<Job> jobs;                         // SC:O(n)
        for (int i = 0; i < deadline.size(); i++) // TC:O(n)
        {
            jobs.emplace_back(Job(i, deadline[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), compare);                          // TC:O(nlogn)
        int maxDeadline = *max_element(deadline.begin(), deadline.end()); // TC:O(n)
        vector<bool> scheduleEmpty(maxDeadline, true);                    // SC:O(maxDeadline)
        for (int i = 0; i < n; i++)                                       // TC:O(n)
        {
            Job job = jobs[i];
            int profit = job.profit;
            int deadline = job.deadline - 1;
            while (deadline >= 0 && !scheduleEmpty[deadline]) // TC:O(maxDeadline)
            {
                deadline--;
            }
            if (deadline >= 0)
            {
                scheduleEmpty[deadline] = false;
                totalProfit += profit;
                profitCount++;
            }
        }
        return {profitCount, totalProfit};
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> deadline(n), profit(n);
    for (int &it : deadline)
    {
        cin >> it;
    }
    for (int &it : profit)
    {
        cin >> it;
    }
    Solution sol;
    vector<int> ans = sol.jobSequencing(deadline, profit);
    for (int &it : ans)
    {
        cout << it << " ";
    }
}