#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <vector>
#include "Contact.h"

class ContactManager {
public:
    void run(); // Hàm chạy ứng dụng

private:
    std::vector<Contact> contacts; // Danh sách các contact

    void displayContacts();     // Hiển thị toàn bộ danh bạ
    void addContact();          // Thêm contact vào danh bạ
    void findContactByName();   // Tìm contact theo tên
    void updateContact();       // Thay đổi thông tin contact
    void deleteContact();       // Xoá thông tin contact
    void countContacts();       // Thống kê số lượng contact
    void backupContacts();      // Sao lưu dữ liệu
    void restoreContacts();     // Khôi phục dữ liệu
};

#endif
