cmake_minimum_required(VERSION 3.25)
project(NUIST_Takeout_Platform)

set(CMAKE_CXX_STANDARD 11)

add_executable(NUIST_Takeout_Platform User.h User.cpp DeliveryPerson.cpp DeliveryPerson.h Customer.cpp Customer.h RestaurantAdmin.cpp RestaurantAdmin.h Restaurant.cpp Restaurant.h Delivery_Function.cpp Register_and_Login.cpp Order.cpp Order.h 测试.cpp ALL_FUNCTION.h Customer_Function.cpp SuperAdmin.cpp SuperAdmin.h Protected.cpp RestaurantAdmin_Function.cpp In_Out_File.cpp)
