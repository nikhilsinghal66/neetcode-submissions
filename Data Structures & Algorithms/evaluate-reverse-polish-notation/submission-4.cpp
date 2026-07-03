class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        int size1=0;
        while(size1<n){
            if(tokens[size1]!="*" && tokens[size1]!="+" &&
            tokens[size1]!="-" && tokens[size1]!="/"){
                st.push(stoi(tokens[size1]));
                size1++;
            }
            else{
                if(st.empty()) return 0;
                int num1=st.top();
                st.pop();
                if(st.empty()) return 0;
                int num2=st.top();
                st.pop();
                long long ans=0;
                if(tokens[size1]=="*"){
                    ans=1LL*num1*num2;
                }
                else if(tokens[size1]=="+"){
                    ans=num1+num2;
                }
                else if(tokens[size1]=="-"){
                    ans=num2-num1;
                }
                else{
                    ans=num2/num1;

                }
                st.push(ans);
                size1++;
            }
        }
        return st.top();
    }
};
