class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     /*   int last_ele = INT_MIN;
        int count = 0;
        int longest = 1;
        
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] - 1 ==  last_ele)
            {
                count++;
                last_ele = nums[i];
            }
            else if(nums[i] != last_ele)
            {
                count = 1;
                last_ele = nums[i];
            }
            longest = max(longest, count);
        }
        
        return longest;
            
    }
};
*/
    int n = nums.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }
    //set stores only unique element
    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number: the previous element should not be in the set
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
};