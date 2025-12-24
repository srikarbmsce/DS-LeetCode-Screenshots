/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    struct ListNode *prevA = list1;
    int i = 0;

    while (i < a - 1) {
        prevA = prevA->next;
        i++;
    }

    struct ListNode *afterB = prevA;
    while (i < b) {
        afterB = afterB->next;
        i++;
    }

    prevA->next = list2;

    struct ListNode *tail2 = list2;
    while (tail2->next != NULL) {
        tail2 = tail2->next;
    }

    tail2->next = afterB->next;

    return list1;
}
