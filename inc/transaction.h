#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<person.h>
#include<unordered_map>

using namespace std;

class transaction{
    private:
    unordered_map<string,person> belongsToGroup;
    public:
    void addPerson(string name);
    bool checkPerson(string name);
    void equalSplit(float amount,string payer);
    void unequalSplit(float amount,string payer,int noOfPeopleInvolvedInTransaction);
    unordered_map<string,person> getDetails();
};

#endif