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

void dfs(TreeNode *root, int depth, vector<vector<int> > &rst) {
    if (NULL == root) {
        return ;
    }
    /* 第一次进入 */
    if (rst.size() == depth) {
        vector<int> level;
        rst.insert(rst.begin(), level);
    }

    dfs(root->left,  depth+1, rst);
    dfs(root->right, depth+1, rst);
    rst[rst.size()-depth-1].push_back(root->val);
}

vector<vector<int> > levelOrderBottom(TreeNode* root) {
    vector<vector<int> > rst;
    dfs(root, 0, rst);
    return rst;
}
