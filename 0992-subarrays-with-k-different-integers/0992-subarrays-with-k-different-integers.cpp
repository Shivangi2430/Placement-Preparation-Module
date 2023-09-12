class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int start = 0;
        int end = 0;
        int count = 0;
        map<int, int>mp;
        while(end < nums.size())
        {
            mp[nums[end]]++;
            
            while(mp.size() > k)
            {
                auto it = mp.find(nums[start]);
                it->second--;
                
                if(it->second == 0)
                    mp.erase(it);
                
                start++;
            }
            count += end - start + 1;
            end++;
        }
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmost(nums, k) - atmost(nums, k-1);
    }
};