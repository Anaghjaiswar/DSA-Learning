
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // we have to first reach the middle node
        // also we will reach the first middle in case of eeven length linked
        // list
        ListNode* fast = head;
        ListNode* slow = head;

        while ((fast->next != nullptr) && (fast->next->next != nullptr)) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // now you reverse the second half
        ListNode* secondhead = reverseSecondHalf(slow->next);
        ListNode* tempNode = secondhead;

        // now we will compare
        ListNode* firsthead = head;

        while (secondhead != nullptr) {
            if (firsthead->val == secondhead->val) {
                firsthead = firsthead->next;
                secondhead = secondhead->next;
            } else return false;
        }

        // before returning let's first make the original list as it is
        // ---- NOT NEEDED IN LEETCODE SOLUTION ----
        // ListNode* temp2Node = reverseSecondHalf(tempNode);
        // slow->next = temp2Node;

        return true;
    }

private:
    ListNode* reverseSecondHalf(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* newNode = curr->next; // we need the memory of where to
                                            // look for next value;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }

        return prev;
    }
};