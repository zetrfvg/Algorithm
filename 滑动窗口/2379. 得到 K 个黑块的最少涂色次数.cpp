class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=1e9,c=0;
        for(int i=0;i<blocks.size();i++){
            c+=blocks[i]=='B';
            if(i>=k-1){
                ans=min(ans,k-c);
                c-=blocks[i-k+1]=='B';
            }
        }
        return ans;
    }
};
