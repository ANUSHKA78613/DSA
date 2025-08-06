class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        queue<int>q;
        for(int i = 0 ;i < n;i++){
           
                mp[s[i]]++;
        }
        for(int  j = 0; j< n;j++){
            if(mp[s[j]] == 1){
                q.push(j);
                return q.front();
            }
        }
      
        return -1;
    }
};