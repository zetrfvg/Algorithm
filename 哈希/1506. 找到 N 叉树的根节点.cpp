/*
哈希表记录存在父节点的结点
在所有节点中找到不存在父节点的结点即为根结点
*/
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        set<Node*> st;
        for(auto p:tree){
            for(auto c:p->children){
                st.insert(c);
            }
        }
        for(auto p:tree) if(!st.count(p)) return p;
        return NULL;
    }
};
