#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person{
    private:
    string name;
    double balance;
    public:
    person();
    person(string personName);
    void addTransaction(float amount);
    string get_name();
    float get_balance();
};

#endif