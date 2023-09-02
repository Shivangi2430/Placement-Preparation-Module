#include <bits/stdc++.h> 
int f(int ind, vector<int>&dp, vector<int>&nums)
{
    if(ind == 0)
        return nums[ind];
    if(ind < 0)
        return 0;
    if(dp[ind] != -1)
        return dp[ind];

    for (int i = 1; i < n; i++) {
        int pick = nums[ind] + dp[ind - 2];
        int notpick = 0 + dp[ind - 1];
    }
    return dp[ind] = max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n, -1);
    return f(n-1, dp, nums);
}
