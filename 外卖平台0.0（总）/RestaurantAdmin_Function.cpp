//
// Created by 李昆峰 on 2023/12/10.
//
#include "RestaurantAdmin.h"
#include "Customer.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

//餐厅信息更新
void updateRestaurantInfo(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    cout << endl << "----------餐厅信息更新----------" << endl;
    string name;
    cout << "餐厅名称: "; cin >> name;

    string location;
    cout << "餐厅位置: "; cin >> location;

    double x, y;
    cout << "餐厅坐标: "; cin >> x >> y;
    Coordinate coordinates(x,y);

    string openingHours;
    cout << "营业时间: "; cin >> openingHours;

    //餐厅列表信息更新
    for(auto &restaurant : restaurants)
    {
        if(Admin.getManagedRestaurant().getId() == restaurant.getId())
        {
            restaurant.setName(name);
            restaurant.setCoordinates(coordinates);
            restaurant.setLocation(location);
            restaurant.setOpeningHours(openingHours);
            Admin.setManagedRestaurant(restaurant);
            break;
        }
    }

    cout << "信息更新成功！" << endl;
    cout << "--------------------------" << endl;
    getchar();
    cout << "请按回车键返回上一级菜单...";
    getchar();
}

//添加菜品
void addRestaurantMenuItem(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    A:
    {
        cout << endl << "----------添加菜品----------" << endl;

        string itemName;
        cout << "名称: "; cin >> itemName;
        if(Admin.getManagedRestaurant().getMenu().count(itemName) != 0) {
            cout << "该菜品已存在，请重新输入..." << endl;
            goto A;
        }
        else{
            double price;
            cout << "价格: "; cin >> price;

            for(auto &restaurant : restaurants)
            {
                if(Admin.getManagedRestaurant().getId() == restaurant.getId())
                {
                    restaurant.addMenuItem(itemName,price);
                    Admin.setManagedRestaurant(restaurant);
                    break;
                }
            }

            cout << "菜品添加成功！" << endl;

            while(true)
            {
                cout << "是否继续添加?(Y/N): ";
                char choice;
                cin >> choice;
                if(choice == 'Y') goto A;
                else if(choice == 'N') return;
                else cout << "输入错误，请重新输入..." << endl;
            }
        }
    }
}

//修改菜品
void updateRestaurantMenuItem(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    string itemName;
    double price;
    for(auto &restaurant : restaurants)
    {
        if(Admin.getManagedRestaurant().getId() == restaurant.getId())
        {
            A:
            {
                cout << endl << "----------修改菜品----------" << endl;
                map<string,double> update_menu = restaurant.getMenu();
                if(update_menu.size() == 0)
                {
                    cout << "当前菜单中没有菜品..." << endl;
                    cout << "---------------------------" << endl;
                    getchar();
                    cout << "按回车键返回上一级菜单...";
                    getchar();
                    return;
                }
                cout << "名称：";
                cin >> itemName;
                if (update_menu.count(itemName) != 0) {
                    cout << "价格：";
                    cin >> price;
                    update_menu[itemName] = price;
                    restaurant.setMenu(update_menu);
                    Admin.setManagedRestaurant(restaurant);
                    cout << "修改成功！" << endl;
                    cout << "---------------------------" << endl;

                    getchar();
                    cout << "请按回车键返回上一级菜单...";
                    getchar();
                    return;
                }
                else {
                    cout << "未找到该菜品，请重新输入..." << endl;
                    goto A;
                }
            }
        }
    }
}

//菜品删除
void removeRestaurantMenuItem(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    for(auto &restaurant : restaurants)
    {
        if(Admin.getManagedRestaurant().getId() == restaurant.getId())
        {
            A:
            {
                cout << endl << "----------菜品删除----------" << endl;
                auto update_menu = Admin.getManagedRestaurant().getMenu();
                string itemName;
                if(update_menu.size() == 0)
                {
                    cout << "当前菜单中没有菜品，无法删除..." << endl;
                    cout << "---------------------------" << endl;
                    getchar();
                    cout << "按回车键返回上一级菜单...";
                    getchar();
                    return;
                }

                cout << "名称:";
                cin >> itemName;
                if (update_menu.count(itemName) != 0) {
                    Admin.getManagedRestaurant().removeMenuItem(itemName);
                    getchar();
                    cout << "删除成功!" << endl;

                    while(true)
                    {
                        cout << "是否继续删除?(Y/N): ";
                        char choice;
                        cin >> choice;
                        if(choice == 'Y') goto A;
                        else if(choice == 'N') return;
                        else cout << "输入错误，请重新输入..." << endl;
                    }
                }
                else {
                    cout << "未找到该菜品，请重新输入..." << endl;
                    goto A;
                }
            }
        }
    }
}

//获取餐厅菜单信息
void getRestaurantMenuInfo(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    cout << endl << "----------菜单信息----------" << endl;
    map<string,double> Menu = Admin.getManagedRestaurant().getMenu();
    if(Menu.size() == 0)
    {
        cout << "当前菜单未添加菜品..." << endl;
        cout << "---------------------------" << endl;

        while(true)
        {
            cout << "是否需要添加?(Y/N):" ;
            char choice;
            cin >> choice;
            if(choice == 'Y') addRestaurantMenuItem(Admin,restaurants);
            else if (choice == 'N') return;
            else cout << "输入错误，请重新输入..." << endl;
        }
    }
    map<string,double> :: iterator i;
    for(i = Menu.begin() ; i != Menu.end(); i++)
        cout << "名称: " << i->first
             << "\t价格: " << i->second << endl;
    cout << "---------------------------" << endl;

    getchar();
    cout << "按回车键返回上一级菜单...";
    getchar();
    return;
}

//更新餐厅菜单
void updateOrderInfo(RestaurantAdmin &Admin,vector<Restaurant> &restaurants, vector<Customer> &customerlist)
{
    cout << endl << "----------当前待处理订单----------" << endl;
    if (Admin.getManagedRestaurant().getOrderPending().size()) {
        for (int i = Admin.getManagedRestaurant().getOrderPending().size() - 1; i >= 0; i--) {
            vector<Order> pending_order = Admin.getManagedRestaurant().getOrderPending();
            pending_order[i].printOrderInfo();
        }
    }
    else {
        cout << "未查询到待处理订单..." << endl;
        cout << "--------------------------------" << endl;
        getchar();
        cout << "按回车键返回上一级菜单...";
        getchar();
        return;
    }
    cout << "--------------------------------" << endl;
    while (true)
    {
        for(auto &restaurant : restaurants)
        {
            if(Admin.getManagedRestaurant().getId() == restaurant.getId())
            {
                A:
                {
                    string updateID;
                    cout << endl << "请输入需要更新的订单的编号（输入-1退出）:";
                    cin >> updateID;

                    if (updateID == "-1") return;

                    B:
                    {
                        cout << endl << "修改订单的状态" << endl;
                        cout << "1: 接收订单" << endl
                             << "2: 制作完成" << endl;
                        cout << "请输入您的选择:";
                        int choice;
                        cin >> choice;

                        int flag = 0;   //标记是否找到订单
                        int location;   //记录订单位置
                        vector<Order> update_pendingOrder = restaurant.getOrderPending();
                        for (int i = 0; i < update_pendingOrder.size(); i++)
                        {
                            if (updateID == update_pendingOrder[i].getOrderId())
                            {
                                flag = 1;
                                location = i;
                                if (choice == 1)
                                {
                                    update_pendingOrder[location].setOrderStatus(Order::Status::Preparing);
                                    //餐厅列表中的餐厅更新
                                    restaurant.setPendingOrder(update_pendingOrder);
                                    //顾客订单信息更新
                                    for(auto customer : customerlist)
                                    {
                                        if(customer.getName() == update_pendingOrder[location].getCustomerName())
                                            customer.setOrderHistory(update_pendingOrder);
                                    }
                                    //餐厅管理员信息更新
                                    Admin.setManagedRestaurant(restaurant);
                                }
                                else if (choice == 2)
                                {
                                    update_pendingOrder[location].setOrderStatus(Order::Status::Prepared);
                                    //餐厅列表中的餐厅更新
                                    restaurant.setPendingOrder(update_pendingOrder);
                                    //顾客订单信息更新
                                    for(auto &customer : customerlist)
                                    {
                                        if(customer.getName() == update_pendingOrder[location].getCustomerName())
                                            customer.setOrderHistory(update_pendingOrder);
                                    }
                                    //餐厅管理员信息更新
                                    Admin.setManagedRestaurant(restaurant);
                                }
                                else
                                {
                                    cout << "输入错误，请重新输入..." << endl;
                                    goto B;
                                }
                            }
                        }
                        if (!flag)
                        {
                            cout << "未找到该订单，请重新输入" << endl;
                            goto A;
                        }
                    }
                }
            }
        }
    }
}

//获取餐厅信息
void getRestaurantInfo(RestaurantAdmin &Admin,vector<Restaurant> &restaurants)
{
    cout << endl << "----------餐厅信息----------" << endl;
    cout << "餐厅编号： " << Admin.getManagedRestaurant().getId() << endl
         << "餐厅名称： " << Admin.getManagedRestaurant().getName() << endl
         << "餐厅位置： " << Admin.getManagedRestaurant().getLocation() << endl
         << "营业时间： " << Admin.getManagedRestaurant().getOpeningHours() << endl
         << "评分： " << Admin.getManagedRestaurant().getRating() << endl;
    cout << "---------------------------" << endl;

    getchar();
    cout << "按回车键返回上一级菜单...";
    getchar();
    return;
    //}
}

//餐厅管理员功能界面
void RestaurantAdmin_Function(RestaurantAdmin &Admin,vector<Restaurant> &restaurants,vector<Customer> &customerlist)
{
    while(true)
    {
        cout << endl << "请选择管理员功能：" << endl
             << "1: 获取餐厅信息" << endl
             << "2: 更新餐厅信息" << endl
             << "3: 管理餐厅菜单" << endl
             << "4: 查看和更新订单状态" << endl
             << "5: 回到上一级菜单" << endl
             << "请输入您的选择：";
        int choice_main;
        cin >> choice_main;

        switch (choice_main) {
            case 1:
                getRestaurantInfo(Admin,restaurants);
                break;
            case 2:
                updateRestaurantInfo(Admin,restaurants);
                break;
            case 3:
                while (true)
                {
                    cout << endl << "----------餐厅菜单管理----------" << endl;
                    cout <<"1: 添加菜品" << endl
                         << "2: 编辑菜品" << endl
                         << "3: 删除菜品" << endl
                         << "4: 查看菜单" << endl
                         << "5: 回到上一个菜单" << endl
                         << "请输入您的选择：";
                    int choice_dish;
                    cin >> choice_dish;
                    if (choice_dish == 1) addRestaurantMenuItem(Admin,restaurants);
                    else if (choice_dish == 2) updateRestaurantMenuItem(Admin,restaurants);
                    else if (choice_dish == 3) removeRestaurantMenuItem(Admin,restaurants);
                    else if (choice_dish == 4) getRestaurantMenuInfo(Admin,restaurants);
                    else if (choice_dish == 5) break;
                    else cout << "输入错误，请重新输入..." << endl;
                }
                break;
            case 4:
                while (true)
                {
                    cout << endl << "----------餐厅订单管理----------" << endl;
                    cout << "1: 查看当前待处理订单" << endl
                         << "2: 更新订单状态" << endl
                         << "3: 查询历史订单" << endl
                         << "4: 回到上一级菜单" << endl
                         << "请输入您的选择：";
                    int choice_order;
                    cin >> choice_order;
                    if (choice_order == 1)  Admin.getManagedRestaurant().print_PendingOrder();
                    else if (choice_order == 2) updateOrderInfo(Admin,restaurants,customerlist);
                    else if (choice_order == 3) Admin.getManagedRestaurant().print_HistoryOrder();
                    else if (choice_order == 4) break;
                    else cout << "输入错误，请重新输入..." << endl;
                }
                break;
            case 5:
                return;
            default:
                cout << "输入错误，请重新输入..." << endl;
        }
    }
}
