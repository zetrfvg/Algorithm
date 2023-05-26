/*
因为target值域不大
用双指针来枚举，一个枚举答案，一个枚举哪些元素小于等于这个答案，统计最接近target的答案即可
*/
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        long long s=0,delta=1e16,ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0,j=0;j<=100000;j++){
            while(i<n&&arr[i]<=j) s+=1LL*arr[i++];
            if(abs(s+1LL*(n-i)*j-target)<delta){
                delta=abs(s+1LL*(n-i)*j-target);
                ans=j;
            }
        }
        return ans;
    }
};
