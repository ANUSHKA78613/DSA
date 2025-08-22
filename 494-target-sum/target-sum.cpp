class Solution {
public:
int solve(vector<int>& nums, int target,int index,int currsum)
{
    if(index == nums.size()){
        if(currsum == target) return 1;
        else return 0;
       
    }
    //include +
    int plus = solve(nums,target,index+1,currsum+nums[index]);
    //include -
     int minus = solve(nums,target,index+1,currsum-nums[index]);
     return plus+minus;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int index = 0;
   int currsum = 0;
    return solve( nums,target,index,currsum);
    }
};