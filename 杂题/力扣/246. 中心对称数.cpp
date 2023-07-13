/*
简单回文串应用
*/
class Solution {
public:
    bool invalid(int x){
        return x==2||x==3||x==4||x==5||x==7;
    }
    bool check(int x,int y){
        if(y<x) swap(x,y);
        return (x==1&&y==1)||(x==8&&y==8)||(x==6&&y==9)||(x==0&&y==0);
    }
    bool isStrobogrammatic(string num) {
        for(int l=0,r=num.size()-1;l<=r;l++,r--){
            if(invalid(num[l]-'0')||invalid(num[r]-'0')) return false;
            if(!check(num[l]-'0',num[r]-'0')) return false;
        }
        return true;
    }
};
