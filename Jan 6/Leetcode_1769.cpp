/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'
*/

// Approach - 1 : O(n^2) approach - Brute Force - AC
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++){
            
            int cnt = 0;

            for(int j = 0; j < n; j++){
                if(j != i && boxes[j] == '1'){
                    cnt += abs(j - i);
                }
            }

            answer[i] = cnt;
        }

        return answer;
    }
};

// Approach - 2 : O(n) approach + extra space
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = (boxes[0] == '0' ? 0 : 1);

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i - 1] + (boxes[i] == '0' ? 0 : 1);
        }

        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = (boxes[n - 1] == '0' ? 0 : 1);

        for(int i = n - 2; i >= 0; i--){
            suffixSum[i] = suffixSum[i + 1] + (boxes[i] == '0' ? 0 : 1);
        }

        int sum = 0;
        vector<int> answer(n, 0);

        //moves for all leftballs to index i
        for(int i = 0; i < n; i++){
            answer[i] = sum;
            sum += prefixSum[i];
        }

        sum = 0;

        //moves for all rightballs to index i
        for(int i = n - 1; i >= 0; i--){
            answer[i] += sum;
            sum += suffixSum[i];
        }

        return answer;
    }
};

// Approach - 3 : O(n) appraoch WITHOUT Extra Space
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> answer(n, 0);

        int cumValue = 0;
        int cumValueSum = 0;

        //moves for all leftballs to index i
        for(int i = 0; i < n; i++){
            answer[i] = cumValueSum;

            cumValue += (boxes[i] == '0' ? 0 : 1);

            cumValueSum += cumValue;
        }

        cumValue = 0;
        cumValueSum = 0;

        //moves for all rightballs to index i
        for(int i = n - 1; i >= 0; i--){
            answer[i] += cumValueSum;

            cumValue += (boxes[i] == '0' ? 0 : 1);

            cumValueSum += cumValue;
        }

        return answer;
    }
};
