

#include <iostream>
#include "ALL_FUNCTION.h"

int main() {

    vector<Customer> customerList;
    vector<DeliveryPerson> deliveryPersonList;
    vector<RestaurantAdmin> restaurantAdminList;
    vector<Restaurant> restaurantList;


    while (true) {
        cout << "欢迎来到NUIST校园外卖平台！" << endl;
        cout << "1: 注册" << endl;
        cout << "2: 登录" << endl;
        cout << "3: 退出" << endl;
        cout << "请选择操作：";

        //读入文件信息
        In_Customer(customerList);
        In_deliveryperson(deliveryPersonList);
        In_restautant(restaurantList);
        In_restaurantadmin(restaurantAdminList);

        int choice;
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                Register(customerList, deliveryPersonList, restaurantAdminList, restaurantList);
                break;
            case 2:
                login(customerList, deliveryPersonList, restaurantAdminList, restaurantList);
                break;
            case 3:

                cout << "谢谢使用，再见！" << endl;
                return 0;
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
    }
}

