class Solution {
public:
    bool calculateday(vector<int>& bloomDay, int day, int m, int k)
    {
        int count = 0;
        int bouquets = 0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day)
                count++;
            else
            {
              bouquets += count/k;
              count = 0;
            }
        }
        
        bouquets += count/k;
        
        if(bouquets >= m)
            return true;
        else 
            return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        /*int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0;i<bloomDay.size();i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }*/
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1; //impossible case.
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(calculateday(bloomDay, mid, m, k))
            {
                 high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};