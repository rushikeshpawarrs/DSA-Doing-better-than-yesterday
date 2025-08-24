class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int last = -1;
        int res = 0;
        int i = 0;
        int j=0;
        while(j<nums.size()){
            if(nums[j] == 0){
                i = last + 1;
                last = j;
            }
            res = max(res, j-i);
            j++;
        }
        return res;
    }
};
