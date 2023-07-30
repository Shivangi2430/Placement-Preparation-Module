class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>st;
        string res = "";
        
         if(num.length() <= k)   
            return "0";
        
         if(k == 0)
            return num;
        
        
        for(char &c : num)
        {
            while(!st.empty() && st.top() > c && k > 0)
            {
                st.pop();
                k--;
            }
        
         // as leading zeroes are to be avoided skip pushing to stack
         if(st.empty()&& c == '0')
             continue;
            
         st.push(c);
            
         }
    
        // after iterating if some k is still not 0 we can pop from back. 456 case
         while(k-- && !st.empty())
           st.pop();
        
         while(!st.empty())
         {
            res += st.top();
            st.pop();
         }
        
    reverse(res.begin(),res.end());

    return res == "" ? "0" : res;

    }
};   
  


