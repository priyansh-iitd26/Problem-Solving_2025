//Problem Link : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/

//Approach 1 : Simple Brute Force (as constraints allow for this)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;
        //strictly increasing
        for(int i = 0; i < n; i++){
            int currLen = 1;
            for(int j = i + 1; j < n; j++){
                if(nums[j] > nums[j - 1]){
                    currLen++;
                }
                else{
                    break;
                }
            }
            maxLen = max(maxLen, currLen);
        }

        //strictly decreasing
        for(int i = 0; i < n; i++){
            int currLen = 1;
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[j - 1]){
                    currLen++;
                }
                else{
                    break;
                }
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};

//Approach 2 : We're interested only in the length of longest strictly increasing subarray OR longest decreasing subarray
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int st_incr = 1, st_decr = 1;
        int maxLen = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                st_incr++;
                maxLen = max(maxLen, st_incr); //keeping track of the maximum length 
                st_decr = 1; //reset
            }
            else if(nums[i] < nums[i - 1]){
                st_incr = 1; //reset
                st_decr++;
                maxLen = max(maxLen, st_decr); //keeping track of the maximum length 
            }
            else{ //reset both if nums[i] == nums[i - 1]
                st_incr = 1;
                st_decr = 1;
            }
        }

        return maxLen;
    }
};
