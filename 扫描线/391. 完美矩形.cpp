/*
覆盖形成的矩形，除了两端的线条，中间小矩形相邻的线条一定是成对出现
*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        vector<array<int,4>> e;
        for(auto &re:rectangles){
            e.push_back({re[0],re[1],re[3],1});
            e.push_back({re[2],re[1],re[3],-1});
        }
        sort(e.begin(),e.end());
        for(int i=0;i<n*2;){
            int j=i;
            vector<array<int,4>> l,r;//l记录矩形的左端点，r记录矩形的右端点
            for(;j<n*2&&e[i][0]==e[j][0];j++){//横坐标相同的线条统一处理
                auto &cur=e[j][3]==1?l:r;
                if(!cur.size()){//该组之前未出现线条
                    cur.push_back(e[j]);
                }else{
                    auto &pre=cur.back();////找到该组之前出现过的最后一个线条
                    if(e[j][1]<pre[2]) return false;//如果旧线条的最高点大于新线条的最低点，说明两个线条有重复部分，即可矩形之间相互覆盖
                    else if(e[j][1]==pre[2]) pre[2]=e[j][2];//如果旧线条的最高点等于新线条的最低点，说明这里是两个相邻矩形的分界点，用新线条的最高点去更新旧线条的最高点
                    else cur.push_back(e[j]);//新旧线条完全没有交集，推入一个新线条
                }
            }
            if(i>0&&j<n*2){
                if(l.size()!=r.size()) return false;//因为是成对出现，所有两个组的线条数量一定相同
                for(int k=0;k<l.size();k++){
                    if(l[k][1]!=r[k][1]||l[k][2]!=r[k][2]) return false;//线条不同，说明有覆盖缺失的情况
                }
            }
            i=j;//枚举下一组横坐标相同的线条集
        }
        return true;
    }
};
