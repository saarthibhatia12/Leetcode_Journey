class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>track(26,0);
        for(int i=0;i<s.length();i++){
            track[s[i]-'a']=i;
        }
        vector<bool>seen(26,false);
        stack<char>st;
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(seen[curr]) continue;
            while(!st.empty()&&st.top()>s[i]&&i<track[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);//push in stack
            seen[curr]=true;// mark seen
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// T.C.=O(2N)
// S.C.=O(N)

// Intiution:
// we have to pick the character's if it is not already visited. If, that's the case we'll try to pick these character's. We'll also make sure, the previously picked character is smaller then the current character in order to maintain lexicographically order. But, how we can check the previously picked character is best for!! And the answer is Stack!!

// Approach:
// 1. we will keep a track of last index of each char to make sure whether it is present further befor popping it out from stack.

// 2. we will take a bool seen array to keep a record whether the character is already present in the stack. if its present we will skip the char if not we will push and mark it true.

// 3. if we find a char smaller than stack top we will keep poping from the stack top(and ensure that that character is present in future using track array if its not present in future we will not pop it) and mark its seen false and push the new char and mark its seen true.

// 4. we will store final stack contents in a string and reverse it to give final answer.
