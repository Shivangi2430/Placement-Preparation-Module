class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*unordered_map<int, int>ump;
        for(int i=0;i<nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        for(auto &it : ump)
        {
            if(it.second > 1)
                return it.first;
        }
        return -1;*/
        
        int slow = nums[0];
        int fast = nums[0];
        do
        {
          slow = nums[slow];
          fast = nums[nums[fast]];
        } 
        while (slow != fast);
        
        fast = nums[0];
        
        while (slow != fast)
        {
          slow = nums[slow];
          fast = nums[fast];
        }
        return slow;
        
    }
};