class Solution {
public:
    vector<int> sumZero(int n) {
    vector<int>v;
    int sum;
    for(int i = -(n/2);i <= n/2;i++){
     if(n % 2 == 0 && i == 0){
        i++;
     }
         v.push_back(i);
        
    }

   return v;
    }
};