#include <iostream>
#include <stack>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* nextPtr): val(x), next(nextPtr){}
};
// using stack
class MoreSpaceSolution
{

    public:
    int pairSum(ListNode* head)
    {
        ListNode* curr=head;
        stack<int> st;
        int len=0;
        while(curr!=nullptr)
        {
            len++;
            curr = curr->next;
        }
        int half = len/2;
        int i=1;
        curr=head;
    
        while(i<=half)
        {
            st.push(curr->val);
            curr=curr->next;
            i++;
        }
        int maxSum=0;
        while(curr!=nullptr)
        {
            maxSum= max(maxSum, st.top()+curr->val);
            st.pop();
            curr=curr->next;
        }
        return maxSum;
    }   
    
};
// by reversing a the second  half O(n) and O(1) space
class Solution
{

    public:
    int pairSum(ListNode* head)
    {
       
        // reaching the middle using slow and fast pointer
        ListNode *slow=head, *fast =head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverseing the  later half 
        ListNode *next=nullptr, *prev=nullptr, *curr=slow;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int maxSum=0;
        ListNode* leftPtr=head;
        ListNode* rightPtr = prev;

        while(rightPtr!=nullptr)
        {
            maxSum = max(rightPtr->val+leftPtr->val,maxSum);
            leftPtr=leftPtr->next;
            rightPtr=rightPtr->next;
        }
        return maxSum;
    }   
    
};
int main()
{
    // 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    Solution sol;
    cout << sol.pairSum(head) << endl;

    return 0;
}


