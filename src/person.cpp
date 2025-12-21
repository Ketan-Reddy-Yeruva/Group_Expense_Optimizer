#include<person.h>
#include<iostream>

using namespace std;

person::person(){
    name="";
    balance=0;
}

person::person(string personName){
        name=personName;
        balance=0;
}

void person::addTransaction(float amount){
    balance+=amount;
}

string person::get_name(){
    return name;
}

float person::get_balance(){
    return balance;
}