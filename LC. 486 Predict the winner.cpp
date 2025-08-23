class Solution {
public:
    int sd(vector<int>& nums, int start, int end, vector<vector<int>>& dp){
        if(start == end)    return nums[start];

        if(dp[start][end] != -1)    return dp[start][end];
        int ds = nums[start] - sd(nums, start +1, end, dp);
        int de = nums[end] - sd(nums, start, end-1, dp);
        dp[start][end] = max(ds, de);
        return dp[start][end];
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return sd(nums,0, nums.size()-1 ,dp) >= 0;;
    }
};
