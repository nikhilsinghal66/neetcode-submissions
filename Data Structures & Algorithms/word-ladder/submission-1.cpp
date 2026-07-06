class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> set1(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        set1.erase(beginWord);
        while(!q.empty()){
            auto temp=q.front();
            int num=temp.first;
            string word=temp.second;
            q.pop();
            if(word==endWord){
                return num;
            }
            for(int i=0;i<word.size();i++){
                for(char j='a';j<='z';j++){
                    char ch=word[i];
                    word[i]=j;
                    if(set1.find(word)!=set1.end()){
                        q.push({num+1,word});
                        set1.erase(word);
                    }
                    word[i]=ch;
                }
            }
        }
        return 0;
    }
};
