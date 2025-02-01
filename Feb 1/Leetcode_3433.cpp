// Problem Link : https://leetcode.com/problems/count-mentions-per-user/description/

// Great problem! Seems like implementing a Discord server
// Only logic used is sorting and custom comparator function
// Simulation as per problem description
// However, understanding the problem statement is difficult, hence a medium

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        //sort events on the basis of timestamps
        //if "MESSAGE" and "OFFLINE" on same timestamp, then "OFFLINE" should come first
        //mentioned in problem description
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            return timeA == timeB ? a[0] > b[0] : timeA < timeB;
        });

        vector<int> offlineTimes(numberOfUsers, 0); //offlineTimes[i] = time(s) at which user i gets offline
        vector<int> mentions(numberOfUsers, 0);

        for(auto &event : events){
            
            if(event[0] == "MESSAGE"){
                int timestamp = stoi(event[1]);

                //collect all ids separated by whitespace
                vector<string> ids;
                stringstream s(event[2]);
                string word;
                while(s >> word){
                    ids.push_back(word);
                }

                for(string &id : ids){
                    if(id == "ALL"){ //mentions all users whether online/offline
                        for(int i = 0; i < numberOfUsers; i++){
                            mentions[i]++;
                        }
                    }
                    else if(id == "HERE"){ //mentions ONLY online users at that timestamp
                        for(int i = 0; i < numberOfUsers; i++){
                            if(offlineTimes[i] == 0 || offlineTimes[i] + 60 <= timestamp){ //offline user at time x will again be online at time x + 60
                                mentions[i]++;
                            }
                        }
                    }
                    else{
                        int userID = stoi(id.substr(2));
                        mentions[userID]++;
                    }
                }
            }
            else{ //event[0] == "OFFLINE"
                int timestamp = stoi(event[1]);
                int userID = stoi(event[2]);

                offlineTimes[userID] = timestamp;
            }
        }
        
        return mentions;
    }
};
