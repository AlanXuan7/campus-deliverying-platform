//
// Created by 邓志轩 on 2023/11/27.
//

#ifndef NUIST_TAKEOUT_PLATFORM_ALL_FUNCTION_H
#define NUIST_TAKEOUT_PLATFORM_ALL_FUNCTION_H

#include <iostream>
#include "User.h"
#include "Customer.h"
#include "Order.h"
#include "Restaurant.h"
#include "RestaurantAdmin.h"
#include "DeliveryPerson.h"

#include "Protected.cpp"
#include "In_Out_File.cpp"

//Register注册功能
void Register(vector<Customer> &customerlist, vector<DeliveryPerson> &deliverylist, vector<RestaurantAdmin> &adminlist,
              vector<Restaurant> &restaurantlist);

//Login登陆功能
void login(vector<Customer> &customerlist, vector<DeliveryPerson> &deliverylist, vector<RestaurantAdmin> &adminlist,
           vector<Restaurant> &restaurantlist);

//Customer_Function基础用户功能
void Customer_Function(vector<Restaurant> &restaurants, Customer &customer,vector<RestaurantAdmin> &restaurantAdminList);

//Delivery_Function外卖员功能
void delivery_func(DeliveryPerson &man,vector<Restaurant> &restaurants,vector<RestaurantAdmin> &restaurantAdminList,vector<Customer> &customerlist);

//RestaurantAdmin_Function餐厅管理员功能
void RestaurantAdmin_Function(RestaurantAdmin &Admin,vector<Restaurant> &restaurants,vector<Customer> &customerlist);

#endif //NUIST_TAKEOUT_PLATFORM_ALL_FUNCTION_H
