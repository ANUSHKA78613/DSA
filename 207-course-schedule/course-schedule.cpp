class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);

        // build graph
        for (auto it : prerequisites) {
            int a = it[0]; // course to take
            int b = it[1]; // prerequisite
            adj[b].push_back(a); 
            in[a]++; // indegree of a increases
        }

        // queue for topo sort
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                in[it]--;
                if (in[it] == 0) q.push(it);
            }
        }

        return count == numCourses;
    }
};
