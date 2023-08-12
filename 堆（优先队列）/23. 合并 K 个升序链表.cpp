/*
用堆每次选取一个最小的元素插入链表即可
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=NULL,*p=NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) q.emplace(lists[i]->val,lists[i]);
        }
        while(!q.empty()){
            auto t=q.top().second;
            q.pop();
            if(!ans){
                ans=p=t;
            }else{
                p->next=t;
                p=t;
            }
            if(t->next) q.emplace(t->next->val,t->next);
        }
        return ans;
    }
};
