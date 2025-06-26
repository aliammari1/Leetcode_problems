// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(n) && !isBadVersion(n-1))
            return n;
        unsigned long long last = n;
        unsigned long long beg = 1;
        if(isBadVersion((beg+last)/2) && !isBadVersion(((beg+last)/2)-1))
            return (beg+last)/2;
        while(beg<=last)
        {
            unsigned long long index = (last + beg) / 2;
            if(isBadVersion(index))
            last = index;
            else
            beg = index+1;
            if(isBadVersion(index) && !isBadVersion(index-1))
            return index;
        }
        return 0;
    }
};