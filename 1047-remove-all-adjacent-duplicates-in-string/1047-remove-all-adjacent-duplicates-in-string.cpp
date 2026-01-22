class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        
        for(char ch : s){
            if(st.empty() || ch != st.top()) st.push(ch);
            else st.pop();
        }
        s = "";    //  re-initialize the string as empty
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());

        return s;
    }
};