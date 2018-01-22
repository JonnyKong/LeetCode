/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> add;
    void swap(int i){   //switch node i with i + 1
        ListNode* a = add[i];
        ListNode* b = add[i + 1];
        if(i == 0){
            a -> next = b -> next;
            b -> next = a;
        }
        else{
            add[i - 1] -> next = b;
            b -> next = a;
            a -> next = i + 2 == add.size() ? NULL : add[i + 2];
        }
        ListNode* temp = add[i];
        add[i] = add[i + 1];
        add[i + 1] = temp;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        for(ListNode* temp = head; temp; temp = temp -> next) add.push_back(temp);
        for(int i = 1; i < add.size(); ++i){
            for(int j = i; j > 0; --j){
                if(add[j] -> val < add[j-1] -> val){
                    swap(j - 1);
                }
                else break;
            }
        }
        return add[0];
    }
};
