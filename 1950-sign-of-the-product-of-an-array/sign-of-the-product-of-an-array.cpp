class Solution {
public:
    int arraySign(vector<int>& nums) {
        // long long product = nums[0] ;
        // for(int i = 1;i<nums.size();i++){
        //     product *= nums[i];
        // }
        // if(product > 0) return 1;
        // else if(product == 0) return 0;
        // else return -1;
        int c;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < 0){
                c++;
            }
            if(nums[i] == 0){
                return 0;
            }
        }
        if(c%2 == 0){
            return 1;

        }
        return -1;
    }
};