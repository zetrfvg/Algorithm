/*
经典八数码问题类型
简单搜索
*/
class Solution {
public:
    string target="123450";
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> st;
        string s;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                s+='0'+board[i][j];
            }
        }
        queue<pair<string,int>> q;
        st.insert(s);
        q.push({s,0});
        while(!q.empty()){
            auto [a,d]=q.front();
            q.pop();
            if(a==target) return d;
            int p=0;
            while(a[p]!='0') p++;
            int x=p/3,y=p%3;
            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<0||xx>=2||yy<0||yy>=3) continue;
                string b=a;
                swap(b[x*3+y],b[xx*3+yy]);
                if(st.count(b)) continue;
                st.insert(b);
                q.push({b,d+1});
            }
        }
        return -1;
    }
};
