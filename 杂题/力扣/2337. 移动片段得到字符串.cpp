/*
分类讨论
*/
class Solution {
public:
    bool canChange(string start, string target) {
        int n=target.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(start[i]=='R'){
                if(x) return false;//target在此之前至少需要一个L,此时后面再出现L已经无法到达target之前需要L的位置
                y++;
            }
            if(target[i]=='L'){
                if(y) return false;//start在此之前至少多出一个R,此时无法再移动到target后面需要R的位置
                x++;
            }
            if(target[i]=='R'){
                if(x||!y) return false;//此时需要在start前面的一个位置找一个R补齐,如果之前存在L,则该L无法和target任何位置上的L匹配；如果之前没有出现R,亦不合法
                y--;
            }
            if(start[i]=='L'){
                if(!x) return false;//此时多出一个L，需要判断target这个位置之前是否需要L,若不需要则该L无法和target任何位置上的L匹配
                x--;
            }
        }
        return !x&&!y;
    }
};
