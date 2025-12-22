#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include<transaction.h>
#include<vector>

using namespace std;

class expenseManager{
    private:
    vector<person> groupDetails;
    public:
    expenseManager(unordered_map<string,person> mymap);
    void printOptimizedExpenses();
};

#endif