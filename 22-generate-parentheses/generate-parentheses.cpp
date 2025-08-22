class Solution {
public:
void solve(int n, int l ,int r ,string& v, vector<string>&ans){
 if(l+r == 2*n){
    ans.push_back(v);
    return;
 }
 //include l
if(l < n){ 
    v.push_back('(');
  solve(n,l+1,r,v,ans);
 v.pop_back();
}
 // include r
 if(r < l){
 v.push_back(')');
  solve(n,l,r+1,v,ans);
 v.pop_back();
 }

}
    vector<string> generateParenthesis(int n) {
    vector<string>ans;
    string v;
    solve(n,0,0,v,ans);
    return ans;
    }
};