class Solution {
    void helper(int idx,vector<vector<string>>&ans,vector<string>&ds,string s){
        if(idx==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPal(s.substr(idx,i-idx+1))){
                ds.push_back(s.substr(idx,i-idx+1));
                helper(i+1,ans,ds,s);
                ds.pop_back();
            }
        }
    }

    bool isPal(string s){
        int st=0;
        int e=s.length()-1;
        while(st<=e){
            if(s[e]!=s[st]) return false;
            st++;
            e--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        helper(0,ans,ds,s);
        return ans;
    }
};

// T.C.=O( (2^n) *k*(n/2) )
// O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

// S.C.=O(k*x)
//  k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. 
