/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> g(110,NULL);
        queue<Node*> q;
        g[node->val]=new Node(node->val);
        q.push(node);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto y:x->neighbors){
                if(!g[y->val]){
                    g[y->val]=new Node(y->val);
                    q.push(y);
                }
                g[x->val]->neighbors.push_back(g[y->val]);
            }
        }
        return g[node->val];
    }
};
