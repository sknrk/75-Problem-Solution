// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int left=0,right=1;left<prices.size()-1 && right<prices.size();){
            int profit = prices[right]-prices[left];
            if(profit > max_profit){
                max_profit = profit;
                right++;
                continue;
            }
            if(profit<=0){
                left = right;
                right++;
            }
            else{
                right++;
            }
        }
        return max_profit;
    }
};

// I used left and right pointer for calculating maximum profit. O(n) is the time complexity of solution.