class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int area,curr = 0,width;
        int n = heights.size();
        vector<int>right(n,0);
        vector<int>left(n,0);
        // right (next smallest element for boundary)
        for(int i = n-1;i>=0;i--){
             while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
             }
             right[i] = s.empty() ? n : s.top();
                s.push(i);
        }
        while(!s.empty()){s.pop();}
         // left (prev smallest element for boundary)
        for(int i = 0;i<n;i++){
             while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
             }
             left[i] = s.empty() ? -1 : s.top();
                s.push(i);
        }
       

        for(int i = 0; i<n;i++){
            width = right[i] - left [i] - 1;
            area = heights[i] * width;
            curr = max(area,curr);
        }
        return curr;
    }
};