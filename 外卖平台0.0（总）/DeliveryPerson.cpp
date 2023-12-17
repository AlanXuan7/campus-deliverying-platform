#include "DeliveryPerson.h"

DeliveryPerson::DeliveryPerson(const string &id, const string &name, int age, const string &gender,
                               const Coordinate &coordinates, const string &password, const string& telephoneNumber,
                               double balance)
        :User(id, name, age, gender, coordinates, password, telephoneNumber, balance),
         totalIncome(0.0), rating(0.0){}


vector<Order> DeliveryPerson::getDeliveryRecords() const {
    return deliveryRecords;
}

void DeliveryPerson::addDeliveryRecord(const Order& record) {
    deliveryRecords.push_back(record);
}

void DeliveryPerson::setDeliveryRecords(vector<Order> newDeliveryOrder) {
    deliveryRecords = newDeliveryOrder;
}

double DeliveryPerson::getTotalIncome() const {
    return totalIncome;
}

void DeliveryPerson::addIncome(double income) {
    totalIncome += income;
}

double DeliveryPerson::getRating() const{
    return rating;
}

void DeliveryPerson::updateRating(double newRating) {
    rating = newRating;
}