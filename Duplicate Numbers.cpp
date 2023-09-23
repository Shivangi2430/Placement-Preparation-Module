class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //O(N) --> TC
        //O(1) -->SC
        
        vector<int>ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            nums[index] = -1*nums[index];
            
            if(nums[index] > 0)
                ans.push_back(index + 1);
        }
        return  ans;
    }
};
