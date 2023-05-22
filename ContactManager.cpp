#include <iostream>
#include <fstream>
#include "ContactManager.h"

void ContactManager::run() {
    int choice;
    while (true) {
        std::cout << "---- ỨNG DỤNG QUẢN LÝ DANH BẠ ĐIỆN THOẠI ----\n";
        std::cout << "1. Hiển thị danh bạ\n";
        std::cout << "2. Thêm contact\n";
        std::cout << "3. Tìm contact theo tên\n";
        std::cout << "4. Thay đổi thông tin contact\n";
        std::cout << "5. Xóa contact\n";
        std::cout << "6. Thống kê số lượng contact\n";
        std::cout << "7. Sao lưu dữ liệu\n";
        std::cout << "8. Khôi phục dữ liệu\n";
        std::cout << "9. Thoát\n";
        std::cout << "Nhập lựa chọn của bạn: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayContacts();
                break;
            case 2:
                addContact();
                break;
            case 3:
                findContactByName();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                countContacts();
                break;
            case 7:
                backupContacts();
                break;
            case 8:
                restoreContacts();
                break;
            case 9:
                std::cout << "Tạm biệt!";
                return;
            default:
                std::cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
        std::cout << "\n";
    }
}

// Hiển thị danh bạ điện thoại
void ContactManager::displayContacts() {
    std::cout << "Danh bạ điện thoại:\n";
    for (const auto& contact : contacts) {
        std::cout << "Tên: " << contact.name << "\n";
        std::cout << "Số điện thoại: " << contact.phone << "\n";
        std::cout << "Email: " << contact.email << "\n";
        std::cout << "Địa chỉ: " << contact.address << "\n\n";
    }
}

// Thêm Contact danh bạ điện thoại
void ContactManager::addContact() {
    Contact newContact;
    std::cout << "Nhập thông tin contact mới:\n";
    std::cout << "Tên: ";
    std::cin.ignore();
    std::getline(std::cin, newContact.name);
    std::cout << "Số điện thoại: ";
    std::getline(std::cin, newContact.phone);
    std::cout << "Email: ";
    std::getline(std::cin, newContact.email);
    std::cout << "Địa Chỉ: ";
    std::getline(std::cin, newContact.address);

    contacts.push_back(newContact);

    std::cout << "Contact đã được thêm vào danh bạ.\n";
}

// Tìm Thông Tin contact có trong danh bạ
void ContactManager::findContactByName() {
    std::string name;
    std::cout << "Nhập tên contact cần tìm: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Thông tin contact:\n";
            std::cout << "Tên: " << contact.name << "\n";
            std::cout << "Số điện thoại: " << contact.phone << "\n";
            std::cout << "Email: " << contact.email << "\n";
            std::cout << "Địa chỉ: " << contact.address << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy contact với tên đã nhập.\n";
    }
}

// Cập nhật thông tin contact
void ContactManager::updateContact() {
    std::string name;
    std::cout << "Nhập tên contact cần thay đổi thông tin: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Nhập thông tin mới cho contact:\n";
            std::cout << "Tên: ";
            std::getline(std::cin, contact.name);
            std::cout << "Số điện thoại: ";
            std::getline(std::cin, contact.phone);
            std::cout << "Email: ";
            std::getline(std::cin, contact.email);
            std::cout << "Địa chỉ: ";
            std::getline(std::cin, contact.address);
            std::cout << "Thông tin contact đã được cập nhật.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy contact với tên đã nhập.\n";
    }
}

// Xoá Thông tin contact
void ContactManager::deleteContact() {
    std::string name;
    std::cout << "Nhập tên contact cần xóa: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "Contact đã được xóa khỏi danh bạ.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy contact với tên đã nhập.\n";
    }
}

// Số lượng contact trong danh bạ
void ContactManager::countContacts() {
    int count = contacts.size();
    std::cout << "Số lượng contact trong danh bạ: " << count << "\n";
}

// Sao lưu thông tin contact
void ContactManager::backupContacts() {
    std::ofstream file("danhba.data");
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << "," << contact.phone << "," << contact.email << "," << contact.address << "\n";
        }
        file.close();
        std::cout << "Dữ liệu đã được sao lưu vào tệp tin.\n";
    } else {
        std::cout << "Không thể mở tệp tin để sao lưu.\n";
    }
}


// Khôi phục dữ liệu contact
void ContactManager::restoreContacts() {
    std::ifstream file("danhba.data");
    if (file.is_open()) {
        contacts.clear();
        std::string line;
        while (std::getline(file, line)) {
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            size_t pos3 = line.find(",", pos2 + 1);
            std::string name = line.substr(0, pos1);
            std::string phone = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string email = line.substr(pos2 + 1);
            std::string address = line.substr(pos3 + 1);
            contacts.push_back({name, phone, email, address});
        }
        file.close();
        std::cout << "Dữ liệu đã được khôi phục từ tệp tin.\n";
    } else {
        std::cout << "Không thể mở tệp tin để khôi phục dữ liệu.\n";
    }
}
