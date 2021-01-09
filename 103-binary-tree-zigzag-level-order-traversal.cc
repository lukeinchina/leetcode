#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


vector<vector<int> > levelOrder(TreeNode* root) {
    int i, size, ctrl;
    vector<vector<int> > rst;
    queue<TreeNode *> q;

    if (NULL != root) {
        q.push(root);
    }
    for (ctrl = 0; !q.empty(); ctrl = (ctrl + 1) % 2) {
        size = q.size();
        vector<int> level;
        for (i = 0; i < size; i++) {
            TreeNode *root = q.front();
            if (ctrl) {
                level.insert(level.begin(), root->val);
            }else {
                level.push_back(root->val);
            }
            q.pop();

            if (NULL != root->left) {
                q.push(root->left);
            } 
            if (NULL != root->right) {
                q.push(root->right);
            }
        }
        rst.push_back(level);
    }
    return rst;
}
