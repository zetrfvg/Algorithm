/*
对于get，在对应key的时间上二分，找到最大的小于等于timestamp的值
*/
class TimeMap {
public:
    map<string,vector<pair<int,string>>> p;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        p[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!p[key].size()||p[key].front().first>timestamp) return "";
        int l=0,r=p[key].size()-1;
        while(l<r){
            int m=(l+r+1)>>1;
            if(p[key][m].first<=timestamp) l=m;
            else r=m-1;
        }
        return p[key][l].second;
    }
};
