#include<transaction.h>
#include<iostream>
#include<vector>

using namespace std;

void transaction::addPerson(string name){
    belongsToGroup[name]=person(name);
}

bool transaction::checkPerson(string name){
    if(belongsToGroup.find(name)!=belongsToGroup.end()){
        return true;
    }
    return false;
}

void transaction::equalSplit(float amount,string payer){
    belongsToGroup[payer].addTransaction(amount);
    float share=(amount/(belongsToGroup.size()));
    for(auto &member : belongsToGroup){
        member.second.addTransaction(-share);
    }
}

void transaction::unequalSplit(float amount,string payer,int noOfPeopleInvolvedInTransaction){
    belongsToGroup[payer].addTransaction(amount);
    vector<string> belongsToTransaction;
    for(int i=0;i<noOfPeopleInvolvedInTransaction;i++){
        string check;
        cin >> check;
        if(belongsToGroup.find(check)!=belongsToGroup.end()){
            belongsToTransaction.push_back(check);
        }else{
            cout << "Enter a valid payee\n";
            i--;
        }
    }
    vector<float> share(noOfPeopleInvolvedInTransaction);
    float check_share=0;
    while(1){
        for(int i=0;i<noOfPeopleInvolvedInTransaction;i++){
            cout << "Enter " << belongsToTransaction[i] << "'s share - ";
            cin >> share[i];
            check_share+=share[i];
        }
        if(check_share==amount){
            break;
        }else{
            cout << "Invalid Transcation, Enter a valid Transaction.\n";
            check_share=0;
        }
    }
    for(int i=0;i<belongsToTransaction.size();i++){
        belongsToGroup[belongsToTransaction[i]].addTransaction(-share[i]);
    }
}

unordered_map<string,person> transaction::getDetails(){
    return belongsToGroup;
}
