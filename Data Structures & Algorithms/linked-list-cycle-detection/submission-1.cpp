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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) {
            return false;
        }
        unordered_map<int, int> indexMap;
        ListNode* temp = head;
        int index = -1;

        while(temp->next != nullptr) {
            if(indexMap.contains(temp->val)) {
                index = indexMap[temp->val];
                return true;
            }

            indexMap[temp->val] = ++index;
            temp = temp->next;
        }

        index = -1;
        return false;
    }
};
