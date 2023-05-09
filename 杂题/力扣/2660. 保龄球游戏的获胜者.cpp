/*
模拟
*/
class Solution {
public:
    int isWinner(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<int> c,d;
        for(int i=0;i<n;i++){
            c.push_back(a[i]);
            d.push_back(b[i]);
            if(i>=1&&a[i-1]==10){
                c.back()*=2;
            }else if(i>=2&&(a[i-1]==10||a[i-2]==10)){
                c.back()*=2;
            }
            if(i>=1&&b[i-1]==10){
                d.back()*=2;
            }else if(i>=2&&(b[i-1]==10||b[i-2]==10)){
                d.back()*=2;
            }
        }
        int x=accumulate(c.begin(),c.end(),0);
        int y=accumulate(d.begin(),d.end(),0);
        if(x>y){
            return 1;
        }else if(x<y){
            return 2;
        }else{
            return 0;
        }
    }
};
