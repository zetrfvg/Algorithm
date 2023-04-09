class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> pos(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!pos[s[i]-'a']) pos[s[i]-'a']=i+1;
            else if(i-pos[s[i]-'a']!=distance[s[i]-'a']) return false;
        }
        return true;
    }
};
