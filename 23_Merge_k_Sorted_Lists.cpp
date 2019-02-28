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
  // Compare two pairs based on underlying value
  struct comp {
    bool operator()(const pair<int, ListNode*>& a,
                    const pair<int, ListNode*>& b) {
      return (a.second->val) > (b.second->val);
    }
  };

  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)
      return NULL;
    else if (lists.size() == 1)
      return lists[0];

    // Insert into heap element from one list each
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, comp> q;
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != NULL) {
        q.push(make_pair(i, lists[i]));
        lists[i] = lists[i]->next;
      }
    }

    ListNode *head = NULL, *tail = NULL;

    while (q.empty() == false) {
      // Get smallest element from list
      pair<int, ListNode*> cur = q.top();
      q.pop();
      if (head == NULL) {
        head = cur.second;
        tail = cur.second;
      } else {
        tail->next = cur.second;
        tail = tail->next;
      }

      // Insert into q head of the same list
      if (lists[cur.first] != NULL) {
        q.push(make_pair(cur.first, lists[cur.first]));
        lists[cur.first] = lists[cur.first]->next;
      }
    }

    return head;
  }
};
