class Solution {
public:
int solve(int mini, int maxi){
    if(maxi == 0){
        return mini;
        
    }

    return solve(maxi,mini%maxi);
}
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
  
        for(int i : nums){
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
       
        return  solve(mini,maxi);

    }
};