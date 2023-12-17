#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "User.h"
#include "Order.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class Restaurant {
public:
    // 构造函数
    Restaurant(){}
    Restaurant(const string& id, const string& name, const string& location,
               const Coordinate& coordinates, const string& openingHours);

    // Getter 和 Setter 方法
    string getId() const;
    string getName() const;
    void setName(const string& name);

    string getLocation() const;
    void setLocation(const string& location);

    Coordinate getCoordinates() const;
    void setCoordinates(const Coordinate& coordinates);

    string getOpeningHours() const;
    void setOpeningHours(const string& openingHours);

    void addMenuItem( string itemName, double price);
    void removeMenuItem(const string& itemName);
    void setMenu(map<string,double> newMenu) ;
    map<string, double> getMenu() const;

    void addHistoryOrder(Order& order);
    void setHistoryOrder(vector<Order> history_order);
    vector<Order> getOrderHistory() const;

    void addPendingOrder(const Order& order);
    void setPendingOrder(vector<Order> pending_order);
    vector<Order> getOrderPending() const;

    double getRating() const;
    void updateRating(double rating);

    //打印待处理订单
    void print_PendingOrder();
    //打印历史订单
    void print_HistoryOrder();
    friend ostream& operator << (ostream &out, Restaurant it);
    friend istream& operator >> (istream &in, Restaurant &it);
private:
    string id;                     // 餐厅编号
    string name;                   // 餐厅名称
    string location;               // 餐厅地理位置
    Coordinate coordinates;        // 餐厅位置坐标
    string openingHours;           // 营业时间
    map<string, double> menu;      // 菜单（菜名及价格）
    vector<Order> orderHistory;    // 历史订单
    vector<Order> pendingOrder;    // 待处理订单
    double rating;                 // 餐厅评分
};
ostream& operator << (ostream &out, Restaurant it){
    out << it.id << " " << it.name << " " << it.location << " " << it.coordinates << " " << it.openingHours
        << " " << it.menu.size() << " ";
    for(auto &iterator : it.menu){
        out << iterator.first << " " << iterator.second << " ";
    }
    out << it.orderHistory.size() << " ";
    for(auto &iterator : it.orderHistory){
        out << iterator << " ";
    }
    out << it.pendingOrder.size() << " ";
    for(auto &iterator : it.pendingOrder){
        out << iterator << " ";
    }
    out << it.rating << " ";
    return out;
}
istream& operator >> (istream &in, Restaurant &it){
    int n;
    string str;
    double d;
    Order o;
    in >> it.id >> it.name >> it.location >> it.coordinates >> it.openingHours;
    in >> n;
    for(int i = 0; i < n; i++){
        in >> str >> d;
        it.menu.insert(make_pair(str, d));
    }
    in >> n;
    for(int i = 0; i < n; i++){
        in >> o;
        it.orderHistory.push_back(o);
    }
    in >> n;
    for(int i = 0; i < n; i++){
        in >> o;
        it.pendingOrder.push_back(o);
    }
    in >> it.rating;
    return in;
}
#endif // RESTAURANT_H
