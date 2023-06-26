/*
分正负数贪心
正数：取最小的非0数字放第一位，对后面的数位从小到大依次排列即可
负数：取最大的非0数字放第一位，对后面的数位从大到小依次排列即可
*/
class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num);
        int p=-1;
        int n=s.size();
        if(num>=0){
            if(n<2) return num;
            for(int i=0;i<n;i++){
                if(s[i]!='0'){
                    if(p==-1||s[i]<s[p]) p=i;
                }
            }
            swap(s[0],s[p]);
            sort(s.begin()+1,s.end());
        }else{
            if(n<3) return num;
            for(int i=0;i<n;i++){
                if(s[i]!='0'){
                    if(p==-1||s[i]>s[p]) p=i;
                }
            }
            swap(s[1],s[p]);
            sort(s.begin()+2,s.end(),greater<>());
        }
        return stoll(s);
    }
};
