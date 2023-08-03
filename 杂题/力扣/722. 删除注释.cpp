/*
模拟题
*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        int flag=0;
        string cur;
        for(auto &s:source){
            for(int i=0;i<s.size();i++){
                if(flag){
                    if(i+1<s.size()&&s[i]=='*'&&s[i+1]=='/'){
                        flag=0;
                        i++;
                    }
                }else{
                    if(i+1<s.size()&&s[i]=='/'&&s[i+1]=='*'){
                        flag=1;
                        i++;
                    }else if(i+1<s.size()&&s[i]=='/'&&s[i+1]=='/'){
                        break;
                    }else{
                        cur+=s[i];
                    }
                }
            }
            if(!flag&&cur!=""){
                ans.push_back(cur);
                cur.clear();
            }
        }
        return ans;
    }
};
