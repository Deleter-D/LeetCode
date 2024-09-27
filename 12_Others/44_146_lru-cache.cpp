/*
    Topic link: https://leetcode.cn/problems/lru-cache/
*/
#include <iostream>
#include <unordered_map>

struct DListNode {
    int key;
    int value;
    DListNode *prev;
    DListNode *next;

    DListNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DListNode(int _key, int _value)
        : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DListNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DListNode *node = new DListNode(key, value);
            cache[key] = node;

            addToHead(node);
            size++;
            if (size > capacity) {
                DListNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                removed = nullptr;
                size--;
            }
        } else {
            DListNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

  private:
    void addToHead(DListNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DListNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DListNode *removeTail() {
        DListNode *node = tail->prev;
        removeNode(node);
        return node;
    }

  private:
    std::unordered_map<int, DListNode *> cache;
    DListNode *head;
    DListNode *tail;
    size_t capacity;
    size_t size;
};

int main(int argc, char const *argv[]) {
    int capacity = 2;
    LRUCache *lruCache = new LRUCache(capacity);
    lruCache->put(1, 1);
    lruCache->put(2, 2);
    std::cout << lruCache->get(1) << std::endl;
    lruCache->put(3, 3);
    std::cout << lruCache->get(2) << std::endl;
    lruCache->put(4, 4);
    std::cout << lruCache->get(1) << std::endl;
    std::cout << lruCache->get(3) << std::endl;
    std::cout << lruCache->get(4) << std::endl;

    return 0;
}
