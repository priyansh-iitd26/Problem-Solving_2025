/*
Problem Link : https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09
*/

// Solved by myself!! However it took around 30 minutes and may not be the most optimal one as well

/* 
Approach 1 (by myself)
Time Complexity : O(n*logn)
Space Complexity : O(3n) ~ O(n)
*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);

        for(int i = 0; i < n; i++) diff[i] = nums[i] - i; //O(n)

        map<int, int> freqMap;

        for(int i = 0; i < n; i++) freqMap[diff[i]]++; //O(logn)

        map<int, int> foundMap;
        long long ans = 0;

        for(int i = 0; i < n; i++){ //O(n*logn)
            int curr = diff[i];

            if(freqMap[curr] == 1) 
                ans += (long long)(n - i - 1);

            else{ 
                if(foundMap.find(curr) != foundMap.end()){ 
                    long long sameElementLeft = (long long)(freqMap[curr] - foundMap[curr] - 1); 
                    ans += (long long)(n - i - 1 - sameElementLeft);
                }
                else{
                    long long toSubtract = (long long)(freqMap[curr] - 1);
                    ans += (long long)(n - i - 1 - toSubtract);
                }
            }

            foundMap[curr]++;
        }

        return ans;
    }
};

