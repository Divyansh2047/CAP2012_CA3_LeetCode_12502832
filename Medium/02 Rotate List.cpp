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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
            
        int len = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        if(k % len == 0){
            return head;
        }

        k = k % len;
        tail->next = head;
        
        ListNode* newLastNode = head;
        int cnt = 0;
        while(newLastNode != NULL){
            cnt++;
            if(cnt == len - k){
                break;
            }
            newLastNode = newLastNode->next;
        }
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
