class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //Using a stack<int> (T.C : O(n))
        
        stack<int>st;
        for(auto &it : asteroids)
        {
            while(!st.empty() && st.top()>0 && it<0)
            {
                int sum = st.top() + it;
                
                if(sum>0)
                {
                    it = 0;
                }
                else if(sum<0)
                {
                    st.pop();
                }
                else  //sum = 0
                {
                    st.pop();
                    it = 0;
                }
            }
            if(it != 0)
                st.push(it);
        }
            int s = st.size();
            vector<int> result(s);
            int i = s-1;
            
            while(!st.empty())
            {
                
            result[i] = st.top();
            st.pop();
            i--;
                
           }
        
        return result;
        
    }
};