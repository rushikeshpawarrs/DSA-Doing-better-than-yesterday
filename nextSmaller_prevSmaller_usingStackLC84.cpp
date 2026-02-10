class Solution {
public:
    vector<int> prevSmallerElement(vector<int> input){
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());

        //left to right prev smaller
        for(int i = 0; i < input.size(); i++){
            int curr = input[i];

            //apka answer stack me
            while(st.top() != -1 && input[st.top()] >= curr){
                st.pop();
            }

            //chota element mil chuka hai -> ans store
            ans[i] = st.top();

            //push krdo curr element k index ko
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& input){
        stack<int> st;
        st.push(-1);

        vector<int> ans(input.size());

        for(int i = input.size()-1; i >= 0; i--){
            int curr = input[i];
            while(st.top() != -1 && input[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmaller(heights);
        int maxArea = INT_MIN;
        int size = heights.size();
        for(int i = 0; i < heights.size(); i++){
            int length = heights[i];
            if(next[i] == -1){
                next[i] = size;
            }
            int w = next[i] - prev[i] - 1;
            int area = length * w;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
