class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        // Step 1: Store all unique characters
        for (auto &word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }
        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i];
            string &w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            int j = 0;
            while (j < len && w1[j] == w2[j])
                j++;
            // Invalid case
            if (j == len && w1.size() > w2.size())
                return "";
            if (j < len) {
                if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
            }
        }
        // Step 3: Kahn's Algorithm
        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }
        string ans = "";
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            ans += node;
            for (char nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        // Step 4: Cycle Detection
        if (ans.size() != indegree.size())
            return "";
        return ans;
    }
};