/*
从左到右枚举数位
如果是正数，则找到第一个小于x的数，在它之前插入
如果是负数，则找到第一个大于x的数，在它之前插入
找不到的话则插入在串尾
*/
class Solution {
public:
    string maxValue(string n, int x) {
        int m=n.size();
        if(n[0]=='-'){
            for(int i=1;i<m;i++){
                if(n[i]-'0'>x){
                    n.insert(i,to_string(x));
                    return n;
                }
            }
        }else{
            for(int i=0;i<m;i++){
                if(n[i]-'0'<x){
                    n.insert(i,to_string(x));
                    return n;
                }
            }
        }
        n+=('0'+x);
        return n;
    }
};
