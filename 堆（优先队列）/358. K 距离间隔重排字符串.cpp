/*
双堆(大根堆)做法：
q1：按字符剩余数量作为第一关键字
q2：按字符上次放置的位置作为第一关键字
模拟：
基于贪心，我们优先选数量最多的字符来放置，即取q1堆顶的元素
然后该字符数量-1，加入q2
每次放置前，从q2中把所有前一次位置和当前位置间隔超过k的字符都加入q1，容易证明这样能够得到合法解(前提是存在合法解)
如果放置的过程中找不到能够放置的字符(即q1为空)，无解
*/
class Solution {
public:
    string rearrangeString(string s, int k) {
        vector<int> cnt(26);
        for(auto c:s) cnt[c-'a']++;
        priority_queue<tuple<int,int,int>> q1,q2;
        for(int i=0;i<26;i++) if(cnt[i]) q1.push({cnt[i],1e9,i});
        string ans;
        for(int i=0;i<s.size();i++){
            while(!q2.empty()&&i+get<0>(q2.top())>=k){
                auto [x,y,z]=q2.top();
                q1.push({y,x,z});
                q2.pop();
            }
            if(q1.empty()) return "";
            auto [c,lst,j]=q1.top();
            q1.pop();
            ans+='a'+j;
            if(c>1) q2.push({-i,c-1,j});
        }
        return ans;
    }
};
