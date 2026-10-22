#include <iostream>
#include <vector>
#include <stdexcept>

class QueueList {
private:
    std::vector<int> data;
    int front_index;

public:
    QueueList() : front_index(0) {}

    // Thêm phần tử vào cuối Queue - O(1) Amortized
    void enqueue(int val) {
        data.push_back(val);
    }

    // Lấy và xóa phần tử ở đầu Queue - O(1) dùng con trỏ trượt
    int dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        int val = data[front_index];
        front_index++;

        // Thu gọn mảng khi phần tử bị dequeue tích lũy lớn
        if (front_index > 1000 && front_index > static_cast<int>(data.size()) / 2) {
            data.erase(data.begin(), data.begin() + front_index);
            front_index = 0;
        }

        return val;
    }

    // Xem phần tử ở đầu Queue - O(1)
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return data[front_index];
    }

    bool isEmpty() const {
        return front_index >= static_cast<int>(data.size());
    }

    int size() const {
        return static_cast<int>(data.size()) - front_index;
    }
};

int main() {
    QueueList queue;

    std::cout << "--- DEMO QUEUE LIST (VECTOR) ---" << std::endl;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Phan tu dau Queue (peek): " << queue.peek() << std::endl; // 10
    std::cout << "Kich thuoc Queue: " << queue.size() << std::endl; // 3

    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // 10
    std::cout << "Phan tu dau Queue sau dequeue: " << queue.peek() << std::endl; // 20

    return 0;
}