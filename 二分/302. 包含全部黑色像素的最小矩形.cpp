/*
注意到黑色像素是一个连通块，且给出了一个黑色像素的坐标
因此可以二分求出所有黑色像素横纵坐标的最大/小值
*/
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n=image.size(),m=image[0].size();
        auto row_check=[&](int k){
            for(int i=0;i<m;i++) if(image[k][i]=='1') return true;
            return false;
        };
        auto col_check=[&](int k){
            for(int i=0;i<n;i++) if(image[i][k]=='1') return true;
            return false;
        };
        int left,right,top,bottom;
        int l=0,r=y;
        while(l<r){
            int mid=(l+r)>>1;
            if(col_check(mid)) r=mid;
            else l=mid+1;
        }
        left=l;
        l=y,r=m-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(col_check(mid)) l=mid;
            else r=mid-1;
        }
        right=l;
        l=0,r=x;
        while(l<r){
            int mid=(l+r)>>1;
            if(row_check(mid)) r=mid;
            else l=mid+1;
        }
        top=l;
        l=x,r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(row_check(mid)) l=mid;
            else r=mid-1;
        }
        bottom=l;
        return (right-left+1)*(bottom-top+1);
    }
};
