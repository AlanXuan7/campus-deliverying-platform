#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

//(附加)位置坐标类Coordinate
class Coordinate {
public:
    //默认构造函数
    Coordinate(double x = 0.0, double y = 0.0);

    //获取坐标值
    double getX() const;
    double getY() const;

    //设置坐标值
    void setX(const double& x);
    void setY(const double& y);

private:
    double x;
    double y;

};
//重载
ostream &operator <<(ostream &out, Coordinate &c){
    out << c.getX() << " " << c.getY();
    return out;
}

istream &operator >>(istream &in, Coordinate &c){
    double x, y;
    in >> x >> y;
    c.setX(x);
    c.setY(y);
    return in;
}
//基本用户类User
class User{
public:
    // 构造函数 学号、姓名、年龄、性别、位置坐标、密码、手机号码、余额初始化为0
    User(){} //无参构造器
    User(const string& id, const string& name, int age, const string& gender,const Coordinate& coordinates,
         const string& password, const string& telephoneNumber, double balance = 0.0);

    //虚析构函数（以便后面先析构派生类再析构基类）
    virtual ~User();

    //Getter 和 Stter 方法
    string getId() const;
    void setId(const  string& id); //&引用，无需复制字符串

    string getName() const;
    void setName(const string& name);

    int getAge() const;
    void setAge(int age);

    string getGender() const;
    void setGender(const string& gender);

    Coordinate getCoordinates() const;
    void setCoordinates(const Coordinate& coorfinates);

    string getTelephoneNumber() const;
    void setTelephoneNumber(const string& telephoneNumber);

    string getPassword() const;
    void setPassword(const string& password);

    double getBalance() const;
    void setBalance(const double &balance);

private:
    string id;                  // 学号
    string name;                // 姓名
    int age;                    // 年龄
    string gender;              // 性别
    Coordinate coordinates;     // 位置坐标
    string password;            // 密码
    string telephoneNumber;     // 手机号码
    double balance;             // 账户余额

};

#endif // USER_H