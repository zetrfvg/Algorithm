/*
大模拟题，细节多
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> s;
        vector<string> t,ans;
        vector<int> h;
        int len=0;
        for(auto c:words){
            if(t.size()==0||len+t.size()-1+c.size()<maxWidth){
                t.push_back(c);
                len+=c.size();
            }else{
                s.push_back(t);
                h.push_back(len);
                t.resize(0);
                len=c.size();
                t.push_back(c);
            }
        }
        s.push_back(t);
        h.push_back(len);
        for(int i=0;i<s.size();i++){
            string res;
            if(i==s.size()-1){
                for(auto c:s[i]){
                    if(res.size()) res+=' ';
                    res+=c;
                }
                while(res.size()!=maxWidth) res+=' ';
                ans.push_back(res);
            }else{
                if(s[i].size()==1){
                    res+=s[i][0];
                    while(res.size()!=maxWidth) res+=' ';
                    ans.push_back(res);
                }else{
                    int w=maxWidth-h[i];
                    int x=w/(s[i].size()-1),y=w%(s[i].size()-1);
                    for(auto c:s[i]){
                        if(res.size()){
                            for(int j=0;j<x;j++) res+=' ';
                        }
                        if(res.size()&&y){
                            res+=' ';
                            y--;
                        }
                        res+=c;
                    }
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};
