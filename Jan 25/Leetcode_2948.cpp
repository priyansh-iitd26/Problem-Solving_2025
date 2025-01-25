// Problem Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/
// GREAT PROBLEM!!!
// MIK's detailed video : https://youtu.be/_rQ4lJlI6nI?feature=shared

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); //O(n*logn)

        int groupNum = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNum;

        unordered_map<int, list<int>> groupToNum;
        groupToNum[groupNum].push_back(vec[0]); //O(1)

        for(int i = 1; i < n; i++){ //O(n)
            if(vec[i] - vec[i - 1] > limit){
                groupNum++;
            }

            numToGroup[vec[i]] = groupNum;
            groupToNum[groupNum].push_back(vec[i]); //O(1)
        }

        vector<int> result(n);
        for(int i = 0; i < n; i++){ //O(n)
            int num = nums[i];
            int group = numToGroup[num];

            result[i] = *groupToNum[group].begin(); //O(1)
            groupToNum[group].pop_front(); //O(1)
        }

        return result;
    }
};
//T.C : O(n*logn)
//S.C : O(n)
