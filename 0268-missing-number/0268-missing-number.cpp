class Solution {
public:
    int missingNumber(vector<int>& nums) {
      
   /*brute force 
      int n=nums.size();
    return n*(n+1)*0.5 - accumulate(nums.begin(),nums.end(),0);
    */

    //XOR

    int xor1 = 0, xor2 = 0;
    int N = nums.size();

    for (int i = 0; i < N ; i++) {

        xor1 = xor1 ^ (i + 1); //XOR up to [1...N]
        xor2 = xor2 ^ nums[i]; // XOR of array elements
       
    }
    return (xor1 ^ xor2); // the missing number
}   
};