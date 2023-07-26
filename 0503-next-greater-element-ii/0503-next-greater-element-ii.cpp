class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      
        /*
        Time Complexity: O(N)
        Space Complexity: O(N)
        */
        
        int n = nums.size();
        stack<int>st;
        vector<int> v(n, -1);
        
        for(int i = 2*n - 1; i >= 0; i--)
        {
            
            while(!st.empty() && nums[i % n] >= st.top())
                st.pop();
            
            if(i < n)
            {
                if(!st.empty())
                    v[i] = st.top();
            }
            
            st.push(nums[i % n]);
            
        }
        return v;
    }
};