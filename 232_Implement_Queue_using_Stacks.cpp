class Queue {
 public:
  stack<int> a;
  stack<int> b;
  int temp;

  void transfer() {
    if (b.empty()) {
      while (!a.empty()) {
        temp = a.top();

        a.pop();

        b.push(temp);
      }
    }
  }

  void push(int x) { a.push(x); }

  // Removes the element from in front of queue.
  void pop(void) {
    transfer();

    b.pop();
  }

  // Get the front element.
  int peek(void) {
    transfer();

    return b.top();
  }

  // Return whether the queue is empty.
  bool empty(void) { return a.empty() && b.empty(); }
};