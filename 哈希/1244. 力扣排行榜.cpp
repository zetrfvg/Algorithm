/*
map维护参赛选手的分数
set维护分数的有序集合
*/
class Leaderboard {
public:
    unordered_map<int,int> p;
    multiset<int> st;
    Leaderboard() {

    }
    
    void addScore(int playerId, int score) {
        if(p.count(playerId)) st.erase(st.find(p[playerId]));
        p[playerId]+=score;
        st.insert(p[playerId]);
    }
    
    int top(int K) {
        auto q=st.rbegin();
        int res=0;
        for(int i=0;i<K;i++,q=next(q)){
            res+=*q;
        }
        return res;
    }
    
    void reset(int playerId) {
        st.erase(st.find(p[playerId]));
        p.erase(playerId);
    }
};
