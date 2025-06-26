// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        for(int i = 0; i<s.length() ; i++) {
            switch(s[i])
            {
                case 'I':
                sum+=1;
                break;
                case 'V':
                if(i-1>=0 && s[i-1]=='I')
                sum+=3;
                else
                sum+=5;
                break;
                case 'X':                
                if(i-1>=0 && s[i-1]=='I')
                sum+=8;
                else
                sum+=10;
                break;
                case 'L':
                if(i-1>=0 && s[i-1]=='X')
                sum+=30;
                else
                sum+=50;
                break;
                case 'C':
                if(i-1>=0 && s[i-1]=='X')
                sum+=80;
                else
                sum+=100;
                break;
                case 'D':
                if(i-1>=0 && s[i-1]=='C')
                sum+=300;
                else
                sum+=500;
                break;
                case 'M':
                if(i-1>=0 && s[i-1]=='C')
                sum+=800;
                else
                sum+=1000;
                break;
            }
        }
        return sum;
    }
};