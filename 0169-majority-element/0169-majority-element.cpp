class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
/*
TC = O(N)
SC = O(1)

 //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
*/

// SC = O(N) TC = O(NlogN) + O(N) = O(NlogN)
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
      
        for(auto x:mp)
        {
            if(x.second>n/2)
            return x.first;
        }
        return -1;
    }
};