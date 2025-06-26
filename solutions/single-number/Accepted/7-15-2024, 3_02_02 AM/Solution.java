// https://leetcode.com/problems/single-number

class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer,Integer> m = new HashMap<>();
        int singleNumber = 0;
        for(int i = 0; i < nums.length;i++) {
            if(m.get(nums[i]) == null)
                m.put(nums[i],0);
            m.put(nums[i],m.get(nums[i]) + 1);
        }
        for(Map.Entry<Integer,Integer> pair : m.entrySet()) {
            if (pair.getValue() == 1)
                return pair.getKey();
        }
        return singleNumber;
    }
}