class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        for(int k=0;k<n;k++){
            if(s[k]=='('){
                i++;
                j++;
            }
            else if(s[k]==')' ){
                i--;
                j--;
            }
            else if(s[k]=='*'){
                i--;
                j++;
            }
            if(j<0){
                return false;
            }
            i=max(0,i);
        }
        return i==0;
        
    }
};
