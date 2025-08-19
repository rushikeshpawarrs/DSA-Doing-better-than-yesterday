class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i = 0;
        long long res = 0;
        while(i < nums.size()){
            long long count = 0;
            while( i < nums.size() && nums[i] == 0){
                count++;
                i++;
                res += count;
            } 
           i++;
        }
        return res;
    }
};
