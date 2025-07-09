#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // Make a frequency hash map, we use this to continuously pop out element whose
        // frequency is most, to ensure that, we push all elements with their frequency
        // in prioriy queue, this ensures that we can modify their frequency and we can get
        // the most frequent one always, Now to implement the interval logic, we add a queue
        // this queue has a time for each task, which has been recently pushed to queue
        // when the timer reaches the queue we push the task back to priority queue for furter logic
        // TC:O(n * (log u + n)), SC:O(u)
        unordered_map<char, int> freq; // SC: O(u), where u = number of unique tasks (max 26)
        for (char ch : tasks)          // TC: O(n)
        {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq; // SC: O(u)
        for (auto &[ch, count] : freq)      // TC: O(u)
        {
            pq.push({count, ch}); // TC: O(log u) 
        }

        queue<pair<int, pair<int, char>>> cooldown; // SC: O(u)
        int time = 0;                               

        // TC (worst case): O(n * (log u + n)), since we may idle up to n time units per task
        while (!pq.empty() || !cooldown.empty()) // Loop runs for each time unit → up to O(T * n)
        {
            time++; 

            if (!pq.empty()) 
            {
                auto [cnt, ch] = pq.top(); 
                pq.pop();                  // TC: O(log u)
                cnt--;
                if (cnt > 0) 
                {
                    cooldown.push({time + n, {cnt, ch}}); 
                }
            }

            if (!cooldown.empty() && cooldown.front().first == time) 
            {
                pq.push(cooldown.front().second); // TC: O(log u)
                cooldown.pop();                   
            }
        }

        return time;
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    vector<char> tasks(k);
    for (char &it : tasks)
    {
        cin >> it;
    }

    Solution sol;
    int ans = sol.leastInterval(tasks, n);
    cout << ans;
}