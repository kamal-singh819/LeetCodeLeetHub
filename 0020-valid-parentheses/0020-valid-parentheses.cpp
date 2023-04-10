class Solution {
private:
    bool matched(char ch, char t){
        if(ch == ')' && t == '(' || ch == '}' && t == '{' || ch == ']' && t == '[')
           return true;
        else 
           return false;   
    }
public:
    bool isValid(string s) {
        int n = s.length();
        if(n == 1)
           return false;
        stack<char> st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                if (!st.empty()){
                    char topp = st.top();
                    if (matched(ch, topp))
                        st.pop();
                    else
                        return false;
                }else
                    return false;   
            }
        }    
    if (st.empty())
        return true;

    else
        return false;
        
    }
};