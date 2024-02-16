class Solution {
public:
    int searching(vector<int>& nums, int k)
    {
        int result = 0;
        int oddCount = 0;
        int left = 0;
        int right = 0;
        
        while(right < nums.size())
        {
            if(nums[right] % 2 != 0)
                oddCount++;
            
            while(oddCount > k)
            {
                if(nums[left] % 2 != 0) 
                    oddCount--;
                
                left++;
            }
            
            result = result + (right - left + 1);
            right++;
        }
        return result;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
      return searching(nums, k) - searching(nums, k-1);
    }
};