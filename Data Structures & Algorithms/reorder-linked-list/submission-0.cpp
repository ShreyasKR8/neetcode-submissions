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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodesList;
        ListNode* temp = head;

        while(temp != nullptr) {
            nodesList.push_back(temp);
            temp = temp->next;
        }

        int i = 0, j = nodesList.size() - 1;
        while(i < j) {
            nodesList[i]->next = nodesList[j];
            i++;
            if(i >= j) break;
            nodesList[j]->next = nodesList[i];
            j--;
        }

        nodesList[i]->next = nullptr;
    }
};
