#include "Customer.h"

Customer::Customer(const string& id, const string& name, int age, const string& gender,
                   const Coordinate& coordinates, const string& password, const string& telephoneNumber, double balance)
        : User(id, name, age, gender, coordinates, password, telephoneNumber, balance),
          rating(0.0) {
    // 构造函数初始化所有成员变量
}

const vector<Order>& Customer::getOrderHistory() const {
    return orderHistory;
}

void Customer::addOrder(const Order& order) {
    orderHistory.push_back(order);
}

double Customer::getRating() const {
    return rating;
}

void Customer::updateRating(double newRating) {
    rating = newRating;
}

//添加
void Customer::setOrderHistory(const vector<Order> &orderHistory) {
    Customer::orderHistory = orderHistory;
}
