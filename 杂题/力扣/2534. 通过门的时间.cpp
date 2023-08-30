/*
模拟
*/
class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        queue<int> in,out;//维护两个队列，一个维护要进入门的人，一个维护要离开门的人
        int time=0,dir=1,lst=-10;//当前时间，上次使用门的人的方向，上次使用门的时间
        int n=arrival.size();
        vector<int> ans(n);
        for(int i=0;i<n||!in.empty()||!out.empty();){
            if(in.empty()&&out.empty()) time=arrival[i];//没有等待用门的人，直接快进到下一个人到来的时间
            while(i<n&&arrival[i]<=time){//入队操作
                if(state[i]) out.push(i);
                else in.push(i);
                i++;
            }
            if(time-lst>1){//前一秒没有人使用门
                if(!out.empty()){//优先给要离开门的人使用
                    lst=ans[out.front()]=time++;//记录时间
                    out.pop();
                    dir=0;//记录方向
                }else{//没有要离开门的人，则给要进入门的人使用
                    lst=ans[in.front()]=time++;
                    in.pop();
                    dir=1;
                }
            }else{//前一秒有人使用
                if(dir){//前一秒使用的人是进入这个门
                    if(!in.empty()){
                        lst=ans[in.front()]=time++;
                        in.pop();
                        dir=1;
                    }else{//当前排队使用门的人中都是要离开这个门的
                        lst=ans[out.front()]=time++;
                        out.pop();
                        dir=0;
                    }
                }else{//前一秒使用的人是离开这个门
                    if(!out.empty()){
                        lst=ans[out.front()]=time++;
                        out.pop();
                        dir=0;
                    }else{//当前排队使用门的人中都是要进入这个门的
                        lst=ans[in.front()]=time++;
                        in.pop();
                        dir=1;
                    }
                }
            }
        }
        return ans;
    }
};
