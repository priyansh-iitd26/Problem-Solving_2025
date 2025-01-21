// Problem link : https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21
// Video Approach : https://www.youtube.com/watch?v=Y8VC_OnkazE

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();

        long long firstRowRemainSum = accumulate(grid[0].begin(), grid[0].end(), 0LL); //will become available for Robot2

        long long secondRowRemainSum = 0; //will become available for Robot2

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int Robot1Col = 0; Robot1Col < n; Robot1Col++){ //The column at which Robot1 comes to bottom row is the strategy of Robot1
            //Robot1 took this strategy
            firstRowRemainSum -= grid[0][Robot1Col];

            //Robot2 will try to do best after Robot1 has taken the above strategy
            long long bestForRobot2 = max(firstRowRemainSum, secondRowRemainSum);

            minimizedRobot2Sum = min(minimizedRobot2Sum, bestForRobot2); //Robot1 will choose such strategy which minimizes Robot2's sum

            secondRowRemainSum += grid[1][Robot1Col]; //will become available for Robot2 just before Robot1 changes strategy (column index of going to bottom row)
        }

        return minimizedRobot2Sum;
    }
};

//Another way to implement above
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long firstRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);

        long long option1 = firstRowSum; //points available for Robot2 on row = 0
        long long option2 = 0; //points available for Robot2 on row = 1

        long long mini = LLONG_MAX; //Robot1 optimal strategy

        for(int i = 0; i < n; i++){
            option1 -= grid[0][i];
            long long robot2Best = max(option1, option2);
            mini = min(mini, robot2Best);
            option2 += grid[1][i];    
        }

        return mini;

    }
};
