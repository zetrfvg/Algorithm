/*
贪心的选取构造出字典序最小的数字
从最高位开始枚举0~9
当前枚举数字0，我们找到离最高位最近的0，位置是pos[0]
如果pos[j]离最高位的距离不超过k，说明可以在k次交换内把数字0移到最高位
如果pos[j]离最高位的距离超过了k，则接下来我们需要依次枚举1，2，……，9
然后我们依次枚举第二位、第三位……即可

这里，在找到数字j能够移到最高位后，此时前j-1个数并不在原来的位置上了，都向后移了一位，即这些数不在原来的位置上了
因为每把一个数移动到前面，就有一段连续的区间向后移了一位，我们需要给这些区间的偏移量加上1，这里区间操作可以用树状数组或者线段树来维护
*/
template<typename T>
struct Fenwick{
	int n;
	vector<T> tr;
	Fenwick(){}
	Fenwick(int _n):tr(_n+1),n(_n){
		for(int i=0;i<=n;i++) tr[i]=0;
	}
	T lowbit(T x){
		return x&-x;
	}
	void add(int u,T x){
		for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=x;
	}
	T query(int u){
		T res=0;
		for(int i=u;i;i-=lowbit(i)) res+=tr[i];
		return res;
	}
};
class Solution {
public:
    string minInteger(string num, int k) {
        int n=num.size();
        Fenwick<int> fen(n);
        vector<queue<int>> e(10);
        for(int i=0;i<n;i++){
            e[num[i]-'0'].push(i+1);
        }
        string ans;
        for(int i=1;i<=n;i++){
            for(int j=0;j<10;j++){
                if(e[j].empty()) continue;
                int delta=fen.query(n)-fen.query(e[j].front());
                if(e[j].front()+delta-i<=k){
                    fen.add(e[j].front(),1);
                    ans+=('0'+j);
                    k-=e[j].front()+delta-i;
                    e[j].pop();
                    break;
                }
            }
        }
        return ans;
    }
};
