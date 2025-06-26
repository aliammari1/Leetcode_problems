// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0,horizental = 0;
        for(int i = 0;i < moves.length();i++)
        {
            switch(moves[i])
            {
                case 'U':
                vertical++;
                break;
                case 'D':
                vertical--;
                break;
                case 'R':
                horizental++;
                break;
                case 'L':
                horizental--;
                break;
            }
        }
        return !vertical && !horizental;
    }
};