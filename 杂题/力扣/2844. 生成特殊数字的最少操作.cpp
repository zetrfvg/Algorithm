/*
首先容易想到暴力枚举串中是否存在00/25/50/75的子序列即可
否则num只能变为0，如果num中存在0则只需要删去n-1个数，如果不存在则需要全部删去
*/
class Solution {
public:
    int minimumOperations(string num) {
        int n=num.size();
        int l=-1,r=-1;
        int x=-1,y=-1;
        for(int i=n-1;~i;i--){
            if(num[i]=='0'&&r==-1) r=i;
            else if((num[i]=='0'||num[i]=='5')&&r!=-1){
                l=i;
                break;
            }
        }
        if(l!=-1&&r!=-1){
            x=n-l-2;
        }
        l=r=-1;
        for(int i=n-1;~i;i--){
            if(num[i]=='5'&&r==-1) r=i;
            else if((num[i]=='2'||num[i]=='7')&&r!=-1){
                l=i;
                break;
            }
        }
        if(l!=-1&&r!=-1){
            y=n-l-2;
        }
        if(x!=-1&&y!=-1){
            return min(x,y);
        }else if(x!=-1){
            return x;
        }else if(y!=-1){
            return y;
        }
        int c=0;
        for(auto p:num) if(p!='0') c++;
        return c;
    }
};
