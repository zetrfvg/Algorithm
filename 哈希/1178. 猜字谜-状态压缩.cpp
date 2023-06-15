/*
因为考虑到匹配和字符的数量无关，只与种类有关，因此将每个字符串用一个二进制数来表示，用哈希表来记录words中各个数出现的次数
然后对于每个puzzle[i]，我们计算出它的二进制数st，然后枚举st的子集，在哈希表中累加答案即可
*/
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> g;
        int n=words.size();
        int m=puzzles.size();
        for(int i=0;i<n;i++){
            int st=0;
            for(int j=0;j<words[i].size();j++){
                st|=(1<<(words[i][j]-'a'));
            }
            g[st]++;
        }
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int st=0;
            for(int j=0;j<puzzles[i].size();j++){
                st|=(1<<(puzzles[i][j]-'a'));
            }
            for(int j=st;j;j=(j-1)&st){
                if(j&(1<<(puzzles[i][0]-'a'))) ans[i]+=g[j];
            }
        }
        return ans;
    }
};
