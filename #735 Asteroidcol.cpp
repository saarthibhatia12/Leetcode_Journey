class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;++i){
            if(arr[i]>0) st.push(arr[i]);
            else{
            while(!st.empty()&&st.top()>0&&abs(arr[i])>st.top()){
                st.pop();
            }
            if(!st.empty()&&abs(arr[i])==st.top()) st.pop();
            else if(st.empty()||st.top()<0) st.push(arr[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;--i){
            ans[i]=st.top();
            st.pop();
        }
        return ans;

    }
};

// T.C.=O(2N)
// S.C=O(N)

// Approach 
// 1. We will keep adding positive values to the stack.
// 2. when we encounter a negative value we will pop the positive value if its absolute value is bigger than top element value.
// 3. if its equal then both asteroids will be destroyed and we will pop top from stack
// 4. if the stack is empty and we have only negative direction asteroids we can push it to the stack
