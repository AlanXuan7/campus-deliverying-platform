
#include "User.h"


//(附加)位置坐标类Coordinate的函数实现
Coordinate::Coordinate(double x, double y) : x(x), y(y) {}

double Coordinate::getX() const{
    return x;
}

double Coordinate::getY() const{
    return y;
}

void Coordinate::setX(const double& x){
    this->x = x;
}

void Coordinate::setY(const double& y){
    this->y = y;
}


//基本用户类User的函数实现
User::User(const string& id, const string& name, int age, const string& gender,const Coordinate& coordinates,
           const string& password, const string& telephoneNumber, double balance) //函数申明中已指定balance = 0.0默认值
        : id(id), name(name), age(age), gender(gender),coordinates(coordinates),
          password(password), telephoneNumber(telephoneNumber), balance(balance)  {
    // 构造函数初始化所有成员变量
}

User::~User() {
    //虚析构函数，方便继承
}

string User::getId() const {
    return id;
}

void User::setId(const string& id) {
    this->id = id;
}

string User::getName() const {
    return name;
}

void User::setName(const string& name) {
    this->name = name;
}

int User::getAge() const{
    return age;
}

void User::setAge(int age){
    this->age = age;
}

string User::getGender() const{
    return gender;
}

void User::setGender(const string& gender){
    this->gender = gender;
}

Coordinate User::getCoordinates () const{
    return coordinates;
}

void User::setCoordinates (const Coordinate& coordinates) {
    this->coordinates = coordinates;
}

string User::getPassword() const{
    return password;
}

void User::setPassword(const string& password){
    this->password = password;
}

string User::getTelephoneNumber() const {
    return telephoneNumber;
}

void User::setTelephoneNumber(const string &telephoneNumber) {
    this->telephoneNumber = telephoneNumber;
}

double User::getBalance() const{
    return balance;
}

void User::setBalance(const double& balance){
    this->balance = balance;
}
