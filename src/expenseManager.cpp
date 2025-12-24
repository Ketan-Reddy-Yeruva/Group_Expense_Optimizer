#include<person.h>
#include<expenseManager.h>
#include<bits/stdc++.h>

class CompareMyClass {
public:
    bool operator()(const person& a, const person& b) {
        // Comparator logic: returns true if a should come after b in the priority queue
        return a.balance < b.balance;  // This makes it a max-heap based on 'value'
    }
};

class CompareMyClass_minheap {
public:
    bool operator()(const person& a, const person& b) {
        // Comparator logic: returns true if a should come after b in the priority queue
        return a.balance > b.balance;  // This makes it a min-heap based on 'value'
    }
};

expenseManager::expenseManager(unordered_map<string,person> mymap) {
    for (auto &x : mymap) {
        groupDetails.push_back(x.second);
    }
}

void expenseManager::printOptimizedExpenses() {
    vector<string>payers;
    vector<string>receivers;
    vector<float>amount;
    priority_queue<person, vector<person>, CompareMyClass> positive;
    priority_queue<person, vector<person>, CompareMyClass_minheap> negative;
    for (person x : groupDetails) {
        if (x.get_balance() > 0) {
            positive.push(x);
        }
        if (x.get_balance() < 0) {
            negative.push(x);
        }
    }
    while(!positive.empty() && !negative.empty() ) {
        person to_be_paid = positive.top(); // he has positive balance (paid a lot)
        person should_pay = negative.top(); // he has negative balance (he should pay to group)
        float pos = positive.top().get_balance;
        // positive.pop();
        float neg = negative.top().get_balance;
        // negative.pop();
        receivers.push_back(positive.top().get_name);
        payers.push_back(negative.top().get_name);
        positive.pop(); negative.pop();
        if (pos + neg == 0) {           
            amount.push_back(pos);
            to_be_paid.addTransaction(neg);
            should_pay.addTransaction(pos);
        }

        else if (pos+neg>0) {         //to_be_paid still needs to get more money from group
            amount.push_back(abs(neg));
            to_be_paid.addTransaction(neg);
            should_pay.addTransaction(abs(neg));
            positive.push(to_be_paid);
        }

        else {                      // should_pay still needs to pay more money to group
            amount.push_back(pos);
            to_be_paid.addTransaction(-pos);
            should_pay.addTransaction(pos);
            negative.push(should_pay);
        }

    }
    int n = amount.size();
    for (int i=0; i<n; i++) {
        cout << payers[i] << "  should pay  " << amount[i] <<"  to  " << receivers[i] << "\n";
    }

    return ;
}