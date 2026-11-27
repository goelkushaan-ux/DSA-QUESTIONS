class Solution {
public:
    bool canAliceWin(int n) {
        int turn =10;
        while(n>0 && n>=turn){
            n-=turn;
            turn--;
        }
        if(turn%2==0) return false;
        return true;
    }
};