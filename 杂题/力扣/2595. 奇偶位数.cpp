class Solution {
public:
    vector<int> evenOddBit(int n) {
        int a=0,b=0;
        for(int i=0;i<=30;i++){
            if((n>>i)&1){
                if(i&1) a++;
                else b++;
            }
        }
        return {b,a};
    }
};
