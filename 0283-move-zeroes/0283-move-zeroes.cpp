class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int k = 0;

       for(int i=0;i<nums.size();i++)
       {
           if(nums[i] != 0) // agar zero nahi hai to swap kar denge or agar zero hai to ignore kar denge
           {
               swap(nums[i], nums[k]);
               k++;
           }
       }
    }
};