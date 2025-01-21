// Problem Link : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/
// Prerequisite : Merge Intervals Problem

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> X;
        vector<pair<int, int>> Y;

        for(auto &coordinates : rectangles){
            X.push_back({coordinates[0], coordinates[2]});
            Y.push_back({coordinates[1], coordinates[3]});
        }

        //mergeInterval logic on X-axis
        sort(X.begin(), X.end());
        vector<pair<int, int>> X_merged;

        if(X.size() > 0) X_merged.push_back({X[0].first, X[0].second});

        for(auto &interval : X){
            if(X_merged.back().second > interval.first){
                X_merged.back().second = max(X_merged.back().second, interval.second);
            }
            else{
                X_merged.push_back(interval);
            }
        }

        if(X_merged.size() >= 3) return true; //two vertical cuts can be made

        //mergeInterval logic on Y-axis
        sort(Y.begin(), Y.end());
        vector<pair<int, int>> Y_merged;

        if(Y.size() > 0) Y_merged.push_back({Y[0].first, Y[0].second});

        for(auto &interval : Y){
            if(Y_merged.back().second > interval.first){
                Y_merged.back().second = max(Y_merged.back().second, interval.second);
            }
            else{
                Y_merged.push_back(interval);
            }
        }

        if(Y_merged.size() >= 3) return true; //two horizontal cuts can be made

        return false; //cannot make two horizontal/vertical cuts
    }
};
