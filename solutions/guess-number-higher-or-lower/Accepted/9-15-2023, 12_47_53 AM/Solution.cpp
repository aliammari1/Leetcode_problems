// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1,left = 1,right = n,number = 0;
        while(left <= right)
        {
            i = left + (right - left) / 2;
            number = guess(i);
            if (number == 0)
                return i;
            else if(number == -1)
                right = i - 1;
            else if(number == 1)
                left = i + 1;
        }
        return -1;
    }
};