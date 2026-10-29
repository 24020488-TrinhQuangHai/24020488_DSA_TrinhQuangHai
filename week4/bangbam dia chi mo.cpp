#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 3 Trạng thái của một ô trong Bảng băm
enum State { EMPTY, OCCUPIED, DELETED };

// Cấu trúc một nút dữ liệu
struct Node {
    int key;
    string value;
    State state;

    // Hàm khởi tạo (Constructor) an toàn cho mọi phiên bản C++
    Node(int k = 0, string v = "", State s = EMPTY) 
        : key(k), value(v), state(s) {}
};

class OpenAddressingHashTable {
private:
    int capacity;       // Kích thước mảng
    int size;           // Số phần tử thực tế (chỉ tính OCCUPIED)
    vector<Node> table;

    // Hàm băm chính (Chia lấy dư)
    int hashFunc(int key) {
        return abs(key) % capacity;
    }

    // Tự động x2 kích thước bảng khi hệ số tải (Load Factor) > 0.7
    void rehash() {
        int oldCapacity = capacity;
        vector<Node> oldTable = table;

        capacity *= 2;
        size = 0;
        table = vector<Node>(capacity);

        cout << "\n[Hệ thống] Tự động mở rộng mảng từ " << oldCapacity << " lên " << capacity << "...\n";

        // Chèn lại tất cả phần tử hợp lệ vào mảng mới
        for (int i = 0; i < oldCapacity; ++i) {
            if (oldTable[i].state == OCCUPIED) {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }
    }

public:
    OpenAddressingHashTable(int cap = 5) : capacity(cap), size(0), table(cap) {}

    // 1. THÊM HOẶC CẬP NHẬT PHẦN TỬ
    bool insert(int key, string value) {
        // Kiểm tra Hệ số tải (Load Factor) để Rehash
        if ((float)(size + 1) / capacity > 0.7) {
            rehash();
        }

        int index = hashFunc(key);
        int targetIdx = -1;

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            // Nếu Key đã tồn tại -> Cập nhật Value mới
            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                table[probe].value = value;
                return true;
            }

            // Ghi nhớ vị trí DELETED đầu tiên để tái sử dụng
            if (table[probe].state == DELETED && targetIdx == -1) {
                targetIdx = probe;
            }

            // Gặp ô EMPTY -> Dừng thăm dò
            if (table[probe].state == EMPTY) {
                if (targetIdx == -1) targetIdx = probe;
                break;
            }
        }

        // Thực hiện chèn mới
        if (targetIdx != -1) {
            table[targetIdx] = Node(key, value, OCCUPIED);
            size++;
            cout << "Da them: (" << key << ", \"" << value << "\") tai Index " << targetIdx << endl;
            return true;
        }

        return false;
    }

    // 2. TÌM KIẾM PHẦN TỬ
    bool search(int key, string& outValue) {
        int index = hashFunc(key);

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            // Gặp ô EMPTY nghĩa là Key không tồn tại
            if (table[probe].state == EMPTY) return false;

            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                outValue = table[probe].value;
                return true;
            }
        }
        return false;
    }

    // 3. XÓA MỀM (LAZY DELETION)
    bool remove(int key) {
        int index = hashFunc(key);

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            if (table[probe].state == EMPTY) return false;

            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                table[probe].state = DELETED; // Đánh dấu đã xóa
                size--;
                cout << "Da xoa Key: " << key << " tai Index " << probe << endl;
                return true;
            }
        }
        return false;
    }

    // 4. HIỂN THỊ BẢNG BĂM
    void display() {
        cout << "\n========== BANG BAM DIA CHI MO ==========" << endl;
        for (int i = 0; i < capacity; ++i) {
            cout << "Index [" << i << "]: ";
            if (table[i].state == OCCUPIED)
                cout << "[" << table[i].key << " : " << table[i].value << "]";
            else if (table[i].state == DELETED)
                cout << "<DELETED>";
            else
                cout << "<EMPTY>";
            cout << endl;
        }
        cout << "==========================================\n" << endl;
    }
};

int main() {
    // Khởi tạo bảng băm ban đầu có kích thước 5
    OpenAddressingHashTable ht(5);

    cout << "--- CHÈN PHẦN TỬ BAN ĐẦU ---" << endl;
    ht.insert(10, "An");      // Index 0
    ht.insert(15, "Binh");    // 15 % 5 = 0 (Đụng độ -> dời sang 1)
    ht.insert(20, "Cuong");   // 20 % 5 = 0 (Đụng độ -> dời sang 2)
    ht.display();

    cout << "--- TÌM KIẾM ---" << endl;
    string val;
    if (ht.search(15, val)) cout << "Tim thay Key 15: " << val << endl;
    else cout << "Khong tim thay Key 15" << endl;

    cout << "\n--- XÓA PHẦN TỬ & TÁI SỬ DỤNG Ô DELETED ---" << endl;
    ht.remove(15);            // Đánh dấu DELETED tại Index 1
    ht.display();

    ht.insert(25, "Dung");    // 25 % 5 = 0 (Đụng độ -> chèn vào ô DELETED tại Index 1)
    ht.display();

    cout << "--- TỰ ĐỘNG REHASH KHI BẢNG ĐẦY ---" << endl;
    ht.insert(30, "Hoa");     // Vượt Load Factor 0.7 -> Tự mở rộng dung lượng lên 10
    ht.display();

    return 0;
}