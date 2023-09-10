#include<bits/stdc++.h>
bool fn(vector<int>& stalls, int cows, int dist)
{
    int last = stalls[0];
    int cntcows = 1;
    for(int i=0; i<stalls.size(); i++)
    {
        if(stalls[i] - last >= dist)
        {
            cntcows++;
            last = stalls[i];
        }
        if(cntcows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls[n-1] - stalls[0];
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(fn(stalls, k, mid))
            low = mid + 1;
        else
        high = mid - 1;
    }
    return high;
}
