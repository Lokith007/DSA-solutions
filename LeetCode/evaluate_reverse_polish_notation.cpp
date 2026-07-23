// Evaluate Reverse Polish Notation [Medium]
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string t:tokens){
            if(t=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second+first);
            }
            else if(t=="-"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second-first);
            }
            else if(t=="*"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second*first);
            }
            else if(t=="/"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second/first);
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};