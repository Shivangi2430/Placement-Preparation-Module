//using dp memoiation

#include <bits/stdc++.h>
int f(int ind, vector<int>&dp, vector<int>&heights)
{
    if(ind == 0)
        return 0;
    if(dp[ind] != -1) 
        return dp[ind];
    int left = f(ind-1, dp, heights) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)
    right = f(ind-2, dp, heights) + abs(heights[ind] - heights[ind-2]);
    return dp[ind] = min(left, right);
} 
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
    return f(n-1, dp, heights);
}
