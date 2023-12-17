// Customer_Functions.cpp
// Created by 邓志轩 2023/11/25
#include <iostream>
#include <vector>
#include "Restaurant.h"
#include "Order.h"
#include "Customer.h"
#include "RestaurantAdmin.h"
using namespace std;

void Customer_Function(vector<Restaurant> &restaurants, Customer &customer, vector<RestaurantAdmin> &restaurantAdminList) {
    A:
    while (true){
        cout << "请选择顾客功能：" << endl
             << "1: 个人信息" << endl
             << "2: 点餐" << endl
             << "3: 查看订单"  << endl
             << "4: 退出" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "个人信息：" << endl;
                cout << "学号: " << customer.getId() << endl;
                cout << "姓名: " << customer.getName() << endl;
                cout << "年龄: " << customer.getAge() << endl;
                cout << "性别: " << customer.getGender() << endl;
                cout << "电话号码: " << customer.getTelephoneNumber() << endl;
                cout << "账户余额: " << customer.getBalance() << endl;
                Coordinate coordinates = customer.getCoordinates();
                cout << "位置: (" << coordinates.getX() << ", " << coordinates.getY()<< ")" << endl;
                cout << "评分: " << customer.getRating() << endl << endl;
                getchar();
                cout << "---------------------------" << endl;
                cout << "按回车键返回上一级菜单...";
                getchar();
                system("cls");//清屏操作，美化一下
                break;

            }
            case 2: {
                if(restaurants.empty()){
                    system("cls");//清屏操作，美化一下
                    cout << "未查询到餐厅信息！！" << endl;
                    cout << "---------------------------" << endl;
                    cout << "按回车键返回上一级菜单...";
                    getchar();
                    getchar();
                    system("cls");//清屏操作，美化一下
                    break;
                }
                for (const auto& restaurant : restaurants) {
                    cout << "编号: " << restaurant.getId() << ", 名称: " << restaurant.getName()
                         << ", 地址: " << restaurant.getLocation() << ", 营业时间: " << restaurant.getOpeningHours()
                         << ", 评分: " << restaurant.getRating() << endl;
                }
                string selectedId;
                cout << "请输入餐厅编号: ";
                cin >> selectedId;

                Restaurant* selectedRestaurant = nullptr;
                for (auto& restaurant : restaurants) {
                    if (restaurant.getId() == selectedId) {
                        selectedRestaurant = &restaurant;
                        break;
                    }
                }

                if (selectedRestaurant == nullptr) {
                    cout << "未找到选定的餐厅，请重新选择。" << endl;
                    goto A;
                }

                cout << "餐厅 " << selectedRestaurant->getName() << " 的菜单：" << endl;
                for (const auto& item : selectedRestaurant->getMenu()) {
                    cout << "菜名: " << item.first << ", 价格: " << item.second << endl;
                }

                vector<pair<string, double>> itemsOrdered;
                string itemName;
                cout << "请输入您要点的菜名（输入 'done' 结束点菜）: ";
                while (cin >> itemName && itemName != "done") {
                    if (selectedRestaurant->getMenu().count(itemName) > 0) {
                        itemsOrdered.emplace_back(itemName, selectedRestaurant->getMenu().at(itemName));
                        cout << itemName << " 已添加到您的订单。" << endl;
                    } else {
                        cout << "未找到该菜品，请重新输入。" << endl;
                    }
                    cout << "继续点菜或输入 'done' 结束点菜: ";
                }

                Order newOrder(customer.getId(), selectedRestaurant->getId(), selectedRestaurant->getName(), customer.getName(),
                               itemsOrdered, customer.getTelephoneNumber(), customer.getCoordinates());
                newOrder.setOrderStatus(Order::Status::Pending);
                /*
                  customer.addOrder(newOrder);
                 更新customer的订单历史，之前的方式不能全局更新
                 */
                auto customer_orders = customer.getOrderHistory();
                customer_orders.push_back(newOrder);
                customer.setOrderHistory(customer_orders);

                //更新餐厅订单
                selectedRestaurant->addPendingOrder(newOrder);
                //selectedRestaurant->addHistoryOrder(newOrder);   删除了这句，在配送员配送完订单后再添加到历史订单会更好些
                for(int i = 0; i < restaurantAdminList.size();i++ )
                {
                    if (restaurantAdminList[i].getManagedRestaurant().getId()== selectedRestaurant->getId())
                        restaurantAdminList[i].setManagedRestaurant(*selectedRestaurant);
                }

                cout << "订单已创建，状态:待处理(Pending)。" << endl;
                break;
            }

            case 3: {
                const vector<Order>& orderHistory = customer.getOrderHistory();
                cout << endl << "----------历史订单----------" << endl;
                if (orderHistory.empty()) {
                    cout << "您还没有历史订单。" << endl;
                } else {
                    for (const auto& order : orderHistory) {
                        order.printOrderInfo();  // 使用 Order 类的 printOrderInfo 方法
                    }
                }
                cout << "----------------------------" << endl;
                cout << "按回车键返回上一级菜单...";
                getchar();
                getchar(); // 等待用户按回车
                system("cls");//清屏操作，美化一下
                break;
            }

            case 4:
                return;
            default: {
                cout << "输入错误，请重新输入。" << endl;
                goto A;
            }
        }
    }

}
