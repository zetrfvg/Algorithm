/*
约瑟夫环
*/
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans+k-1)%i+1;
        }
        return ans;
    }
};
