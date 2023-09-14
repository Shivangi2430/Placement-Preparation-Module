class Solution {
public:
   
    int rob(vector<int>& nums) {
         int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<nums.size(); i++)
        {
            int take = nums[i];
            if(i > 1)
                take += prev2;
            
            int not_take = 0 + prev;
            
            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }   
        return prev;
       /* if(nums.size() == 1)
            return nums[0];
        
        vector<int>temp1, temp2;
        for(int i=0; i<nums.size(); i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=nums.size() - 1)
                temp2.push_back(nums[i]);
        }
        return max(maxAdjacentSum(temp1), maxAdjacentSum(temp2));
        */
    }
};