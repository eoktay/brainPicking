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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
      int record = 0;
      ListNode *ret = new ListNode(0, NULL);
      ListNode *retDup = ret;
      ListNode *parent;
      int currentSum = 0;
      while(l1 != NULL || l2 != NULL)
      {
        ListNode *next = new ListNode();
        ret->next = next;
        if (l1 && l2)
        {
          currentSum = l1->val + l2->val + record;
          // cout << "current currentSum: " << currentSum << endl;
          if (currentSum > 9)
          {
            currentSum = currentSum % 10;
            record = 1;
          }
          else
          {
            record = 0;
          }
        }
        else if(l1)
        {
          currentSum += l1->val + record;
          if (currentSum > 9)
          {
            currentSum = currentSum % 10;
            record = 1;
          }
          else
          {
            record = 0;
          }
        }
        else if(l2)
        {
          currentSum += l2->val + record;
          if (currentSum > 9)
          {
            currentSum = currentSum % 10;
            record = 1;
          }
          else
          {
            record = 0;
          }
        }
        ret->val = currentSum;
        currentSum = 0;
        if (l1)
          l1 = l1->next;
        if (l2)
          l2 = l2->next;
        parent = ret;
        ret = ret->next;
      }
      if (!record)
        parent->next = NULL;
      else
        parent->next->val = record;
      return retDup;
    }
};