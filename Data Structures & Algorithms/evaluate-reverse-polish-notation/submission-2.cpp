class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="+" && tokens[i]!="-"){
                st.push(stoi(tokens[i]));
            }
            if(tokens[i]=="*" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1*temp2);
            }
            if(tokens[i]=="+" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1+temp2);
            }
            if(tokens[i]=="-" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2-temp1);
            }
            if(tokens[i]=="/" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(temp1 != 0) st.push(temp2/temp1);
            }
        }
        return st.top();
    }
};
