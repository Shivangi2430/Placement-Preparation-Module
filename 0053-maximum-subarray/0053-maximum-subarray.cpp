class Solution {
public:
    int maxSubArray(vector<int>& nums) {

// TC = O(N)
// SC = O(1)

    long long maxi = LONG_MIN; // maximum sum as minimum value
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {

        sum += nums[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;


       /* int sum = 0;
       vector<int> dummy;
       int k=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                sum = sum+nums[j];
                dummy[k]=sum;
                k++;
            }
        }
      return *max_element(dummy.begin(), dummy.end());
   */
    }
};