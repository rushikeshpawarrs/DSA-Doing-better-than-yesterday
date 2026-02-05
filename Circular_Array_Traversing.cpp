//out of bound %
//steps you have to traverse on array % by size of array
//11%5 = 1;
//11 indexes traverse on a 5 size array
//LC 3379
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for(int i=0; i < n; i++){
            int shift = nums[i] % n; //reducing the large shifts within 0..n-1 range
            int newidx = (i + shift) % n;

            if(newidx < 0)  newidx += n;
            result[i] = nums[newidx];
        }
        return result;
    }
};
