class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   
         /*Time Complexity: O(N)
         Space Complexity: O(K)*/
        
         deque < int > dq;
         vector < int > ans;
         for (int i = 0; i < nums.size(); i++)
         {
             
         if (!dq.empty() && dq.front() == i - k) //i-k element will be the out of bound element
             dq.pop_front();

         while (!dq.empty() && nums[dq.back()] < nums[i]) 
             dq.pop_back();

         dq.push_back(i);
         if (i >= k - 1) ans.push_back(nums[dq.front()]);
             
         }
        return ans;
    }
};