#include <iostream>
#include <stdexcept>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* head;
    Node* tail;
    int current_size;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr), current_size(0) {}

    ~QueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Thêm phần tử vào cuối Queue - O(1)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current_size++;
    }

    // Lấy và xóa phần tử ở đầu Queue - O(1)
    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        Node* temp = head;
        int val = temp->val;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        current_size--;
        return val;
    }

    // Xem phần tử ở đầu Queue - O(1)
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return head->val;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int size() const {
        return current_size;
    }
};

int main() {
    QueueLinkedList queue;

    std::cout << "--- DEMO QUEUE LINKEDLIST ---" << std::endl;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Phan tu dau Queue (peek): " << queue.peek() << std::endl; // 1
    std::cout << "Kich thuoc Queue: " << queue.size() << std::endl; // 3

    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // 1
    std::cout << "Phan tu dau Queue sau dequeue: " << queue.peek() << std::endl; // 2

    return 0;
}