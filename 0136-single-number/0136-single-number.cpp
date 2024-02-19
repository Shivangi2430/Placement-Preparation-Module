class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
      int xorr=0;
       for(int i=0;i<nums.size();i++)
       {
           xorr = xorr^nums[i]; 
       }
      return xorr;
        
        /*unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            if(it.second == 1)
                return it.first;
        }
        return -1;*/
    }
};