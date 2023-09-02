#include <bits/stdc++.h>
long long int maxadjacent(vector<int>& nums)
{
    int n = nums.size();
    long long prev = nums[0];
    long long prev2 = 0;
    
    for(int i=0; i<n; i++)
    {
        long long take = nums[i];

        if(i > 1)
            take += prev2;
            
        long long nottake = 0 + prev;

        long long curr = max(take, nottake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
} 

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<int>temp1, temp2;

    if(n == 1)
        return valueInHouse[0];

    for (int i = 0; i < n; i++)
    {
      if (i != 0)
        temp1.push_back(valueInHouse[i]);
      if (i != n-1)
        temp2.push_back(valueInHouse[i]);
    }

   return max(maxadjacent(temp1), maxadjacent(temp2));
}
