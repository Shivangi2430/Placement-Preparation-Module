class Solution {
public:
    
    // TC = O(N)
    // SC = O(2N)
    
    vector<int> getNSL(vector<int>& arr, int n)  //This is just we are finding next smaller to each element to left
    {
        vector<int>result(n);
        stack<int>st;
        
        for(int i=0; i<n; i++)
        {
            
            while(!st.empty() && arr[st.top()] >= arr[i])  //equal to as to remove dublicate subarr with same min element //strictly less
                st.pop();
            
            if(st.empty()) 
                result[i] = -1;
            
            else
                result[i] = st.top();
            
            st.push(i);
        }
             
        return result;
    }
    
    vector<int> getNSR(vector<int>& arr, int n)  //This is just we are finding next smaller to each element to right
    {
        vector<int>result(n);
        stack<int>st;
        
        for(int i=n-1; i>=0; i--)
        {

            while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                st.pop();
            
            if(st.empty()) 
                result[i] = n;
            
            else
                result[i] = st.top();
             
            st.push(i);
        }
        return result;
    }
    
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> NSL = getNSL(arr, n); //Next smaller to left
        vector<int> NSR = getNSR(arr, n); //Next smaller to right
        
        long long sum = 0;
        int M = 1e9+7;
        
        for(int i=0; i<n; i++)
        {
            long long ls = i - NSL[i]; //distance to nearest smaller to left from i
            
            long long rs = NSR[i] - i; //distance to nearest smaller to right from i
            
            long long total_subarr_with_this_ele_as_min = ls * rs;
            
            long long total_ways = arr[i] * total_subarr_with_this_ele_as_min;
                                    
            sum = (sum + total_ways) % M;
        }
        return sum;
    }
};

/*
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i< arr.size(); i++)
        {
            int mini = arr[i];
            for(int j = i; j< arr.size(); j++)
            {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % 1000000007;
            }
        }
        return sum;
    }
};
*/