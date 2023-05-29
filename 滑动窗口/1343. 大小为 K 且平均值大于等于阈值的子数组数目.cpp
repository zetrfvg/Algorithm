/*
滑动窗口枚举所有长为K的子数组即可
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int ans=0,sum=0;
        for(int l=0,r=0;r<n;r++){
            sum+=arr[r];
            if(r>=k-1){
                if(threshold*k<=sum) ans++;
                sum-=arr[r-k+1];
            }
        }
        return ans;
    }
};
