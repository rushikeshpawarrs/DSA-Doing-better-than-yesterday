class Solution {
public:
    //3 var change ho rhe hai, isliye 3d dp hai
    //buy n sell stock 2 ko refer krna jruri hai
    //only two tranx thats why a limit var is taken
    int soldp(vector<int>& prices, int i, int buy,int limit, vector<vector<vector<int>>>& dp){
        if(i >= prices.size() || limit ==0 )  return 0;
        if(dp[i][buy][limit] != -1)    return dp[i][buy][limit];
        int profit = 0;
        if(buy){
            int bp = -prices[i] + soldp(prices, i+1, 0,limit, dp);
            int sp = soldp(prices, i+1, 1, limit, dp);
            profit = max(bp, sp);
        }
        else{
            int sp = prices[i] + soldp(prices, i+1, 1, limit-1,dp);
            int skp = soldp(prices, i+1, 0,limit, dp);
            profit = max(sp, skp);
            }
            dp[i][buy][limit] = profit;
            return dp[i][buy][limit];
        }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return soldp(prices, 0, 1, 2, dp);
    }
};
