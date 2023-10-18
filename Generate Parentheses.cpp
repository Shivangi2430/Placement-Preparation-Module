class Solution {
public:
    void func(vector<string>& ans, int n, int open, int close, string curr_str) {
        
        //base case
        if(curr_str.size() == 2*n) {
            ans.push_back(curr_str);
        }
            
        if(open < n) {
            func(ans, n, open + 1, close, curr_str + '(');
        }
            
        if(close < open) {
            func(ans, n, open, close + 1, curr_str + ')');
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(ans, n, 0, 0, "");
        return ans;
    }
};
