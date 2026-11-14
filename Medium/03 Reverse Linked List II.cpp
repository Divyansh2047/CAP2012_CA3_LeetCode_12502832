/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* preLeft = dummy;
        ListNode* currNode = head;

        for(int i = 0; i < left - 1; i++){
            preLeft = preLeft->next;
            currNode = currNode->next;
        }

        ListNode* subList = currNode;
        ListNode* prev = NULL;
        for(int i = 0; i <= right - left; i++){
            ListNode* next = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = next;
        }

        preLeft->next = prev;
        subList->next = currNode;
    return dummy->next;
    }
};
