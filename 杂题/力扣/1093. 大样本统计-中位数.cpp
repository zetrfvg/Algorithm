/*
大模拟
*/
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n=count.size();
        vector<double> ans;
        for(int i=0;i<n;i++){
            if(count[i]){
                ans.push_back(i);
                break;
            }
        }
        for(int i=n-1;~i;i--){
            if(count[i]){
                ans.push_back(i);
                break;
            }
        }
        long long sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum+=1LL*count[i]*i;
            cnt+=count[i];
        }
        ans.push_back((double)sum/cnt);
        int cur=0,tot=0;
        for(int i=0;i<n;i++){
            if(!count[i]) continue;
            cur+=count[i];
            if(!tot&&cur*2>=cnt){
                tot+=i;
            }
            if(cur*2>=cnt+1){
                tot+=i;
                break;
            }
        }
        ans.push_back((double)tot/2);
        int mx=0,res=0;
        for(int i=0;i<n;i++){
            if(count[i]>mx){
                res=i,mx=count[i];
            }
        }
        ans.push_back(res);
        return ans;
    }
};
