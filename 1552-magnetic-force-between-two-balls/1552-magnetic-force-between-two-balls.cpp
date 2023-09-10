class Solution {
public:
    bool fn(vector<int>& position, int balls, int dist)
    {
        
    int last = position[0];
    int cntballs = 1;
    for(int i=0; i<position.size(); i++)
    {
        if(position[i] - last >= dist)
        {
            cntballs++;
            last = position[i];
        }
        if(cntballs >= balls)
            return true;
    }
    return false;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
    
    int n = position.size();
    sort(position.begin(), position.end());
    int low = 0;
    int high = position[n-1] - position[0];
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(fn(position, m, mid))
            low = mid + 1;
        else
        high = mid - 1;
    }
    return high;
        
    }
};