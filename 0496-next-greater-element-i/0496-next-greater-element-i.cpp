class Solution {
public:
    
    /*Time Complexity:
    
The algorithm traverses both nums2 and nums1 once using loops, which takes O(N+M) time, where N is the length of nums2 and M is the length of nums1.

Space Complexity:

The algorithm uses an additional stack and an unordered map, each of which can store up to N elements in the worst case, resulting in O(N) extra space.
Overall, the algorithm has a linear time complexity of O(N+M) and a linear space complexity of O(N). It efficiently finds the next greater element for each value in nums1 using a stack and an unordered map.*/
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
   
        stack<int> st;
        unordered_map<int, int> ump;
        
        for(int i = nums2.size()-1; i>=0; i--)
        {
            while(!st.empty()  &&  nums2[i] >= st.top())
                st.pop(); //pop all the lesser values from the stack
            
            if(st.empty())
                ump[nums2[i]] = -1;  //if stack gets empty put -1 in ump
            
            else
                ump[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            nums1[i] = ump[nums1[i]];
        }
        
        return nums1;
        
        /*     vector<int> ans;
        
        for(int i=0;i<nums1.size();i++)
        {
            int max=-1;
            
            for(int j=0;j<nums2.size();j++)
            {
                int index=j;
                
                if(nums1[i]==nums2[j]) // Found element in nums2 that matches current element in nums1
                { 
                     while(index!=nums2.size())// Iterate through remaining elements in nums2 to find next greater element
                     {
                          if(nums2[index]>nums1[i])
                          {
                            max=nums2[index]; // Update max if we find a greater element
                            break;
                          }
                        index++;
                    }
               }
            }
            ans.push_back(max);
        }
        return ans; */
    }
};