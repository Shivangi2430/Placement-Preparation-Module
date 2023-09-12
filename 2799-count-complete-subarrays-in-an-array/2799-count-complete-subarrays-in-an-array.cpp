class Solution {
public:
    int atmost(vector<int>& nums, int k)
    {
        int start = 0;
        int end = 0;
        int count = 0;
        map<int,int>mp;
        
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
    
    int countCompleteSubarrays(vector<int>& nums) {
        map<int, int>mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int k = mp.size();
        
        return atmost(nums, k) - atmost(nums, k-1);
    }
};