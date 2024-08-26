/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (!root)
            return result;

        stack<Node*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node* node = nodeStack.top();
            nodeStack.pop();

            result.push_back(node->val);

            for (Node* child : node->children) {
                nodeStack.push(child);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};