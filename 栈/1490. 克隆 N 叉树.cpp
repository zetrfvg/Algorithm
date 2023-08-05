/*
栈模拟建树，一边dfs一边克隆建树
*/
class Solution {
public:
    Node* cloneTree(Node* root) {
        stack<Node*> st;
        Node* ans=NULL;
        function<void(Node*)> dfs=[&](Node* root){
            if(!root) return;
            Node* p=new Node(root->val);
            if(st.empty()) ans=p;
            else st.top()->children.push_back(p);
            st.push(p);
            for(auto ch:root->children){
                dfs(ch);
            }
            st.pop();
        };
        dfs(root);
        return ans;
    }
};
