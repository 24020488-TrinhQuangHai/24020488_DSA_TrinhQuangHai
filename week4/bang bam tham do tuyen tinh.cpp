#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum State { EMPTY, OCCUPIED, DELETED };

struct Node {
    int key;
    string value;
    State state = EMPTY;
};

class HashTable {
private:
    int capacity;
    int size; // Thêm biến size để quản lý số phần tử thực tế
    vector<Node> table;

    int hashFunc(int key) {
        return abs(key) % capacity;
    }

public:
    HashTable(int size) : capacity(size), size(0), table(size) {}

    // 1. THÊM HOẶC CẬP NHẬT (Đã sửa lỗi trùng Key khi có DELETED)
    bool insert(int key, string value) {
        if (size >= capacity) {
            cout << "Loi: Bang bam da day hoan toan!\n";
            return false;
        }

        int index = hashFunc(key);
        int targetIdx = -1;

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            // Kiểm tra nếu Key đã tồn tại -> Cập nhật ngay
            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                table[probe].value = value;
                return true;
            }

            // Ghi nhớ vị trí DELETED đầu tiên tìm thấy
            if (table[probe].state == DELETED && targetIdx == -1) {
                targetIdx = probe;
            }

            // Nếu gặp ô EMPTY -> Dừng duyệt
            if (table[probe].state == EMPTY) {
                if (targetIdx == -1) targetIdx = probe; // Nếu chưa thấy DELETED thì lấy ô EMPTY này
                break;
            }
        }

        // Thực hiện chèn mới
        if (targetIdx != -1) {
            table[targetIdx] = {key, value, OCCUPIED};
            size++;
            return true;
        }

        return false;
    }

    // 2. TÌM KIẾM (Đã sửa an toàn khi duyệt)
    bool search(int key, string& outValue) {
        int index = hashFunc(key);

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            if (table[probe].state == EMPTY) return false;

            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                outValue = table[probe].value;
                return true;
            }
        }
        return false;
    }

    // 3. XÓA MỀM
    bool remove(int key) {
        int index = hashFunc(key);

        for (int i = 0; i < capacity; ++i) {
            int probe = (index + i) % capacity;

            if (table[probe].state == EMPTY) return false;

            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                table[probe].state = DELETED;
                size--; // Giảm số lượng phần tử
                return true;
            }
        }
        return false;
    }

    void display() {
        cout << "\n--- BANG BAM THAM DO TUYEN TINH ---\n";
        for (int i = 0; i < capacity; ++i) {
            cout << "Index [" << i << "]: ";
            if (table[i].state == OCCUPIED)
                cout << "[" << table[i].key << " : " << table[i].value << "]";
            else if (table[i].state == DELETED)
                cout << "<DELETED>";
            else
                cout << "<EMPTY>";
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht(5);

    ht.insert(10, "An");      // Index 0
    ht.insert(15, "Binh");    // Index 1
    ht.insert(20, "Cuong");   // Index 2

    ht.remove(15);            // Index 1 chuyển thành <DELETED>

    // Thử cập nhật Key 20 (vốn nằm sau ô DELETED)
    ht.insert(20, "Cuong Moi"); 

    ht.display();
    return 0;
}