/*
以0为锚点，每次选取元素p来询问两次query(0,a,b,c),query(p,a,b,c)来判断p和0是否相等，如此可以统计出两种元素各有多少个
*/
class Solution {
public:
    int guessMajority(ArrayReader &reader) {
        int n=reader.length();
        int cnt=0,pos=0;
        for(int i=0;i<n;i++){
            vector<int> a{0,1,2,3},b{i,1,2,3};
            if(i<=3) a[i]=4,b[i]=4;
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(reader.query(a[0],a[1],a[2],a[3])==reader.query(b[0],b[1],b[2],b[3])) cnt++;
            else pos=i;
        }
        if(cnt*2==n) return -1;
        else if(cnt*2>n) return 0;
        else return pos;
    }
};
