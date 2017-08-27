

/*
 * Problem statement :- https://leetcode.com/problems/add-two-numbers/description/
 *
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *res = NULL, *last = NULL;
        int carry = 0, curSum;
        while(l1 && l2) {
            int v1 = l1->val;
            int v2 = l2->val;
            curSum = v1 + v2 + carry;
            carry = 0;
            if(curSum > 9) carry = 1;
            curSum = curSum % 10;
            if(!res) {
                res = new ListNode(curSum);
                last = res;
            } else{
                last->next = new ListNode(curSum);
                last = last->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            int v = l1->val;
            curSum = v + carry;
            carry = 0;
            if(curSum > 9) carry = 1;
            curSum = curSum % 10;
            if(!res) {
                res = new ListNode(curSum);
                last = res;
            } else {
                last->next = new ListNode(curSum);
                last = last->next;
            }
            l1 = l1->next;
        }
        
        while(l2) {
            int v = l2->val;
            curSum = v + carry;
            carry = 0;
            if(curSum > 9) carry = 1;
            curSum = curSum % 10;
            if(!res) {
                res = new ListNode(curSum);
                last = res;
            } else {
                last->next = new ListNode(curSum);
                last = last->next;
            }
            l2 = l2->next;
        }
        
        if(carry) {
            if(!res) {
                res = new ListNode(carry);
                last = res;
            } else {
                last->next = new ListNode(carry);
                last = last->next;
            }
        }
        if(last)
            last->next = NULL;
        return res;
        
    }
};
