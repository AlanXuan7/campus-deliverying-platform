#include "Restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant(const string& id, const string& name, const string& location,
                       const Coordinate& coordinates, const string& openingHours)
        : id(id), name(name), location(location), coordinates(coordinates),
          openingHours(openingHours), rating(0.0) {

    // 构造函数初始化所有成员变量
}

string Restaurant::getId() const {
    return id;
}

string Restaurant::getName() const {
    return name;
}

void Restaurant::setName(const string& name) {
    this->name = name;
}

string Restaurant::getLocation() const {
    return location;
}

void Restaurant::setLocation(const string& location) {
    this->location = location;
}

Coordinate Restaurant::getCoordinates() const {
    return coordinates;
}

void Restaurant::setCoordinates(const Coordinate& coordinates) {
    this->coordinates = coordinates;
}

string Restaurant::getOpeningHours() const {
    return openingHours;
}

void Restaurant::setOpeningHours(const string& openingHours) {
    this->openingHours = openingHours;
}

void Restaurant::addMenuItem(string itemName, double price) {
    menu.insert(make_pair(itemName,price));
}

void Restaurant::removeMenuItem(const string& itemName) {
    menu.erase(itemName);
}

map<string, double> Restaurant::getMenu() const{
    return menu;
}

void Restaurant::addHistoryOrder(Order& order) {
    orderHistory.push_back(order);
}

vector<Order> Restaurant::getOrderHistory() const {
    return orderHistory;
}

void Restaurant::addPendingOrder(const Order& order)
{
    pendingOrder.push_back(order);
}

vector<Order> Restaurant::getOrderPending() const
{
    return pendingOrder;
}

double Restaurant::getRating() const {
    return rating;
}

void Restaurant::updateRating(double rating) {
    this->rating = rating;
}

void Restaurant::setHistoryOrder(vector<Order> history_order)
{
    orderHistory = history_order;
}
void Restaurant::setPendingOrder(vector<Order> pending_order)
{
    pendingOrder = pending_order;
}

void Restaurant::print_PendingOrder()
{
    cout << endl << "----------当前待处理订单----------" << endl;
    if (!pendingOrder.empty()) {
        for (int i = pendingOrder.size() - 1; i >= 0; i--) {
            cout << endl << "------------------" << endl;
            pendingOrder[i].printOrderInfo();
            cout << "------------------" << endl;
        }
    }
    else {
        cout << "未查询到待处理订单..." << endl;
    }
    cout << "--------------------------------" << endl;

    getchar();
    cout << "请按回车键返回上一级菜单...";
    getchar();
    return;
}

void Restaurant::print_HistoryOrder()
{
    cout << endl << "----------当前历史订单----------" << endl;
    if (orderHistory.size()) {
        for (int i = orderHistory.size() - 1; i >= 0; i--) {
            cout << endl << "------------------" << endl;
            orderHistory[i].printOrderInfo();
            cout << "------------------" << endl;
        }
    }
    else {
        cout << "未查询到历史订单..." << endl;
    }
    cout << "------------------------------" << endl;
    getchar();
    cout << "请按回车键返回上一级菜单...";
    getchar();
    return;
}
void Restaurant::setMenu(map<string,double> newMenu){
    menu = newMenu;
}
