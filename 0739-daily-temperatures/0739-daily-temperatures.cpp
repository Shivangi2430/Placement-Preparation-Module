class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>nge(n,0);
        stack<int>st;
        
        for(int i = n-1; i>=0; i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop(); //pop untill we find a greater element that means st.top should be greater than ith element
            
            if(!st.empty()) //found the element
                nge[i] = st.top() - i;
            
            st.push(i);
        }
        return nge;
    }
};

    
