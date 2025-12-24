/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL){return list2;}
    if(list2==NULL){return list1;}
    struct ListNode *temp = list1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = list2;
    int swap;
    do{
        swap = 0;
        struct ListNode* curr = list1;
        struct ListNode* lptr = NULL;
        while(curr->next!=lptr){
            if(curr->val > curr->next->val){
                swap = 1;
                int temp = curr->val;
                curr->val = curr->next->val;
                curr->next->val = temp;
            }
            curr = curr->next;
        }
        lptr = curr;
    }while(swap);
    return list1;
}
