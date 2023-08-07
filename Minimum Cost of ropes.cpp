class Solution
{
    public:
    
    long long calculate(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        
        long long result = 0;
        
        for(int i=0; i<n; i++)
            pq.push(arr[i]);
        
        while(pq.size()>1)
        {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a+b;
            result += sum;
            pq.push(sum);
            
        }
        return result;
    }
    
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {

        return calculate(arr, n);
    }
};
