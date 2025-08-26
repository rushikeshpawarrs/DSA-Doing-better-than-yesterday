class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int maxD = 0;
        int maxA = 0;
        for(int i=0;i<n;i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int diag = l*l + w * w;
            int area = l*w;

            if(diag > maxD){
                maxD = diag;
                maxA = area;
            }
            else if(diag == maxD){
                maxA = max(maxA, area);
            }
        }
        return maxA;
    }
};
