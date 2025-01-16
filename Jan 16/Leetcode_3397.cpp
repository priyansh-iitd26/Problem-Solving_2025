/*
3397. Maximum Number of Distinct Elements After Operations

You are given an integer array nums and an integer k.
You are allowed to perform the following operation on each element of the array at most once:
- Add an integer in the range [-k, k] to the element.

Return the maximum possible number of distinct elements in nums after performing the operations.

Example 1:
Input: nums = [1,2,2,3,3,4], k = 2
Output: 6
Explanation:
nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:
Input: nums = [4,4,4,4], k = 1
Output: 3
Explanation:
By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= k <= 10^9
*/

// Logic :
/*
Why array is sorted??
- The array needs to be sorted so that the lowerbound of all elements increases and our logic remains valid.
For element at the left end, we would like to make it equal to its lower bound (nums[0]-k) so that we could have more range to choose on for later elements.
If we traverse from right to left, we can set the rightmost element to the upper bound (nums[n-1]+k) owing to similar reasons.
We're playing very safe by demanding just one more element than the previous one placed.
*/

// Code :
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //For leftmost element
        //We'll traverse from left to right starting from index 1
        int demand = (nums[0] - k) + 1; //the demand for the 1st indexed element would be 1 more than the element placed at 0th index
        int distinctCount = 1; //till now 1 distinct element (at 0th index) is there

        for(int i = 1; i < n; i++){
            int lowerBound = nums[i] - k;
            int upperBound = nums[i] + k;

            if(demand >= lowerBound && demand <= upperBound){
                distinctCount++;
                demand++;
            }
            else if(demand < lowerBound){
                distinctCount++;
                demand = lowerBound + 1;
            }
            else continue; //when demand > upperBound, we need to sacrifice distinctancy at this position and distinctCount won't increase
        }

        return distinctCount;
    }
};
