class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int x=stoi(event1[0].substr(0,2))*60+stoi(event1[0].substr(3));
        int xx=stoi(event1[1].substr(0,2))*60+stoi(event1[1].substr(3));
        int y=stoi(event2[0].substr(0,2))*60+stoi(event2[0].substr(3));
        int yy=stoi(event2[1].substr(0,2))*60+stoi(event2[1].substr(3));
        if(y>=x&&y<=xx) return 1;
        if(x>=y&&x<=yy) return 1;
        return 0;
    }
};
