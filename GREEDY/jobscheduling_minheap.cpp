vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
    int n = deadline.size();
    vector<int> ans = {0, 0};
    vector<pair<int, int>> jobs;

    // step 1: pair deadlines and profits
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // step 2: sort jobs by deadline (earlier deadlines first)
    sort(jobs.begin(), jobs.end());

    // step 3: use a min-heap to store the profit of selected jobs
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int currDeadline = jobs[i].first;
        int currProfit = jobs[i].second;

        // if we can still schedule a job before the deadline
        if (currDeadline > pq.size()) {
            pq.push(currProfit);
        }
        // if no slot left, replace the job with lowest profit
        else if (!pq.empty() && pq.top() < currProfit) {
            pq.pop();
            pq.push(currProfit);
        }
    }

    // step 4: extract total profit and job count
    while (!pq.empty()) {
        ans[1] += pq.top(); // total profit
        pq.pop();
        ans[0]++;           // job count
    }

    return ans;
}
