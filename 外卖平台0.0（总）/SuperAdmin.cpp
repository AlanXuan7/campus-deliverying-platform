#include "SuperAdmin.h"
#include <iostream>

using namespace std;

SuperAdmin::SuperAdmin() {
    // 构造函数实现
}

void SuperAdmin::viewCustomers(const vector<Customer>& customers, const vector<DeliveryPerson>& deliveryPeople,
                               const vector<RestaurantAdmin>& admins) {
    int choice;
    cout << "请选择查看的类型：\n1. 顾客\n2. 外卖员\n3. 餐厅管理员\n";
    cin >> choice;

    switch (choice) {
        case 1:
            viewCustomers(customers);
            break;
        case 2:
            viewDeliveryPeople(deliveryPeople);
            break;
        case 3:
            viewRestaurantAdmins(admins);
            break;
        default:
            cout << "无效选择。\n";
            break;
    }
}

void SuperAdmin::modifyCustomers(vector<Customer>& customers, vector<DeliveryPerson>& deliveryPeople,
                                 vector<RestaurantAdmin>& admins) {
    // 实现修改用户信息的逻辑
    // 示例代码略
}

void SuperAdmin::viewCustomers(const vector<Customer>& customers) {
    for (const auto& customer : customers) {
        displayUserInfo(customer);
    }
}

void SuperAdmin::viewDeliveryPeople(const vector<DeliveryPerson>& deliveryPeople) {
    for (const auto& deliveryPerson : deliveryPeople) {
        displayUserInfo(deliveryPerson);
    }
}

void SuperAdmin::viewRestaurantAdmins(const vector<RestaurantAdmin>& admins) {
    for (const auto& admin : admins) {
        displayUserInfo(admin);
    }
}

void SuperAdmin::displayUserInfo(const User& user) {
    // 显示用户信息的实现
    // 示例代码略
}

void SuperAdmin::editUserInfo(User& user) {
    // 编辑用户信息的实现
    // 示例代码略
}
