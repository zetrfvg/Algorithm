/*
因为一共只有12个区域，我们可以用一个二进制数来枚举Bob是否获取每个区域的得分
如st=011000101011表示Bob获取了第1、2、6、8、10、11个区域的得分，共38
*/
class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int mx=0,st;
        vector<int> ans(12);
        for(int i=1;i<(1<<12);i++){
            int res=numArrows,tot=0;
            for(int j=0;j<12;j++){
                if((i>>j)&1){
                    res-=aliceArrows[j]+1;
                    tot+=j;
                }
            }
            if(res>=0&&tot>mx){
                mx=tot;
                st=i;
            }
        }
        for(int j=0;j<12;j++){
            if((st>>j)&1){
                ans[j]=aliceArrows[j]+1;
                numArrows-=ans[j];
            }
        }
        ans.back()+=numArrows;
        return ans;
    }
};
