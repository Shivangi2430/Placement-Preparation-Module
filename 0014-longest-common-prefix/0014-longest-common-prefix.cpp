class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        string ans = "";
        int n = strs.size();
       
        for(int i = 0; i < strs[0].length(); i++) //first string 
        {
            bool match = true;
            
            //first string ke har character ko ab compare krayenge remaining string se
            char ch = strs[0][i];  // first char of 0th stirng = f
            
            for(int j=1; j<n; j++)
            {
                // 2nd and 3rd string ke first char se compare krenge 'f' ko 
               if(strs[j].size() < i || ch != strs[j][i]) //jthe string ka ith character
               {
                 match = false;
                 break;
               }
                
            }
            
            if(match == false)
            break;
            
            else
            ans.push_back(ch);
            
        }
        
        return ans;
    }
};