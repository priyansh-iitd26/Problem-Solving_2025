/*
2429. Minimize XOR
Given two positive integers num1 and num2, find the positive integer x such that:
- x has the same number of set bits as num2, and
-  The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.
Return the integer x. The test cases are generated such that x is uniquely determined.

Example 1:
Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

Example 2:
Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 
Constraints:
1 <= num1, num2 <= 10^9
*/

// Approach 1
class Solution {
private:
    bool isSet(int &x, int bit){
        return x & (1 << bit);
    }
    void setBit(int &x, int bit){
        x |= (1 << bit);
    }
    void unsetBit(int &x, int bit){
        x &= ~(1 << bit);
    }
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBits = __builtin_popcount(num2);
        int currSetBits = __builtin_popcount(x);

        int bit = 0; //current bit position
        if(currSetBits < requiredSetBits){
            //Need to set remaining bits starting from LSB
            while(currSetBits < requiredSetBits){
                if(!isSet(x, bit)){
                    setBit(x, bit);
                    currSetBits++;
                }
                bit++;
            }
        }
        else if(currSetBits > requiredSetBits){
            //Need to unset remaining bits starting from LSB
            while(currSetBits > requiredSetBits){
                if(isSet(x, bit)){
                    unsetBit(x, bit);
                    currSetBits--;
                }
                bit++;
            }
        }

        return x;
    }
};
// T.C : O(logn) because there are 1 + logn bits in a number n
// S.C : O(1)

// Approach - 2 :
// Take x = 0 in beginning. Insert bits from MOST SIGNIFICANT POSITION.
// Insert where num1 has set bit (for cancellation after XOR)
// If after scanning requiredSetBits is not exhausted, then we'll start setting the bits from LEAST SIGNIFICANT POSITION.
class Solution {
private:
    bool isSet(int &x, int bit){
        return x & (1 << bit);
    }
    void setBit(int &x, int bit){
        x |= (1 << bit);
    }
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = __builtin_popcount(num2); //O(log(n))

        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--){
            if(isSet(num1, bit)){
                setBit(x, bit);
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++){
            if(!isSet(num1, bit)){
                setBit(x, bit);
                requiredSetBitCount--;
            }
        }

        return x;
    }
};
