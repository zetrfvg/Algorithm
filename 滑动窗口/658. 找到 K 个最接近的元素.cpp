/*
排序后滑动窗口枚举最小合法区间即可
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int cur=0,pos,cost=1e9;
        for(int l=0,r=0;r<n;r++){
            cur+=abs(x-arr[r]);
            if(r>=k-1){
                if(cur<cost){
                    cost=cur;
                    pos=l;
                }
                cur-=abs(x-arr[l++]);
            }
        }
        vector<int> ans(k);
        for(int i=0;i<k;i++,pos++){
            ans[i]=arr[pos];
        }
        return ans;
    }
};
