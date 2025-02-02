//Problem Link : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

//most important line in problem description : The relative order of all the meetings should stay the same and they should remain non-overlapping.

//it is most optimal to select k consecutive meetings and shift them to one particular side (left or right)
//selecting k consecutive meetings allows for more free gaps to be added than selection of non k-consecutive meetings

//when we move k consecutive meetings, the k + 1 gaps are added and we need to maximize the free gap length between any k consecutive meetings
//try to think of an algorithm for this!!


//fixed-size sliding window on free gap length, but the window size should be k + 1 not k!!

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freeGaps; //pushing all free gaps into this array so that later we can perform sliding window onto it
        
        freeGaps.push_back(startTime[0]); //the free time before start of first meeting
        
        for(int i = 1; i < n; i++){ //free time between any two consecutive meetings also pushed
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        freeGaps.push_back(eventTime - endTime.back()); //the free time after the end of last meeting

        //sliding window template
        int gapWindow = k + 1;
        
        int i = 0, j = 0;
        long long sum = 0, maxSum = LLONG_MIN;

        while(j < freeGaps.size()){
            sum += freeGaps[j];

            if(j - i + 1 == gapWindow){
                maxSum = max(maxSum, sum);
                sum -= freeGaps[i];
                i++;
            }

            j++;
        }

        return (int)maxSum;
    }
};
