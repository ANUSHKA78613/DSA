class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,m=0;
        for(int r=0;r<s.length();r++){
            if(mp.find(s[r])!=mp.end()){
                    l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;
            m = max(m,r-l+1);
        }
        return m;
    }
};