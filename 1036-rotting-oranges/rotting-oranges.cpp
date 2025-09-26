class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // queue stores {{row, col}, time}
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m]; 
        int fresh = 0; // total fresh oranges

        // Initialize queue and visited
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        int time = 0;
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        int rotted = 0; // count of fresh oranges that got rotten

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    
                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    rotted++; // ✅ count rotted fresh orange
                }
            }
        }

        // If not all fresh got rotten
        if(rotted != fresh) return -1;
        return time;
    }
};
