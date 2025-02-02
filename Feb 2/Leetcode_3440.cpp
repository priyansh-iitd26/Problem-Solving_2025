//Problem Link : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

//most important line in description : Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.
//this means that the order of meetings can be changed so as to get the maximum free gap

//how to approach this?? Here just one meeting can be rescheduled!! (agar 1 ki jagah k hota then it would be super hard)
//note that in Leetcode 3439, the relative ordering was to be maintained fixed and not allowed to change
//meetings could just shift left and right without jumping to other free gap (except the free gaps besides itself)

//in this variation, one particular meeting can be jumped to other free gaps as well
//main catch : one meeting can be jumped over other gap if the free gap length >= meetingTime 

//so, we can preprocess by maintaining prefix maximum and suffix maximum over the free gaps and 2 cases arise
//case1 : we jump the meeting over other free gaps not besides itself, then the free gap created would be the sum of gaps already beside the meeting in its original position + meetingTime (since jumping over the meeting has created a new gap)
//case2 : shift the meeting (as in Leetcode 3439), the free gap created is just sum of free gaps already beside the original meeting

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        vector<int> freeGaps;
        freeGaps.push_back(startTime.front());

        for(int i = 1; i < n; i++){
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        }

        freeGaps.push_back(eventTime - endTime.back());

        vector<int> suffixMax(freeGaps.size(), 0);
        for(int i = freeGaps.size() - 2; i >= 0; i--){
            suffixMax[i] = max(suffixMax[i + 1], freeGaps[i + 1]);
        }

        vector<int> prefixMax(freeGaps.size(), 0);
        for(int i = 2; i < freeGaps.size(); i++){
            prefixMax[i] = max(prefixMax[i - 1], freeGaps[i - 2]);
        }

        int ans = INT_MIN;

        for(int i = 1; i < freeGaps.size(); i++){
            int meetingTime = endTime[i - 1] - startTime[i - 1]; //for freegap[i], the corresponding meeting is at index i - 1

            if(meetingTime <= max(prefixMax[i], suffixMax[i])){
                ans = max(ans, freeGaps[i - 1] + meetingTime + freeGaps[i]);
            }

            ans = max(ans, freeGaps[i - 1] + freeGaps[i]);
        }

        return ans;

    }
};
