// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(n) && !isBadVersion(n-1))
            return n;
        int last = n;
        int beg = 1;
        if(isBadVersion((beg+last)/2) && !isBadVersion(((beg+last)/2)-1))
            return (beg+last)/2;
        while(beg<=last)
        {
            unsigned long long int index = (last + beg) / 2;
            if(isBadVersion(index))
            last = index;
            else
            beg = index + 1;
            if(last==beg)
            return index;
        }
        return 0;
    }
};