#ifndef LEET_CODE_COMMON_BASE_TYPE_H_
#define LEET_CODE_COMMON_BASE_TYPE_H_

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*-----------------------------------Linked List --------------------------*/
struct ListNode *linked_list_create(int *array, int size);
struct ListNode *linked_list_destroy(struct ListNode *head);
struct ListNode *linked_list_insert_head(struct ListNode *head, int val);
struct ListNode *linked_list_insert_tail(struct ListNode *head, int val);
struct ListNode *linked_list_insert(struct ListNode *head, int val);
void linked_list_print(const struct ListNode *head);
/*-----------------------------------Linked List --------------------------*/

/*----------------------------binary search tree --------------------------*/
/*----------------------------binary search tree --------------------------*/
#endif
