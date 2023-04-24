/*
字典序最大的子串一定为s的某个后缀。如果最大子串区间为[l,r]，那么一定可以向s尾部扩展形成字典序更大的子串，故一定为s的某个后缀
用双指针来找字典序最大的左端点即可
*/
class Solution {
public:
    string lastSubstring(string s) {
        int l=0,r=1;
        int n=s.size();
        while(r<n){
            int k=0;
            while(r+k<n&&s[l+k]==s[r+k]) k++;
            if(r+k<n&&s[l+k]<s[r+k]){
                int t=l;
                l=r;
                r=max(r+1,t+k+1);
            }else{
                r=r+k+1;
            }
        }
        return s.substr(l);
    }
};
