class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    
        //TC = O(n)
        //SC = O(1)
        
      int n = nums.size();
      int left = 0;
      int right = 0;
      int len = 0;
      int temp = 0;
        
      while(right < n)
      {
          if(nums[right] != 1)
              temp++;
          
          while(temp > k)
          {
              if(nums[left] == 0)
                  temp--;
              
              left++;
          }
          
          len = max(len, right - left + 1);
          right++;
          
      }
        
    return len;
    }
};