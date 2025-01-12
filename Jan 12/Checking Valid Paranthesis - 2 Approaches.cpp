// To check valid paranthesis, we use Stack Approach with space complexity O(n). But, we can solve it without using any extra space, i.e. in O(1) space using left to right and right to left traversal.
// Note that this O(1) space approach works only when string has one type of open or close bracket, i.e. only one type of '(', '{' or '[' is considered as open and same for closed as well.

// Sample Code Snippet :
bool isValid(string s) {
    int n = s.length();
    
    //LtoR traversal
    int openBracketCount = 0;
    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(ch == '('){
            openBracketCount++;
        }
        else{
            openBracketCount--;
        }

        if(openBracketCount < 0){
            return false;
        }
    }
    
    //RtoL traversal
    int closedBracketCount = 0;
    for(int i = n - 1; i >= 0; i--){
        char ch = s[i];
        if(ch == ')'){
            closedBracketCount++;
        }
        else{
            closedBracketCount--;
        }

        if(closedBracketCount < 0){
            return false;
        }
    }

    return true; 
}
