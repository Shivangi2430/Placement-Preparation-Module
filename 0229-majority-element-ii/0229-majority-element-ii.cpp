class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      
        vector<int>ans;
        int count1 = 0, count2 = 0;
        int element1, element2;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(count1 == 0 && nums[i] != element2)
            {
                element1 = nums[i];
                count1 = 1;
            }
            
            else if(count2 == 0 && nums[i] != element1)
            {
                element2 = nums[i];
                count2 = 1;
            }
                
            else if(element1 == nums[i])
                count1++;
            
            else if(element2 == nums[i])
                count2++;
            
            else
            {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i ] == element1)
                count1++;
            
            if(nums[i ] == element2)
                count2++;
        }
        
        if(count1 > (nums.size()/3))
            ans.push_back(element1);
        
        if(count2 > (nums.size()/3))
            ans.push_back(element2);
         
    return ans;
        
        /* TC = O(n)
           SC = O(n)

        unordered_map<int,int>mp;  // element, frequency
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            if(it.second > n/3)
            ans.push_back(it.first);
        }

        return ans;  */
    }
};