#ifndef RESTAURANT_ADMIN_H
#define RESTAURANT_ADMIN_H

#include "User.h"
#include "Restaurant.h"
#include <string>

using namespace std;

class RestaurantAdmin : public User {
public:
    // 构造函数
    RestaurantAdmin(){} //无参构造器
    RestaurantAdmin(const string& id, const string& name, int age, const string& gender, const Coordinate& coordinates,
                    const string& password, const string& telephoneNumber, double balance,
                    Restaurant managedRestaurant);


    // Destructor
    virtual ~RestaurantAdmin();

    bool getPower();

    // Getter 和 Setter 方法
    Restaurant getManagedRestaurant() const;
    void setManagedRestaurant(Restaurant restaurant);
    friend ostream& operator << (ostream &out, RestaurantAdmin it);
    friend istream& operator >> (istream &in, RestaurantAdmin &it);
private:
    Restaurant managedRestaurant; // 管理的餐厅
    bool power ; //超级管理员授权方可使用功能
};
ostream& operator << (ostream &out, RestaurantAdmin it){
    Coordinate c = it.getCoordinates();
    out << it.getId() << " "
        << it.getName() << " "
        << it.getAge() << " "
        << it.getGender() << " "
        << c << " "
        << it.getPassword() << " "
        << it.getTelephoneNumber() << " "
        << it.getBalance() << " "
        << it.managedRestaurant << endl;
    return out;
}
istream& operator >> (istream &in, RestaurantAdmin &it){
    string str;
    int i;
    double d;
    Coordinate c;
    Restaurant r;
    in >> str; it.setId(str);
    in >> str; it.setName(str);
    in >> i;   it.setAge(i);
    in >> str; it.setGender(str);
    in >> c;   it.setCoordinates(c);
    in >> str; it.setPassword(str);
    in >> str; it.setTelephoneNumber(str);
    in >> d;   it.setBalance(d);
    in >> it.managedRestaurant;
    return in;
}
#endif // RESTAURANT_ADMIN_H
