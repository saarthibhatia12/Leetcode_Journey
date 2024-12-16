class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(st.empty()||st.top()<arr[i]){
                st.push(arr[i]);
            }
            else{
                int maxi=st.top();
                while(!st.empty()&&st.top()>arr[i]){
                    st.pop();
                }
                st.push(maxi);
            }
        }
        return st.size();
    }
};

// T.C.=O(N)
// S.C.=O(N)

// Approach:
// 1. the approach follows on pushing elements on stack untill they are in increasing order.
// 2. whenever we find a smaller element than stack top we preserve the max element of stack and pop elements from stack.
// 3. we push the max element in the stack as it can start a new chunk
// 4. we return stack size that represents number of max elements.

// Intiution:
// if a number in the array is less than any number in the previous chunks, this number cannot create a new chunk, as we cannot swap elements from different chunks to fix their relative order. We will iterate over the array and maintain a stack to represent the maximum values of the chunks created so far. As we loop over the array, we decide whether the current element (arr[i]) can start a new chunk or should merge with an existing chunk.
