#ifndef SUPERADMIN_H
#define SUPERADMIN_H

#include <vector>
#include "Customer.h"
#include "DeliveryPerson.h"
#include "RestaurantAdmin.h"
#include "ALL_FUNCTION.h"

class SuperAdmin {
public:
    SuperAdmin();

    // 查看用户信息
    void viewCustomers(const  vector<Customer>& customers, const vector<DeliveryPerson>& deliveryPeople,
                   const vector<RestaurantAdmin>& admins);

    // 修改用户信息
    void modifyCustomers(vector<Customer>& customers, vector<DeliveryPerson>& deliveryPeople,
                    vector<RestaurantAdmin>& admins);

private:
    void viewCustomers(const  vector<Customer>& customers);
    void viewDeliveryPeople(const  vector<DeliveryPerson>& deliveryPeople);
    void viewRestaurantAdmins(const  vector<RestaurantAdmin>& admins);

    // 辅助函数，具体实现取决于User类的定义
    void displayUserInfo(const User& user);
    void editUserInfo(User& user);
};

#endif // SUPERADMIN_H
