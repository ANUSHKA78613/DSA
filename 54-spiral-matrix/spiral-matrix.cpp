class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int>ans;
        int srow = 0,scol = 0,erow = m-1,ecol = n-1;
        while(srow <= erow && scol <= ecol){
            //top
            for( int i = scol; i <= ecol; i++){
                ans.push_back(mat[srow][i]);
            }
            // right
            for( int j = srow+1; j <= erow; j++){
                ans.push_back(mat[j][ecol]);
            }
            //bottom
            for( int j = ecol-1; j >= scol; j--){
                if(srow == erow) { break; }
                ans.push_back(mat[erow][j]);
            }
            // left
            for( int i = erow-1; i >= srow+1; i--){
                if(scol == ecol){ break; }
                ans.push_back(mat[i][scol]);
            }
            srow++, scol++ ,erow--, ecol--;
        }
        return ans;
    }
};