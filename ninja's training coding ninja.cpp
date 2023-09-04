int f(int day, int last, vector<vector<int>> &points, vector<vector<int>>& dp)
{
    if(day == 0)
    {
        int maxi = 0;
        for(int task=0; task<3; task++)
        {
          if(task != last)
           maxi = max(maxi, points[0][task]);   
        }
        return maxi;
    }
    
    int maxi = 0;
    
    if(dp[day][last] != -1)
            return dp[day][last];
     
    for(int task = 0; task < 3; task++)
    {
        if(task != last)
        {

        int profit = points[day][task] + f(day - 1, task, points, dp);
        maxi = max(maxi, profit);

        }
       
    }

    return dp[day][last] = maxi;

}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}
