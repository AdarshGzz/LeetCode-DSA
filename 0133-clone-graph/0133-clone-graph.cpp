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
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> map{{node,new Node(node->val)}};
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            for(auto v: u->neighbors){
                if(!map.count(v)){
                    map[v] = new Node(v->val);
                    q.push(v);
                }
                map[u]->neighbors.push_back(map[v]);
            }
        }
        return map[node];
    }
};