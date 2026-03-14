// memoization
#include <bits/stdc++.h>
using namespace std; // imp line

class Solution
{
public:
    int fn(int i, int target, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (wt[0] <= target)
                return dp[0][target] = val[0];
            return dp[0][target] = 0;
        }

        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int take = INT_MIN;
        if (wt[i] <= target)
        {
            take = val[i] + fn(i - 1, target - wt[i], val, wt, dp);
        }
        int notTake = 0 + fn(i - 1, target, val, wt, dp);
        return dp[i][target] = max(notTake, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        fn(n - 1, W, val, wt, dp);
        return dp[n - 1][W];
    }
};

// Tabulation
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                dp[0][i] = val[0];
            else
            {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= W; target++)
            {
                int notTake = 0 + dp[i - 1][target];
                int take = INT_MIN;
                if (wt[i] <= target)
                {
                    take = val[i] + dp[i - 1][target - wt[i]];
                }
                dp[i][target] = max(notTake, take);
            }
        }

        return dp[n - 1][W];
    }
};

// Space Optimization

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {

        int n = val.size();
        //  vector<vector<int>>dp(n , vector<int>(W+1, -1));
        vector<int> prev(W + 1, -1);
        vector<int> curr(W + 1, -1);
        for (int i = 0; i <= W; i++)
        {
            if (wt[0] <= i)
                prev[i] = val[0];
            else
            {
                prev[i] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= W; target++)
            {
                int notTake = 0 + prev[target];
                int take = INT_MIN;
                if (wt[i] <= target)
                {
                    take = val[i] + prev[target - wt[i]];
                }
                curr[target] = max(notTake, take);
            }
            prev = curr;
        }

        return prev[W];
    }
};

int main()
{

    Solution obj;

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int W = 50;

    cout << obj.knapsack(W, val, wt);

    return 0;
}