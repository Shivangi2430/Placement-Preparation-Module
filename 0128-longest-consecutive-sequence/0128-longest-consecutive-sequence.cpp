class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int last_ele = INT_MIN;
        int count = 0;
        int longest = 1;
        
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] - 1 ==  last_ele)
            {
                count++;
                last_ele = nums[i];
            }
            else if(nums[i] != last_ele)
            {
                count = 1;
                last_ele = nums[i];
            }
            longest = max(longest, count);
        }
        
        return longest;
            
    }
};