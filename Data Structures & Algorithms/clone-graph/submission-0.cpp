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
    Node* cloneGraph(Node* node) 
    {
        if (!node) return nullptr;
        unordered_map<int, Node*> oldNodes;
        unordered_map<int, Node*> newNodes;
        dfs(node, oldNodes, newNodes);

        for (auto [i, oldNode] : oldNodes)
        {
            Node* newNode = newNodes[i];
            //string oldS = "";
            //oldS += to_string(num) + ": [";

            for (Node* neighbor : oldNode->neighbors)
            {
                newNode->neighbors.push_back(newNodes[neighbor->val]);
                //oldS += to_string(neighbor->val) + ", ";
            }

           //while (oldS.back() == ' ' || oldS.back() == ',') oldS.pop_back();
            //oldS += "]";
            
            //cout << s << endl;
        }
        
        return newNodes[node->val];
    }

    void dfs(Node* node, unordered_map<int, Node*>& oldNodes, unordered_map<int, Node*>& newNodes)
    {
        if (!node) return;
        if (oldNodes.contains(node->val)) return;

        oldNodes[node->val] = node;
        newNodes[node->val] = new Node(node->val);

        for (Node* node : node->neighbors)
        {
            dfs(node, oldNodes, newNodes);
        }
    }
};
