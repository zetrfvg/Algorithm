/*
模拟
*/
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int m=arr[(n-1)/2];
        sort(arr.begin(),arr.end(),[&](const int &x,const int &y){
            int a=abs(x-m),b=abs(y-m);
            return a==b?x>y:a>b;
        });
        arr.erase(arr.begin()+k,arr.end());
        return arr;
    }
};
