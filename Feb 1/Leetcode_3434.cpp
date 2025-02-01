//Problem Link : https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

//Great problem on Kadane's Algorithm!!!
//But what is the intuition ?

//Note that we have no restriction on the value of x, so this practically means that we can choose any subarray and add x (may be positive or negative) to all
//elements of that subarray

//We want to choose that subarray that contains the maximum number of duplicate elements so that they can be transformed into k
//But to choose subarray will take n^2 time complexity!! Then we notice the constraints and see that 1 <= nums[i] <= 50

//So, we can basically brute force on the target values to find the max subarray sum in the transformed array (see the implementation)

class Solution {
private:
    //Kadane's Algorithm Template
    long long maxSubarraySum(vector<int> arr){
        if (!arr.size()) return 0;

        long long res = arr[0];
        long long maxEnding = arr[0];

        for(int i = 1; i < arr.size(); i++){
            maxEnding = max((long long)maxEnding + arr[i], (long long)arr[i]);
            res = max(res, maxEnding);
        }
        
        return res > 0 ? res : (long long)0;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt_k = 0; //to store the count of k in nums

        for(int i = 0; i < n; i++){
            if(nums[i] == k) cnt_k++;
        }

        long long ans = cnt_k;
        long long target_freq = LLONG_MIN;

        for(int target = 1; target <= 50; target++){

            if(target != k){

                vector<int> transformed_arr = nums;

                for(int i = 0; i < n; i++){
                    if(nums[i] == target) transformed_arr[i] = 1;
                    else if(nums[i] == k) transformed_arr[i] = -1;
                    else transformed_arr[i] = 0;
                }

                target_freq = max(target_freq, maxSubarraySum(transformed_arr));
            }
        }

        return ans + target_freq;
    }
};
