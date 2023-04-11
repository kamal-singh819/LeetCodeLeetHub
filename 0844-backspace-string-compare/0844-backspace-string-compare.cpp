class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "";
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] != '#') st.push(s[i]);
            else if(s[i] == '#' && (st.empty() || st.top() == '#')) st.push(s[i]);
            else if(s[i] == '#' && st.top() != '#') st.pop();
        }
        while(!st.empty()){
            if(st.top() != '#')
                str1 += st.top();
            st.pop();
        }
        
        string str2 = "";
        for(int i=0; i<t.length(); i++){
            if(t[i] != '#') st.push(t[i]);
            else if(t[i] == '#' && (st.empty() || st.top() == '#')) st.push(t[i]);
            else if(t[i] == '#' && st.top() != '#') st.pop();
        }
        while(!st.empty()){
            if(st.top() != '#')
                str2 += st.top();
            st.pop();
        }
        return str1 == str2 ? true : false;
    }
};