/*
用哈希表存储p的所有祖先，再让q一层一层向上跳，一边跳一边查询节点是否在哈希表中即可
*/
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> st;
        while(p){
            st.insert(p);
            p=p->parent;
        }
        while(q){
            if(st.count(q)) return q;
            q=q->parent;
        }
        return NULL;
    }
};
