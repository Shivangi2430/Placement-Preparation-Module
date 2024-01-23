class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

    //TC = O(N) + O(logN)
    //SC = O(N)
        
    unordered_map<int,int>mpp;
    mpp[0] = 1; // Setting 0 in the map
    int prefixSum = 0;
    int count = 0;

    for(int i=0;i<nums.size();i++){
        prefixSum += nums[i];
        int remove = prefixSum - k;
        
        // Add the number of subarrays to be removed:

        count += mpp[remove];

        // Update the count of prefix sum
        // in the map.

        mpp[prefixSum] += 1;
    }

    return count;
        
    }
};