/*
每次从堆中选取两个频率最高的元素交错放置
*/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> q;
        sort(barcodes.begin(),barcodes.end());
        int n=barcodes.size();
        for(int i=0;i<n;){
            int j=i;
            while(j<n&&barcodes[i]==barcodes[j]) j++;
            q.push({j-i,barcodes[i]});
            i=j;
        }
        int i=0;
        while(q.size()>1){
            auto a=q.top();
            q.pop();
            auto b=q.top();
            q.pop();
            if(i&&a.second==barcodes[i-1]) swap(a,b);
            barcodes[i++]=a.second;
            barcodes[i++]=b.second;
            if(--a.first){
                q.push(a);
            }
            if(--b.first){
                q.push(b);
            }
        }
        if(q.size()){
            barcodes.back()=q.top().second;
        }
        return barcodes;
    }
};
