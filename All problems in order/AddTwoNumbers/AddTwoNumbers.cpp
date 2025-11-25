
/*
===============================================================================
    My solution (Iterative Addition with Carry)

    https://leetcode.com/problems/add-two-numbers/description/

    Time Complexity: O(max(n, m))
    Space Complexity: O(max(n, m))

    Approach:
    1. Traverse both linked lists while performing digit-by-digit addition.
    2. Maintain a carry value (remainder) to store overflow from each step.
    3. For each iteration:
    - Add values of the current nodes and the carry.
    - If only one node exists, add its value with the carry.
    4. Store the digit (sum % 10) in the current node of the result list.
    5. Update the carry using sum / 10.
    6. Create and move to the next node in the result list.
    7. After processing both lists, if a carry remains, append a final node.
    8. Return the head of the resulting linked list.
===============================================================================
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        int remainder = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* currResult = result;
        while (true)
        {
            if (!curr1 && !curr2)
            {
                currResult->val = remainder;
                break;
            }
            else if (!curr1 || !curr2)
            {
                int sum;

                if (!curr1)
                {
                    sum = curr2->val + remainder;
                    curr2 = curr2->next;
                }
                else if (!curr2)
                {
                    sum = curr1->val + remainder;
                    curr1 = curr1->next;
                }
                currResult->val = sum % 10;
                remainder = sum / 10;
            }
            else
            {
                int sum = curr1->val + curr2->val + remainder;
                currResult->val = sum % 10;
                remainder = sum / 10;

                curr1 = curr1->next;
                curr2 = curr2->next;


            }
            if (!curr1 && !curr2)
            {
                if (remainder > 0)
                {
                    currResult->next = new ListNode();
                    currResult->next->val = remainder;
                }
                break;
            }
            currResult->next = new ListNode();
            currResult = currResult->next;

        }

        return result;
    }
};

/*
===============================================================================
 Optimal Solution (Iterative Addition with Carry, without unneccessary variables and checks)
 Time Complexity: O(max(n, m))
 Time Complexity: O(1)
===============================================================================

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = new ListNode();
        ListNode* curr = result;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->val = sum % 10;
            carry     = sum / 10;

            if (l1 || l2 || carry)
            {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        return result;
    }
};

/*