class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n < 2) return 0;
        int i = 0;
        int j = 1;
        int ans = INT_MIN;
        while(j < n){
            if(nums[i]<=nums[j]){
                ans = max(ans,nums[j]-nums[i]);
            }
            i++;
            j++;
        }  
        return ans;                                                                                         
    }
};