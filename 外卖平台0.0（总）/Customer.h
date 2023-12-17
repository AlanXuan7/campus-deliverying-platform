#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Order.h"
#include <vector>
#include <string>

using namespace std;

class Customer : public User {
public:
    // 构造函数
    Customer(){}
    Customer(const string& id, const string& name, int age, const string& gender,
             const Coordinate& coordinates, const string& password, const string& telephoneNumber, double balance);

    // 特有的 Getter 和 Setter 方法
    const vector<Order>& getOrderHistory() const;
    void addOrder(const Order& order);
    void setOrderHistory(const vector<Order> &orderHistory); //添加，更新历史订单使用

    double getRating() const;
    void updateRating(double newRating);

private:
    vector<Order> orderHistory; // 订单历史
    double rating;               // 用户评价
};

#endif // CUSTOMER_H
