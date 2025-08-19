class Solution {
public:
set<vector<int>>s;
void  solve(vector<int>& arr,int index,int target, vector<vector<int>>&ans,vector<int>&v){
    if(index >= arr.size() || target < 0){
        return;
    } 
    if(target == 0){
        if(s.find(v) == s.end()){
           ans.push_back(v);
    
            s.insert(v);
        }
        return;
    }
    v.push_back(arr[index]);
  
    solve(arr,index+1,target-arr[index],ans,v); //single include
    solve(arr,index,target-arr[index],ans,v); //multiple include
    v.pop_back();
      solve(arr,index+1,target,ans,v); //exclude
}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(arr,0,target,ans,v);
        return ans;
    }
};