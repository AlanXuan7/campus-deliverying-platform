#include "RestaurantAdmin.h"
#include <iostream>
using namespace std;

RestaurantAdmin::RestaurantAdmin(const string& id, const string& name, int age, const string& gender,
                                 const Coordinate& coordinates, const string& password, const string& telephoneNumber,
                                 double balance, Restaurant managedRestaurant)
        : User(id, name, age, gender, coordinates, password, telephoneNumber, balance),
          managedRestaurant(managedRestaurant), power(false) {
}

RestaurantAdmin::~RestaurantAdmin() {
    // 需要注意的是，这里不应该删除 managedRestaurant，
    // 因为 RestaurantAdmin 不拥有这个对象的所有权
}

bool RestaurantAdmin::getPower() {
    return power;
}

Restaurant RestaurantAdmin::getManagedRestaurant()const{
    return managedRestaurant;
}

void RestaurantAdmin::setManagedRestaurant(Restaurant restaurant) {
    managedRestaurant = restaurant;
}
