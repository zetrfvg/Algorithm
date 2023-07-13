/*
用一个哈希表记录所有串出现的位置
对于每次询问，我们用双指针来寻找最短距离
*/
class WordDistance {
public:
    unordered_map<string,vector<int>> p;
    unordered_map<string,int> sz;
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i<wordsDict.size();i++){
            p[wordsDict[i]].push_back(i);
            sz[wordsDict[i]]=p[wordsDict[i]].size();
        }
        for(auto &[a,b]:p) b.push_back(1e9);
    }
    
    int shortest(string word1, string word2) {
        int l=0,r=0,ans=1e9;
        while(l<sz[word1]&&r<sz[word2]){
            ans=min(ans,abs(p[word1][l]-p[word2][r]));
            if(p[word1][l+1]>p[word2][r+1]) r++;
            else l++;
        }
        return ans;
    }
};
