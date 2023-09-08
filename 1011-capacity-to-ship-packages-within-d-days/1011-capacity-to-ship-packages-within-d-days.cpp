class Solution {
public:
    int fun(vector<int>& weights, int capacity){
        int load = 0;
        int days = 1;
        
        for(int i=0; i<weights.size(); i++)
        {
            if(load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
                load += weights[i];
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        
        for(int i = 0; i<weights.size(); i++)
            sum += weights[i];
        
        int high = sum;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int daysrequired = fun(weights, mid);
            if(daysrequired <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};