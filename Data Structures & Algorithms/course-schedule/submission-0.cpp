class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Indegree...
        vector<vector<int>> adjlist(numCourses);
        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            adjlist[b].push_back(a);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adjlist[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            auto temp=q.front();
            int node=temp;
            q.pop();
            ans++;
            for(auto it:adjlist[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans!=numCourses){
            return false;
        }
        return true;
    }
};
