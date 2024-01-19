class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

       // 1st approach    
       //TC = O(n)  SC = O(1) 

       int n= nums.size();
       vector<int> ans(n,0);
       int neg = 1, pos = 0;

       for(int i=0;i<n;i++){
           if(nums[i]>0)
            {
                ans[pos] = nums[i];
                pos+=2;
            }
            else if(nums[i]<0)
            {
                ans[neg] = nums[i];
                neg+=2;
            }
       }
       return ans;


// 2nd approach   TC = O(n)  SC = O(n)
/*
int n = nums.size();
        vector<int> ans, neg, pos;
        for(auto num : nums){
            if(num > 0){
                pos.push_back(num);
            }
            else if(num < 0){
                neg.push_back(num);
            }
        }
        for(int i=0; i<neg.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
*/


    }
};