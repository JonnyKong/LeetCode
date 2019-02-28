/**
 * Maintain doubly-linked list in hashmap
 * i.e. java.LinkedHashMap
 */

class Node {
 public:
  int key;
  int value;
  Node *front;
  Node *back;
  Node(int _key, int _value) : key(_key), value(_value) {}
  Node(int _key, int _value, Node *_front, Node *_back)
      : key(_key), value(_value), front(_front), back(_back) {}
};

class LRUCache {
 private:
  int capacity;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> m;
  void move_to_first(Node *node) {
    Node *front_node = node->front;
    Node *back_node = node->back;
    if (front_node == NULL) {
      return;
    } else if (back_node == NULL) {
      front_node->back = NULL;
      tail = front_node;
    } else {
      front_node->back = back_node;
      back_node->front = front_node;
    }
    node->back = head;
    node->front = NULL;
    head->front = node;
    head = node;
  }

 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->head = NULL;
    this->tail = NULL;
  }

  int get(int key) {
    unordered_map<int, Node *>::iterator it = m.find(key);
    if (it == m.end()) {
      return -1;
    } else {
      move_to_first(it->second);
      return it->second->value;
    }
  }

  void put(int key, int value) {
    unordered_map<int, Node *>::iterator it = m.find(key);
    if (it == m.end()) {
      /* If full, remove tail*/
      if (m.size() == capacity) {
        m.erase(tail->key);
        if (tail->front) {
          tail->front->back = NULL;
        } else {
          head = NULL;
        }
        Node *to_del = tail;
        tail = tail->front;
        delete to_del;
      }
      Node *new_insert = new Node(key, value, NULL, head);
      if (head) {
        new_insert->back->front = new_insert;
      } else {
        tail = new_insert;
      }
      head = new_insert;
      m[key] = new_insert;
    } else {
      m[key]->value = value;
      move_to_first(it->second);
    }
  }

  ~LRUCache() {
    Node *p = head, *to_delete;
    while (p) {
      to_delete = p;
      p = p->back;
      delete to_delete;
    }
  }
};