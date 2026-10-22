#include <iostream>
#include <stdexcept>

// Cấu trúc một nút trong LinkedList
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* head;
    int current_size;

public:
    StackLinkedList() : head(nullptr), current_size(0) {}

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Thêm phần tử vào đỉnh Stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        current_size++;
    }

    // Lấy và xóa phần tử ở đỉnh Stack
    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        Node* temp = head;
        int val = temp->val;
        head = head->next;
        delete temp;
        current_size--;
        return val;
    }

    // Xem phần tử ở đỉnh Stack
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
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
// Hàm main - điểm bắt đầu của chương trình
int main() {
    StackLinkedList stack;

    std::cout << "--- DEMO STACK LINKEDLIST ---" << std::endl;

    // Push phần tử
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Phan tu tren cung (peek): " << stack.peek() << std::endl; // 30
    std::cout << "Kich thuoc Stack: " << stack.size() << std::endl; // 3

    // Pop phần tử
    std::cout << "Pop: " << stack.pop() << std::endl; // 30
    std::cout << "Pop: " << stack.pop() << std::endl; // 20

    std::cout << "Phan tu tren cung sau khi pop: " << stack.peek() << std::endl; // 10
    std::cout << "Stack co rong khong? " << (stack.isEmpty() ? "Co" : "Khong") << std::endl;

    return 0;
}