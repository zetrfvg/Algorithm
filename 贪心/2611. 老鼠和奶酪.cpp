/*
如果老鼠2把奶酪都吃了，获得的价值sum=Σreward2[i]
对于每个奶酪i，老鼠1吃掉则sum=sum+reward1[i]-reward2[i]
观察变化值reward1[i]-reward2[i]，我们希望这个变化值尽可能的大，最终获得的价值才会最大
因此对reward1[i]-reward2[i]排序之后选最大的k个值加上sum即为答案
*/
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum=accumulate(reward2.begin(),reward2.end(),0);
        int n=reward1.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=reward1[i]-reward2[i];
        }
        sort(diff.begin(),diff.end(),greater<>());
        return sum+accumulate(diff.begin(),diff.begin()+k,0);
    }
};
