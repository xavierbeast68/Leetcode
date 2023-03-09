//* https://leetcode.com/problems/palindrome-linked-list/description/
//* https://leetcode.com/problems/palindrome-linked-list/editorial/
//* https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

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
    // slow-fast technique or two-runners pointer technique
    ListNode* findMid(ListNode* head){
        ListNode *slow, *fast;
        slow = fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* reverseList(ListNode* midNode){
        ListNode *prev = NULL;
        ListNode *curr = midNode;
        ListNode *Next;

        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }

        ListNode *midNode = findMid(head);

        ListNode *left = head;
        ListNode *right = reverseList(midNode);

        while(right != NULL){
            if(left->val != right->val){
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }
};