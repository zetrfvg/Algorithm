/*
简单贪心即可
*/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> pos,neg;
        for(auto c:satisfaction){
            if(c>=0) pos.push_back(c);
            else neg.push_back(c);
        }
        int ans=0,sum=0;
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end(),greater<>());
        for(int i=0;i<pos.size();i++){
            sum+=pos[i],ans+=(i+1)*pos[i];
        }
        for(int i=0;i<neg.size();i++){
            sum+=neg[i];
            if(sum>0) ans+=sum;
            else break;
        }
        return ans;
    }
};
