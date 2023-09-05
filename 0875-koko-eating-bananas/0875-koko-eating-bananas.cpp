class Solution {
public:
long long count_banana(vector<int> &v,int num)
{
    long long sum=0;
    for(int i=0; i<v.size(); i++)
    {
        sum+=ceil((double)v[i]/(double)num);
    }
    return sum;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1;
       int high=*max_element(piles.begin(),piles.end());
       while(low<=high)
       {
           int mid=low + (high - low)/2;
           long long totalhr = count_banana(piles,mid);
           
           if(totalhr<=h)
               high=mid-1;
           
           else
               low=mid+1;         
       } 
       return low;
    }
};