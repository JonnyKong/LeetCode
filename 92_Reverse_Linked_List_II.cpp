#include <iostream>
#include <string>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseHelper(ListNode* head, int len) {
    if (head == nullptr)
      return nullptr;
    else if (len == 0 || head->next == nullptr)
      return head;
    else if (head->next->next == nullptr) {
      ListNode* result = head->next;
      result->next = head;
      head->next = nullptr;
      return result;
    }
    ListNode* cur = head;
    ListNode* cur_next = head->next;
    ListNode* cur_next_next = cur_next->next;
    for (int i = 0; i < len; ++i) {
      if (cur_next == nullptr) break;
      cur_next->next = cur;
      cur = cur_next;
      cur_next = cur_next_next;
      if (cur_next_next) cur_next_next = cur_next_next->next;
      // Otherwise, will break in next iteration
    }
    head->next = cur_next;  // Could be nullptr
    return cur;
  }

  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* cur = head;
    if (m == 1) return reverseHelper(head, n - m);
    int i = 1;

    while (cur->next && ++i < m) cur = cur->next;
    cur->next = reverseHelper(cur->next, n - m);
    return head;
  }
};

int main() {
  ListNode* root = new ListNode(3);
  root->next = new ListNode(5);
  //   root->next->next = new ListNode(3);
  //   root->next->next->next = new ListNode(4);
  //   root->next->next->next->next = new ListNode(5);
  Solution().reverseBetween(root, 1, 1);
  return 0;
}