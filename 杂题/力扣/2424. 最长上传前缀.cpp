/*
用一个f数组来记录每个视频是否被上传，用top来表示最长的前缀
上传视频：令f[video]=1，然后top指针不断后移直到top的后一个元素为0为止即可
最长前缀：返回top即可
*/
class LUPrefix {
public:
    int f[100010];
    int top=0;
    LUPrefix(int n) {
        memset(f,0,sizeof f);
    }
    
    void upload(int video) {
        f[video]=1;
        while(f[top+1]) top++;
    }
    
    int longest() {
        return top;
    }
};
