class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
        return false;
        }
        int s =10;
        int c = 0;
        while(n >= s){
            n = n - s;
            c++;
            s--;
        }
       if( c % 2 == 1){
        return true;
       }
       return false;
    }
};