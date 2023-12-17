#include<iostream>
#include<fstream>
#include<cassert>
#include<vector>
#include "Customer.h"
#include "DeliveryPerson.h"
#include "Order.h"
#include "Restaurant.h"
#include "RestaurantAdmin.h"
#include "User.h"
using namespace std;
void Out_Customer(vector<Customer> customerlist){
    fstream file("cd\\Users\\alan\\Desktop\\Customer.txt", ios::out);//此处制定一个路径, 存放Customer中除了历史的部分
    if(file.is_open()) cout << "正在写入文件"<<endl;
    else assert(file.is_open());
    for(auto &it : customerlist){
        file << it.getId()
             <<" "<< it.getName()
             <<" "<< it.getAge()
             <<" "<< it.getGender();
        Coordinate c = it.getCoordinates();
        file
                <<" "<< c
                <<" "<< it.getPassword()
                <<" "<< it.getTelephoneNumber()
                <<" "<< it.getBalance()
                <<" "<< it.getOrderHistory().size();
        for (auto &ite : it.getOrderHistory()){
            file << ite;
        }
        file
                <<" "<< it.getRating()
                <<endl;
    }
    file.close();
    cout << "文件写入成功！" <<endl;
}
void In_Customer(vector<Customer> &customerlist){
    fstream file("cd\\Users\\alan\\Desktop\\Customer.txt", ios::in);
    if(file.is_open()) cout << "正在读取文件"<<endl;
    else assert(!file.is_open());
    string str;
    int i;
    double d;
    while(file.peek() != EOF){
        Customer it;
        file >> str; it.setId(str);
        file >> str; it.setName(str);
        file >> i;   it.setAge(i);
        file >> str; it.setGender(str);
        Coordinate c;
        file >> c;   it.setCoordinates(c);
        file >> str; it.setPassword(str);
        file >> str; it.setTelephoneNumber(str);
        file >> d;   it.setBalance(d);
        file >> i;
        Order o;
        for(int j = 0; j < i; i++){
            file  >> o;
            it.addOrder(o);
        }
        file >> d;   it.updateRating(d);
        customerlist.push_back(it);
    }
    file.close();
    cout << "文件读取成功！" <<endl;
}
void Out_deliveryperson(vector<DeliveryPerson> list){
    fstream file("cd\\Users\\alan\\Desktop\\deliveryperson.txt", ios::out);
    if(file.is_open()) cout << "正在写入文件"<<endl;
    else assert(!file.is_open());
    for(auto &it : list){
        file << it.getId()
             <<" "<< it.getName()
             <<" "<< it.getAge()
             <<" "<< it.getGender();
        Coordinate c = it.getCoordinates();
        file
                <<" "<< c
                <<" "<< it.getPassword()
                <<" "<< it.getTelephoneNumber()
                <<" "<< it.getBalance();
        //输入记录数组
        int i;
        i = it.getDeliveryRecords().size();
        file <<" "<< i;
        for(auto &j : it.getDeliveryRecords()){
            file <<" "<< j;
        }
        file <<" "<< it.getTotalIncome()
             <<" "<< it.getRating()
             <<endl;
    }
    file.close();
    cout << "文件写入成功！" <<endl;
}
void In_deliveryperson(vector<DeliveryPerson> &list){
    fstream file("cd\\Users\\alan\\Desktop\\deliveryperson.txt", ios::in);
    if(file.is_open()) cout << "正在读取文件"<<endl;
    else assert(!file.is_open());
    string str;
    int i;
    double d;
    Order order;
    Coordinate c;
    while(file.peek() != EOF){
        DeliveryPerson it;
        file >> str; it.setId(str);
        file >> str; it.setName(str);
        file >> i;   it.setAge(i);
        file >> str; it.setGender(str);
        file >> c;   it.setCoordinates(c);
        file >> str; it.setPassword(str);
        file >> str; it.setTelephoneNumber(str);
        file >> d;   it.setBalance(d);
        //记录数组录入
        file >> i;
        for(int j = 0; j < i; j++){
            file >> str;
            it.addDeliveryRecord(order);
        }
        file >> d;   it.addIncome(d);
        file >> d;   it.updateRating(d);
        list.push_back(it);
    }
    file.close();
    cout << "文件读取成功！" <<endl;
}
void Out_restaurant(vector<Restaurant> list){
    fstream file("cd\\Users\\alan\\Desktop\\restaurant.txt", ios::out);
    if(file.is_open()) cout << "正在写入文件"<<endl;
    else assert(!file.is_open());
    file << list.size() << endl;
    for(auto &it : list){
        file << it << endl;
    }
    file.close();
    cout << "文件写入成功！" <<endl;
}
void In_restautant(vector<Restaurant> &list){
    fstream file("cd\\Users\\alan\\Desktop\\restaurant.txt", ios::in);
    if(file.is_open()) cout << "正在读取文件"<<endl;
    else assert(!file.is_open());
    int n;
    Restaurant it;
    file >> n;
    for(int i = 0; i < n; i++){
        file >> it;
        list.push_back(it);
    }
    file.close();
    cout << "文件读取成功！" <<endl;
}
void Out_restaurantadmin(vector<RestaurantAdmin> list){
    fstream file("cd\\Users\\alan\\Desktop\\restaurantadmin.txt", ios::out);
    if(file.is_open()) cout << "正在写入文件"<<endl;
    else assert(!file.is_open());
    //
    file << list.size() << endl;
    for(auto &it : list){
        file << it << endl;
    }
    //
    file.close();
    cout << "文件写入成功！" <<endl;
}
void In_restaurantadmin(vector<RestaurantAdmin> &list){
    fstream file("cd\\Users\\alan\\Desktop\\restaurantadmin.txt", ios::in);
    if(file.is_open()) cout << "正在读取文件"<<endl;
    else assert(!file.is_open());
    //
    int n;
    RestaurantAdmin it;
    file >> n;
    for(int i = 0; i < n; i++){
        file >> it;
        list.push_back(it);
    }
    //
    file.close();
    cout << "文件读取成功！" <<endl;
}
