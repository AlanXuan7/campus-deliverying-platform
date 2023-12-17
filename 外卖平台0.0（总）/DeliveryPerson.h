#ifndef DELIVERY_PERSON_H
#define DELIVERY_PERSON_H

#include "User.h"
#include <vector>
#include <string>
#include "Order.h"

using namespace std;

class DeliveryPerson : public User {
public:

    enum class Status {
        Free,           //空闲中
        Deliverying     //配送中
    };

    // 构造函数
    DeliveryPerson(){}
    DeliveryPerson(const string &id, const string &name, int age, const string &gender,
                   const Coordinate &coordinates, const string &password, const string& telephoneNumber,
                   double balance);

    vector<Order>  getDeliveryRecords() const;
    void setDeliveryRecords(vector<Order> newDeliveryOrder);
    void addDeliveryRecord(const Order& record);

    double getTotalIncome() const;
    void addIncome(double income);

    double getRating() const;
    void updateRating(double newRating);

private:
    vector<Order> deliveryRecords;  // 配送记录
    double totalIncome;              // 总收入
    double rating;                   // 配送评分
};

#endif // DELIVERY_PERSON_H
