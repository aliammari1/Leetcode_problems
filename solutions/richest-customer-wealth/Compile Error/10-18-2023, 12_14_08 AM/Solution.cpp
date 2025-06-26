// https://leetcode.com/problems/richest-customer-wealth

class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        for(int i = 0;i < accounts.length;i++)
        {
            int customerWealth = 0;
            for(int j = 0;j < accounts[i].length;j++)
            {
                customerWealth += accounts[i][j];
            }
            if(customerWealth > max)
                max = customerWealth;
        }
        return max;
    }
}