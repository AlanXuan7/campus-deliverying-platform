#include <iostream>
#include <vector>
#include "Restaurant.h"
#include "Order.h"
#include "Customer.h"
#include "RestaurantAdmin.h"
#include "DeliveryPerson.h"
using namespace std;

void accept_Order(DeliveryPerson &man,vector<Restaurant> &restaurants,vector<RestaurantAdmin> &restaurantAdminList,vector<Customer> &Customerlists)
{
    //打印所有拥有待处理订单的餐厅
    int flag = 0; // 判断是否有拥有待处理订单的餐厅
    for (auto &restaurant : restaurants)
    {
        if (restaurant.getOrderPending().empty()) continue;

        flag = 1;
        cout << endl << "----------------餐厅信息----------------" << endl;
        cout << "餐厅编号： " << restaurant.getId() << endl
             << "餐厅名称： " << restaurant.getName() << endl
             << "餐厅位置： " << restaurant.getLocation() << endl
             << "评分： " << restaurant.getRating() << endl
             << "待处理订单数量：" << restaurant.getOrderPending().size() << endl;
        cout << "--------------------------" << endl;
    }

    if(flag == 0)
    {
        cout << endl << "当前没有可以配送的订单..." << endl;
        cout << "按回车键返回上一级菜单...";
        getchar();
        getchar(); // 等待用户按回车
        system("cls");//清屏操作，美化一下
        return;
    }

    //配送员选择餐厅
    cout << endl << "请输入餐厅编号：";
    string res_choice;
    cin >> res_choice;
    int res_loc;
    for (int i = 0; i < restaurants.size(); ++i)
        if(restaurants[i].getId() == res_choice)
            res_loc = i;

    //打印该餐厅的所有待处理订单的信息
    cout << endl << "----------当前餐厅待处理订单----------" << endl;
    for(auto &res_order : restaurants[res_loc].getOrderPending())
    {
        res_order.printOrderInfo();
        cout << "--------------------------" << endl;
    }


    //配送员选择配送的订单
    cout << endl << "请输入你要接受的订单的编号：";
    string order_choice;
    cin >> order_choice;

    //更新订单信息
    vector<Order> update_pendingOrder = restaurants[res_loc].getOrderPending();
    for(auto &res_order : update_pendingOrder)
        if(res_order.getOrderId() == order_choice)
        {
            res_order.setOrderStatus(Order::Status::InTransit);    //设置订单状态
            //将订单插入配送员的配送记录中
            auto delivery_record = man.getDeliveryRecords();
            delivery_record.push_back(res_order);
            man.setDeliveryRecords(delivery_record);

            //更新顾客订单信息
            for(auto &customer : Customerlists)
            {
                if(customer.getName() == res_order.getCustomerName())
                {
                    auto customer_records = customer.getOrderHistory();
                    for(auto &customer_record : customer_records)
                        customer_record.setOrderStatus(Order::Status::InTransit);
                    customer.setOrderHistory(customer_records);
                }
            }
        }

    //更新餐厅列表里的餐厅信息
    restaurants[res_loc].setPendingOrder(update_pendingOrder);

    //更新对应餐厅管理员里的餐厅信息
    for(auto &res_admin : restaurantAdminList)
        if(res_admin.getManagedRestaurant().getId() == restaurants[res_loc].getId())
            res_admin.setManagedRestaurant(restaurants[res_loc]);

}

void end_Order(DeliveryPerson &man,vector<Restaurant> &restaurants,vector<RestaurantAdmin> &restaurantAdminList,vector<Customer> &Customerlists)
{
    cout << endl << "--------当前待处理的订单--------" << endl;
    if(man.getDeliveryRecords().size() == 0)
    {
        cout << "当前无配送订单..." << endl;
        cout << "按回车键返回上一级菜单...";
        getchar();
        getchar(); // 等待用户按回车
        system("cls");//清屏操作，美化一下
        return;
    }
    //打印配送员当前处理的订单
    int pending = 0; //判断 delivery_order 中是否有待处理订单
    for (auto delivery_order : man.getDeliveryRecords())
    {
        if(delivery_order.getOrderStatus() == Order::Status::Completed) continue;
        pending = 1;
        delivery_order.printOrderInfo();
    }

    //若订单中均为已完成订单，则退出
    if(!pending)
    {
        cout << "当前无可配送订单..." << endl;
        cout << "按回车键返回上一级菜单...";
        getchar();
        getchar(); // 等待用户按回车
        system("cls");//清屏操作，美化一下
        return;
    }

    //配送员结束订单，订单状态的更新
    cout << endl <<"请输入要结束的订单编号：";
    string order_choice;
    string res_Id;
    cin >> order_choice;

    //骑手历史订单更新
    auto Order_records = man.getDeliveryRecords();
    string res_name_of_order; //获取订单的餐厅编号
    string cus_name_of_order; //获取订单的顾客编号
    for (auto &delivery_order : Order_records)
    {
        if(delivery_order.getOrderId() == order_choice)
        {
            //更新订单信息
            delivery_order.setOrderStatus(Order::Status::Completed);
            //骑手获得收益
            man.addIncome(delivery_order.getTotalAmount());

            res_name_of_order = delivery_order.getRestaurantId();
            cus_name_of_order = delivery_order.getCustomerName();

            //更新配送员的配送记录
            man.setDeliveryRecords(Order_records);
        }
    }

    //顾客订单更新
    for(auto &customer : Customerlists)
    {
        if(cus_name_of_order == customer.getId())
        {
            auto customer_orders = customer.getOrderHistory();
            for(auto &customer_order : customer_orders)
                if(customer_order.getOrderId() == order_choice)
                    customer_order.setOrderStatus(Order::Status::Completed);
            customer.setOrderHistory(customer_orders);
        }
    }

    //餐厅更新
    for(auto &restaurant : restaurants)
    {
        //根据订单编号找到所属餐厅
        if(res_name_of_order == restaurant.getId())
        {
            //更新该餐厅中的订单状态
            auto res_pendingOrder = restaurant.getOrderPending();
            for(auto &pendingOrder : res_pendingOrder)
                if(pendingOrder.getOrderId() == order_choice)
                {
                    pendingOrder.setOrderStatus(Order::Status::Completed);
                    //历史订单更新
                    auto history_Order = restaurant.getOrderHistory();
                    history_Order.push_back(pendingOrder);
                    restaurant.setHistoryOrder(history_Order);
                }
            //待处理订单更新
            for(int i = 0; i < res_pendingOrder.size(); i++)
                if(res_pendingOrder[i].getOrderId() == order_choice)
                {
                    res_pendingOrder.erase(res_pendingOrder.begin() + i);
                    restaurant.setPendingOrder(res_pendingOrder);
                }
            //更新该餐厅所属的管理员中的ManagedRestaurant对象
            for(auto &admin : restaurantAdminList)
                if(admin.getManagedRestaurant().getId() == restaurant.getId())
                {
                    admin.setManagedRestaurant(restaurant);
                }
        }
    }
}

void delivery_func(DeliveryPerson &man,vector<Restaurant> &restaurants,vector<RestaurantAdmin> &restaurantAdminList,vector<Customer> &Customerlists)
{
    A:
    {
        cout<< endl <<"请选择配送员功能："<<endl
            <<"1: 接受/结束订单"<<endl
            <<"2: 查看配送收入和个人评分"<<endl
            <<"3: 查看个人配送记录"<<endl
            <<"4: 回到主菜单" << endl
            <<"请输入您的选择：" ;
        int choice;
        cin>>choice;
        system("cls");//清屏操作，美化一下
        switch (choice)
        {
            case 1:
            {
                B:
                {
                    cout << endl << "--------派送订单--------" << endl;
                    cout << "1：接受订单" << endl;
                    cout << "2：结束订单" << endl;
                    cout << "3：返回上一级菜单" << endl;
                    cout << "请输入您的选择：";

                    int choice_sec;
                    cin >> choice_sec;
                    system("cls");//清屏操作，美化一下
                    switch (choice_sec)
                    {
                        //接受订单
                        case 1:
                        {
                            accept_Order(man,restaurants,restaurantAdminList,Customerlists);
                            goto A;
                        }
                            //结束订单
                        case 2:
                        {
                            end_Order(man,restaurants,restaurantAdminList,Customerlists);
                            goto A;
                        } //case2
                        case 3:
                            goto A;
                        default:
                            cout << "输入错误，重新输入..." << endl << endl;
                            goto B;
                    }
                }
            } //case1

            case 2:
            {
                cout << endl;
                cout << "-------------------" << endl;
                cout << "总收入：" << man.getTotalIncome() << endl;
                cout << "评分：" << man.getRating() << endl;
                cout << "-------------------" << endl;
                getchar();
                cout << "请按回车键返回上一级菜单...";
                getchar();
                system("cls");//清屏操作，美化一下
                goto A;
            }
            case 3:
            {
                if(man.getDeliveryRecords().size() == 0)
                {
                    cout << endl << "当前无配送记录..." << endl;
                    cout << "按回车键返回上一级菜单...";
                    getchar();
                    getchar(); // 等待用户按回车
                    system("cls");//清屏操作，美化一下
                }
                for(auto order_record : man.getDeliveryRecords())
                {
                    order_record.printOrderInfo();
                    cout << "------------------" << endl;
                }
                goto A;
            }
            case 4:
                return;
            default:
                cout << "输入错误，请重新输入..." << endl;
                goto A;
        }
    }
}