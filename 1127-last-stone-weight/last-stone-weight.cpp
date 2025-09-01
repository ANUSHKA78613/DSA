class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
       
        for(int i : stones){
            pq.push(i);
        }
         int n = pq.size();
        if(n == 0) return 0;
        if(n == 1) return stones[0];
        // if(n == 2) return abs(stones[1]-stones[0]);
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int d = abs(b-a); 
                pq.push(d);
            
        }
        return pq.top();
    }
};