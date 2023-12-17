#include "Order.h"
#include <iostream>
using namespace std;

Order::Order(const string& orderId, const string& restaurantId, const string& restaurantName,
             const string& customerName, const vector<pair<string, double>>& itemsOrdered,
             const string& customerPhone, const Coordinate& customerCoordinates)
        : orderId(orderId), restaurantId(restaurantId), restaurantName(restaurantName),
          customerName(customerName), itemsOrdered(itemsOrdered),
          customerPhone(customerPhone), customerCoordinates(customerCoordinates),
          orderStatus(Status::Pending) {
}

string Order::getOrderId() const {
    return orderId;
}

string Order::getRestaurantId() const {
    return restaurantId;
}

string Order::getRestaurantName() const {
    return restaurantName;
}

string Order::getCustomerName() const {
    return customerName;
}

double Order::getTotalAmount() const {
    double total = 0.0;
    for (const auto& item : itemsOrdered) {
        total += item.second;
    }
    return total;
}

string Order::getCustomerPhone() const {
    return customerPhone;
}

Coordinate Order::getCustomerCoordinates() const {
    return customerCoordinates;
}

Order::Status Order::getOrderStatus() const {
    return orderStatus;
}

void Order::setOrderStatus(Status newStatus) {
    orderStatus = newStatus;
}

//订单信息打印
void Order::printOrderInfo() const
{
    cout << "订单信息" << endl;
    cout << "订单编号: " << orderId << endl;
    cout << "订单状态: ";
    if (orderStatus == Status::Pending) cout << "待接单" << endl << endl;
    if (orderStatus == Status::Preparing) cout << "制作中" << endl << endl;
    if (orderStatus == Status::Prepared) cout << "制作完成, 待配送" << endl << endl;
    if (orderStatus == Status::InTransit) cout << "配送中" << endl << endl;
    if (orderStatus == Status::Completed) cout << "已完成" << endl << endl;

    cout << "餐厅信息" << endl;
    cout << "餐厅编号: " << restaurantId << endl
         << "餐厅名称: " << restaurantName << endl << endl;

    cout << "顾客信息" << endl;
    cout << "顾客姓名: " << customerName << endl
         << "顾客电话: " << customerPhone << endl
         << "顾客地址: " << customerCoordinates.getX() << ', ' << customerCoordinates.getY() << endl << endl;

    cout << "菜品订单" << endl;
    for (int i = 0; i < itemsOrdered.size(); i++) {
        cout << "菜品名称: " << itemsOrdered[i].first << "\t"
             << "价格: " << itemsOrdered[i].second << endl;
    }

    cout << endl;

    cout << "本单总计: " << getTotalAmount() << " 元" << endl;
}

Order::Order() {}

