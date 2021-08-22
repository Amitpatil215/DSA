/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    int length(ListNode *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;

        int lenA = length(A);
        int lenB = length(B);

        int diff = abs(lenA - lenB);

        ListNode *large;
        ListNode *small;

        if (lenA > lenB)
        {
            large = A;
            small = B;
        }
        else
        {
            large = B;
            small = A;
        }

        while (diff > 0)
        {
            large = large->next;
            diff--;
        }
        while (large != NULL && small != NULL)
        {
            if (large == small)
            {
                return large;
            }
            large = large->next;
            small = small->next;
        }
        return NULL;
    }
};