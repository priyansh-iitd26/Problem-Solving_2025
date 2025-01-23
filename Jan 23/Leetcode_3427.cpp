// Problem Link : https://leetcode.com/problems/sum-of-variable-length-subarrays/description/

// Simple enough!!

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        
        int total_sum = 0;
        
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        for(int i = 0; i < n; i++){
            int start = max(0, i - nums[i]);
            int end = i;

            int curr_sum = 0;
            if(start == 0) curr_sum = prefixSum[end];
            else curr_sum = prefixSum[end] - prefixSum[start - 1];
            
            total_sum += curr_sum;
        }

        return total_sum;
    }
};
