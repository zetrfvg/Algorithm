/*
对于所有点，分别求出其左右两端的最长连续递减的序列长度
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int> l(n),r(n),valid(n);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) l[i]+=l[i-1]+1,valid[i]++;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]) r[i]+=r[i+1]+1,valid[i]++;
        }
        int ans=0;
        for(int i=0;i<n;i++) if(valid[i]==2) ans=max(ans,l[i]+r[i]+1);
        return ans;
    }
};
