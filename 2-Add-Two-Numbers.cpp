#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(0), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0;
        ListNode *sumHead = new ListNode(0);
        ListNode *curr = sumHead;
        while (l1 && l2)
        {
            int digitSum = l1->val + l2->val + carry;
            curr->val = digitSum % 10;
            carry = digitSum / 10;
           
            if (l1->next || l2->next || carry)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int digitSum = l1->val + carry;
            curr->val = digitSum % 10;
            carry = digitSum / 10;

            if (l1->next || carry)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
            l1 = l1->next;
        }
        while (l2)
        {
            int digitSum = l2->val + carry;
            curr->val = digitSum % 10;
            carry = digitSum / 10;
            
            if (l2->next || carry)
            {
                curr->next = new ListNode(0);
                curr = curr->next;
            }
            l2 = l2->next;
        }
        if (carry)
        {
            curr->val = carry;
        }
        curr->next = nullptr;
        return sumHead;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
ListNode *createList(vector<int> nums)
{
    ListNode *dummy = new ListNode();
    ListNode *curr = dummy;

    for (int x : nums)
    {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy->next;
}
int main()
{
    // Test case 1

        // 342 represented as 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 465 represented as 5 -> 6 -> 4
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    // Test case 2
    l1 = createList({9, 9, 9, 9, 9, 9, 9});
    l2 = createList({9, 9, 9, 9});

    result = sol.addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}