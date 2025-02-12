You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Example 1:
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
  
Example 2:
Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

------------------------------------------------------------------------------------***********************-----------------------------------------------------------------------------------------------------------
Clearly the brute force approach will give TLE

// My Approach
class Solution {
private:
    int digitSum(int num){
        int sum = 0;

        while(num){
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int, multiset<int>> sum_to_nums;

        for(int i = 0; i < n; i++){
            int sum = digitSum(nums[i]);
            sum_to_nums[sum].insert(nums[i]);
        }

        int max_sum = INT_MIN;

        for(auto it = sum_to_nums.begin(); it != sum_to_nums.end(); it++){
            if(it->second.size() == 1) continue;

            auto iter = it->second.rbegin(); //here iter is a reverse iterator on the multiset
            int curr_max = *iter;
            ++iter; //reverse iterator on ++ goes backward
            curr_max += *iter;

            max_sum = max(max_sum, curr_max);
        }

        return max_sum == INT_MIN ? -1 : max_sum;
    }
};
