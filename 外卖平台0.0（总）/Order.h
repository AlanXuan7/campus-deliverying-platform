#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "User.h"
#include <fstream>
#include <utility>
using namespace std;

class Order {
public:
    enum class Status {
        Pending,   // 未接单
        Preparing, // 制作中
        Prepared,  // 制作完成，待配送
        InTransit, // 配送中
        Completed  // 已完成
    };
    friend ostream& operator << (ostream &out, Order it);
    friend istream& operator >> (istream &in, Order &it);
    // 构造函数
    Order(const string& orderId, const string& restaurantId, const string& restaurantName,
          const string& customerName, const vector<pair<string, double>>& itemsOrdered,
          const string& customerPhone, const Coordinate& customerCoordinates);

    Order();

    // Getter 方法
    string getOrderId() const;
    string getRestaurantId() const;
    string getRestaurantName() const;
    string getCustomerName() const;
    double getTotalAmount() const;
    string getCustomerPhone() const;
    Coordinate getCustomerCoordinates() const;
    Status getOrderStatus() const;

    // 订单状态管理
    void setOrderStatus(Status newStatus);

    //订单信息打印
    void printOrderInfo() const;

private:
    string orderId;                                 //订单编号
    string restaurantId;                            //餐厅编号
    string restaurantName;                          //餐厅名字
    string customerName;                            //顾客名字
    vector<pair<string, double>> itemsOrdered;      //菜品
    string customerPhone;                           //顾客电话
    Coordinate customerCoordinates;                 //顾客地址
    Status orderStatus;                             //订单状态
};
ostream& operator << (ostream &out, Order it){
    out << it.orderId << " " << it.restaurantId << " " << it.restaurantName << " " << it.customerName << " ";
    out << it.itemsOrdered.size() << " ";
    for (auto &iterator : it.itemsOrdered){
        out << iterator.first << " " << iterator.second << " ";
    }
    out << it.customerPhone << " " << it.customerCoordinates << " " << static_cast<int>(it.orderStatus) << endl;
    return out;
}

istream &operator >> (istream &in, Order &it){
    in >> it.orderId >> it.restaurantId >> it.restaurantName >> it.customerName;
    int i;
    string str;
    double d;
    in >> i;
    for(int j = 0; j < i; j++){
        in >> str >> d;
        it.itemsOrdered.push_back(make_pair(str,d));
    }
    in >> it.customerPhone >> it.customerCoordinates >> i;
    it.orderStatus = static_cast<Order::Status>(i);
    return in;
}
#endif // ORDER_H