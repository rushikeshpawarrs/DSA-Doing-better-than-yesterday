//next smaller element using stack
//array ko piche se traverse karenge L <- R
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> input = {2,1,4,3};
    vector<int> ans(input.size());
    stack<int> st;
    st.push(-1);
    for(int i = input.size()-1; i >= 0; i--){
        int curr = input[i];

        while(st.top() >= curr){
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }
    
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i]<<" ";
    }

    return 0;
}
