class Solution {
public:
    bool checkString(string s) {
        int x=0,y=0;
        for(auto a:s){
            if(a=='b') y=1;
            else if(a=='a' && y==1) return false;
        }
        return true;
    }
};