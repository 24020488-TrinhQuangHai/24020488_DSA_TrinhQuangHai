#include <iostream>
#include <vector>
#include <stdexcept>

class StackList {
private:
    std::vector<int> data;

public:
    // Thêm phần tử vào đỉnh Stack - O(1) Amortized
    void push(int val) {
        data.push_back(val);
    }

    // Lấy và xóa phần tử ở đỉnh Stack - O(1)
    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        int val = data.back();
        data.pop_back();
        return val;
    }

    // Xem phần tử ở đỉnh Stack - O(1)
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return static_cast<int>(data.size());
    }
};

int main() {
    StackList stack;

    std::cout << "--- DEMO STACK LIST (VECTOR) ---" << std::endl;

    stack.push(100);
    stack.push(200);
    stack.push(300);

    std::cout << "Phan tu tren cung (peek): " << stack.peek() << std::endl; // 300
    std::cout << "Kich thuoc Stack: " << stack.size() << std::endl; // 3

    std::cout << "Pop: " << stack.pop() << std::endl; // 300
    std::cout << "Phan tu tren cung sau pop: " << stack.peek() << std::endl; // 200

    return 0;
}