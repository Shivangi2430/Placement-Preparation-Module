class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        int min = nums[0];
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < min)
                min = nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            result = result + nums[i] - min;
        }
        return result;
    }
};