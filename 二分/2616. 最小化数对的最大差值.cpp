/*
二分答案
因为答案与顺序无关，我们将数组排序
基于贪心，为了让差值尽可能的小，我们每次枚举相邻的两个元素即可
*/
class Solution {
public:
    bool check(vector<int>& a,int m,int u){
        int c=0;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]<=m) c++,i++;
        }
        return c>=u;
    }
    int minimizeMax(vector<int>& a, int p) {
        int n=a.size();
        sort(a.begin(),a.end());
        int l=0,r=*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
        while(l<r){
            int m=(l+r)>>1;
            if(check(a,m,p)) r=m;
            else l=m+1;
        }
        return l;
    }
};
