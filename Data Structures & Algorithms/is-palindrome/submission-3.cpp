#include <cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        for(int i=0;i<n;i++){
            s[i]=tolower(s[i]);
        }
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i< j && !isalnum(s[j])){
                j--;
            }
            if( s[i] !=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
