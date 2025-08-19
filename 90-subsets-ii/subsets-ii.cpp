class Solution {
public:

    void solve(vector<int>& nums,int index,vector<int>v,vector<vector<int>>&ans){
        //base case
        if(index >= nums.size()){
            ans.push_back(v);
            return;}
            // exclude
            int i = index + 1;
            while(i < nums.size() && nums[i-1] == nums[i]){
                i++;
                 
            }
           solve(nums,i,v,ans);
            //include
            int element = nums[index];
            v.push_back(element);
           solve(nums,index+1,v,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      vector<int>v; //store all pairs
     vector<vector<int>>ans;
     int index = 0;
     solve(nums,index,v,ans);
     return ans;
    }
};
