#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
static  
    string serialize(TreeNode* root) {
        queue<TreeNode *> queue;
        string s;
        char buff[16];
        TreeNode *p = NULL;
        queue.push(root);
        while (!queue.empty()) {
            p = queue.front();
            queue.pop();
            if (s.size() > 0) {
                s.push_back(',');
            }
            if (NULL == p) {
                s.push_back('N');
            } else {
                snprintf(buff, sizeof(buff), "%d", p->val);
                s.append(buff);
                queue.push(p->left);
                queue.push(p->right);
            }
        }
        return s;
    }
static
inline int get_val(const char * &s) {
    int val = atoi(s);
    while ('\0' != *s && ',' != *s) {
        s++;
    }
    return val;
}
static
inline TreeNode * create_node(const char * &s) {
    TreeNode *p = NULL;
    if ('N' == *s) {
        s++;
    } else if ('\0' != *s){
        p = (TreeNode *)calloc(1, sizeof(struct TreeNode));
        p->val = get_val(s);
    }
    return p;
}

    // Decodes your encoded data to tree.
    static
    TreeNode* deserialize(string data) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        queue<TreeNode *> *parent = &q1;
        queue<TreeNode *> *child  = &q2;
        queue<TreeNode *> *temp   = NULL;
        TreeNode *root = NULL;
        TreeNode *p    = NULL;
        const char *s = data.c_str();
        root = create_node(s);
        if (NULL != root) {
            parent->push(root);
        }
        s += (',' == *s);
        while (!parent->empty()) {
            while (!parent->empty()) {
                p = parent->front();
                parent->pop();

                p->left = create_node(s);
                if (NULL != p->left) {
                    child->push(p->left);
                }
                s++; /* skip ',' */
                p->right = create_node(s);
                if (NULL != p->right) {
                    child->push(p->right);
                }
                if (',' == *s) {
                    s++;
                }
            }
            /* switch */
            temp = parent;
            parent = child;
            child = temp;
        }

        return root;
    }
};

struct TreeNode *
tree_insert(struct TreeNode *root, int v) {
    if (NULL == root) {
        root = (TreeNode *)calloc(1, sizeof(struct TreeNode));
        root->val = v;
    } else if (v < root->val) {
        root->left = tree_insert(root->left, v);
    } else {
        root->right = tree_insert(root->right, v);
    }
    return root;
}

void tree_print(const struct TreeNode *root) {
    if (NULL == root) {
        return ;
    }
    tree_print(root->left);
    printf("%d\t", root->val);
    tree_print(root->right);
}

int
main(void) {
    struct TreeNode *root = NULL;
    int nums[] = {10, 5, 15, 3, 18, 4, 12, 14, 1, -2, 20, -30};
    int i;
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        root = tree_insert(root, nums[i]);
    }
    tree_print(root);
    printf("\n");
    string str = Codec::serialize(root);
    printf("%s\n", str.c_str());

    struct TreeNode *q = Codec::deserialize(str);
    tree_print(q);
    printf("\n");
    return 0;
}
