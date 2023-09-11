class Solution {
public:
    
    //just like painter's partition
    
    int fun(vector<int>& nums, int maxsum)
    {
        int partitions = 1;
        long long validsum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] + validsum <= maxsum)
                validsum += nums[i];
            else
            {
                partitions++;
                validsum = nums[i];
            }
        }
        return partitions;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum += nums[i];
        int high = sum;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            int subarrays = fun(nums, mid);
            if(subarrays > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};