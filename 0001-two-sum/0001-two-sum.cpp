class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


     /* for(int i=0;i<nums.size();i++)
        {
          for(int j=i+1;j<nums.size();j++)
          {
           if(nums[i]+nums[j]==target)
           {
          
           return {i,j};
           }
          }
        }
        return {};
        */

    unordered_map<int, int>ump;
// O(nlogn)
//sc o(n)
    for(int i=0; i<nums.size(); i++)
    {
        if(ump.find(target-nums[i]) == ump.end()) //couldn't find
        {
           ump[nums[i]] = i;
        }
        else 
        {
            return {ump[target - nums[i]], i};
        }
    }
return {-1, -1};
    }
};