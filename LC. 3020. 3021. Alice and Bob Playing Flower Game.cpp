class Solution {
//odd ka count nikalo sirf
//simple math
public:
    long long flowerGame(int n, int m) {
        return 1LL * ((n+1)/2) * (m/2) + 1LL * (n/2) * ((m+1)/2);
    }
};
