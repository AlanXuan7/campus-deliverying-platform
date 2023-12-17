//created by 杜冉 2023/11/25
#include "ALL_FUNCTION.h"
#include <iostream>
#include <vector>

using namespace std;


//-------------------------------------------------------注册------------------------------------------------------------


//使用时将存储信息的容器传入
void Register( vector<Customer> &customerlist,vector<DeliveryPerson> &deliverylist,vector<RestaurantAdmin> &adminlist, vector<Restaurant> &restaurantlist){

    cout << "----------------------------------------" << endl;
    cout << "\t请选择注册类型"<<endl
         <<"1: 用户"<<endl
         <<"2: 配送员"<<endl
         <<"3: 餐厅管理员"<<endl
         <<"4: 回到主菜单"<<endl;

    int choice;
    cin>>choice;
    system("cls");//清屏操作，美化一下
    switch(choice){
        //用户:
        case 1:{
            A:
            cout << "\t输入注册信息"<<endl;
            string id,name,gender,password,telephone_number;
            int age;
            double balance,x,y;


            cout << "学号:" ;
            cin >> id;
            while(!Protectid(id)){
                cin >> id;
            }
            //查找是否注册//---------
            for (const auto& it: customerlist){
                if(id == it.getId()) {
                    cout << "该学号已被注册！请重新输入！！";
                    goto A;
                }
            }

            cout << "姓名:";
            cin >> name;
            //---------
            while(!Protectname(name)){
                cin >> name;
            }
            cout << "年龄:";
            cin >> age;
            //----------
            while(!Protectid(id)){
                cin >> age;
            }
            cout << "性别:";
            cin >> gender;
            cout << "位置(同行分别输入x和y):";
            cin >> x >> y;
            cout << "密码:";
            cin >> password;
            //----------
            while(!Protectpassword(password)){
                cin >> password;
            }
            cout << "手机号码:";
            cin >> telephone_number;
            //----------
            while(!Protectid(telephone_number)){
                cin >> telephone_number;
            }
            cout << "账户余额:";
            cin >> balance;

            Customer a(id, name, age, gender, Coordinate(x,y), password, telephone_number, balance);



            customerlist.push_back(a);
            system("cls");//清屏操作，美化一下
            cout << "恭喜您！用户注册成功！！" << endl;
            break;
        }
            //外卖员:
        case 2:{
            B:
            cout << "\t输入注册信息"<<endl;
            string id,name,gender,password,telephone_number;
            int age;
            double balance,x,y;

            cout << "学号:" ;
            cin >> id;
            while(!Protectid(id)){
                cin >> id;
            }
            //查找是否注册//---------
            for (const auto& it: deliverylist){
                if(id == it.getId()) {
                    cout << "该学号已被注册！请重新输入！！";
                    goto B;
                }
            }
            cout << "姓名:";
            cin >> name;
            //---------
            while(!Protectname(name)){
                cin >> name;
            }
            cout << "年龄:";
            cin >> age;
            //----------
            while(!Protectid(id)){
                cin >> age;
            }
            cout << "性别:";
            cin >> gender;
            cout << "位置(同行分别输入x和y):";
            cin >> x >> y;
            cout << "密码:";
            cin >> password;
            //----------
            while(!Protectpassword(password)){
                cin >> password;
            }
            cout << "手机号码:";
            cin >> telephone_number;
            //----------
            while(!Protectid(telephone_number)){
                cin >> telephone_number;
            }
            cout << "账户余额:";
            cin >> balance;
            DeliveryPerson a(id, name, age, gender, Coordinate(x,y), password, telephone_number, balance);


            deliverylist.push_back(a);
            system("cls");//清屏操作，美化一下
            cout << "恭喜您！外卖员注册成功！！" << endl;
            break;
        }

            //餐厅管理员:
        case 3:{
            C:
            cout << "\t输入注册信息"<<endl;
            string id,name,gender,password,telephone_number;
            int age;
            double balance,x,y;

            cout << "学号:" ;
            cin >> id;
            while(!Protectid(id)){
                cin >> id;
            }
            //查找是否注册//---------
            for (const auto& it: adminlist){
                if(id == it.getId()) {
                    cout << "该学号已被注册！请重新输入！！";
                    goto C;
                }
            }
            cout << "姓名:";
            cin >> name;
            //---------
            while(!Protectname(name)){
                cin >> name;
            }
            cout << "年龄:";
            cin >> age;
            //----------
            while(!Protectid(id)){
                cin >> age;
            }
            cout << "性别:";
            cin >> gender;
            cout << "位置(同行分别输入x和y):";
            cin >> x >> y;
            cout << "密码:";
            cin >> password;
            //----------
            while(!Protectpassword(password)){
                cin >> password;
            }
            cout << "手机号码:";
            cin >> telephone_number;
            //----------
            while(!Protectid(telephone_number)){
                cin >> telephone_number;
            }
            cout << "账户余额:";
            cin >> balance;

            Coordinate Admin_loc(x,y);
            system("cls");//清屏操作，美化一下
            cout<<"个人信息已录入，请注册餐厅信息："<<endl
                <<"请输入编号、名称、位置、坐标x与y、营业时间:"<<endl;

            string Rest_id, Rest_name, Rest_location, Rest_time;
            double Rest_x, Rest_y;


//////////////////////////////////////

            D:
            cout << "餐厅编号:";
            cin >> Rest_id;
            for(auto &it: restaurantlist){
                if (it.getId() == Rest_id){
                    cout << "该餐厅编号已被注册！请重新输入！！";
                    goto D;
                }
            }
///////////////////////////////////////////////
            E:

            cout << "餐厅名称:";
            cin >> Rest_name;
            for(auto &it: restaurantlist){
                if (it.getName() == Rest_name){
                    cout << "该餐厅名称已被注册！请重新输入！！";
                    goto E;
                }
            }
//////////////////////////////////////////////////////
            cout << "餐厅地理位置:";
            cin >> Rest_location;
            cout << "餐厅位置坐标(同行输入):";
            cin >> Rest_x >> Rest_y;
            cout << "餐厅营业时间:";
            cin >> Rest_time;
            //---------
            while(!Protecttime(Rest_time)){
                cout << "营业时间格式错误！请重新输入！！";
                cin >> Rest_time;
            }

            //Restaurant类初始化
            Coordinate Rest_loc(Rest_x, Rest_y);
            Restaurant myRestaurant(Rest_id, Rest_name, Rest_location, Rest_loc, Rest_time);


            //初始化菜单
            cout << "输入菜单中的菜名和价格（输入null与0表示结束）"<< endl;
            string food;
            double price;
            cin >> food >> price;
            while(food != "null"){
                myRestaurant.addMenuItem(food, price);
                cin >> food >> price;
            }

            //将注册好的餐厅信息添加到餐厅列表中
            restaurantlist.push_back(myRestaurant);

            RestaurantAdmin admin( id, name, age, gender, Admin_loc, password,telephone_number, balance, myRestaurant);
            //查找是否注册
            for(auto &it: adminlist){
                if(id == it.getId())
                {cout<<"该用户名已被注册！请重新注册！！";
                    goto A;}
            }
            //将注册好的管理员信息注册到管理员列表中
            adminlist.push_back(admin);
            system("cls");//清屏操作，美化一下
            cout << "餐厅信息和餐厅管理员信息已注册完毕！ 请等待超级管理员授权！！" << endl;
            break;
        }
            //default:
        case 4:break;
        default:{
            cout<<"输入错误，请重新输入！";
            goto A;
        }
    }
}



//-------------------------------------------------------登陆-------------------------------------------------------------







void login(vector<Customer> &customerlist,vector<DeliveryPerson> &deliverylist,vector<RestaurantAdmin> &adminlist, vector<Restaurant> &restaurantlist){
    B:
    cout<<"请选择登录类型："<<endl
        <<"1: 用户"<<endl
        <<"2: 配送员"<<endl
        <<"3: 餐厅管理员"<<endl
        <<"4: 回到主菜单"<<endl;
    int choice;
    cin>>choice;
    system("cls");//清屏操作，美化一下
    switch(choice) {


//customer:
        case 1: {
            cout << "请输入用户名和密码：" << endl;
            string id, password;
            string _password;
            cin >> id >> password;
            bool flag = 0, login = 0;
            for (auto beg = customerlist.begin(), end = customerlist.end(); beg != end; beg++) {
                auto r = *beg;
                if (r.getId() == id) {
                    flag = 1;
                    _password = r.getPassword();
                    break;
                }
            }
            if (flag == 0) {
                system("cls");//清屏操作，美化一下
                cout << "没有此用户,请返回登陆界面！！" << endl;
                goto B;
            } else
                while (1) {
                    if (password == _password) {
                        login = 1;
                        break;
                    } else {
                        cout << "密码错误，请重新输入：";
                        cin >> password;
                    }
                }

            if (login == 1) {
                system("cls");//清屏操作，美化一下
                cout << "顾客账户登陆成功！！"  << endl;
                for(auto& this_customer:customerlist){
                    if( this_customer.getId() == id){
                        Customer_Function(restaurantlist, this_customer,adminlist);//进入用户界面
                    }
                }
            }
            break;
        }


//deliveryperson:
        case 2: {
            system("cls");//清屏操作，美化一下
            cout << "请输入用户名和密码：" << endl;
            string id, password;
            string _password;
            cin >> id >> password;
            DeliveryPerson a;
            bool flag = 0, login = 0;
            for (auto beg = deliverylist.begin(), end = deliverylist.end(); beg != end; beg++) {
                auto r = *beg;
                if (r.getId() == id) {
                    a = r;
                    flag = 1;
                    _password = r.getPassword();
                    break;
                }
            }
            if (flag == 0) {
                system("cls");//清屏操作，美化一下
                cout << "没有此配送员,返回登陆界面" << endl;
                goto B;
            }
            else
                while (1) {
                    if (password == _password) {
                        login = 1;
                        break;
                    }
                    else {
                        cout << "密码错误，请重新输入：" ;
                        cin >> password;
                    }
                }
            if (login == 1) {
                system("cls");//清屏操作，美化一下
                cout << "配送员账户登陆成功！！" << endl;
                for(auto &delivery_person : deliverylist)
                    if(delivery_person.getId() == id)
                        delivery_func(delivery_person,restaurantlist,adminlist,customerlist); //进入配送员界面
            }
            break;
        }

//admin:
        case 3: {
            system("cls");//清屏操作，美化一下
            cout << "请输入用户名和密码：" << endl;
            string id, password;
            string _password;
            cin >> id >> password;
            RestaurantAdmin admin;
            bool flag = 0, login = 0;
            for (auto beg = adminlist.begin(), end = adminlist.end(); beg != end; beg++) {
                auto r = *beg;
                if (r.getId() == id) {
                    flag = 1;
                    if(r.getPower() == false){
                        system("cls");//清屏操作，美化一下
                        cout << "该用户还未被授权！！请联系超级管理员！！" << endl;
                        goto B;
                    }
                    _password = r.getPassword();
                    break;
                }
            }
            if (flag == 0) {
                system("cls");//清屏操作，美化一下
                cout << "没有此管理员,返回登陆界面" << endl;
                goto B;
            }
            else
                while (1) {
                    if (password == _password) {
                        login = 1;
                        break;
                    }
                    else {
                        system("cls");//清屏操作，美化一下
                        cout << "密码错误，请重新输入：" << endl;
                        cin >> password;
                    }
                }
            if (login == 1) {
                system("cls");//清屏操作，美化一下
                cout << "管理员账户登陆成功！！" << endl;
                for(auto &restaurant_admin : adminlist)
                    if(restaurant_admin.getId() == id)
                        //修改
                        RestaurantAdmin_Function(restaurant_admin,restaurantlist,customerlist);//进入管理员界面
            }
            break;
        }
        case 4:break;
            //default:
        default : {
            cout << "输入错误，请重新输入" << endl;
            goto B;
        }
    }
}