// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto it : nums2)
            nums1.push_back(it);
        int size = nums1.size() - 1;
        sort(nums1.begin(),nums1.end());
        if(size % 2 != 0)
            return static_cast<double>((nums1[(size/2) + 1] + nums1[size/2])) / 2;
        return nums1[size/2];
    }
};