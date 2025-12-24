#include<bits/stdc++.h>
#include<person.h>
#include<transaction.h>
#include<expenseManager.h>

using namespace std;

int main() {
    cout << "How many people went out ??" << "\n";

    int n;
    cin >> n;

    // the main data structure of this program.
    transaction outing_today;

    cout << "Enter the names of people now....." << "\n";
    for (int i=0; i<n; i++) {
        cout << "Name of Person i " << "   ";
        string s; cin >> s;
        if (!outing_today.checkPerson(s)) {
            outing_today.addPerson(s);
        }
        else {
            cout << "Error";
        }
        cout << "\n";
    }
    


    cout << "Enter '+' to add a transaction [or] Enter '=' to get simplified split." << "\n";
    cout << "Enter any other key to exit." << "\n";

    while(1) {
        char c; cin >> c;
        if (c=='+') {
            cout << "Enter 1 to split equally [or] Enter 2 to split weight wise." << "\n";
            int n; cin >> n;
            if (n==1) {
                cout << "Who paid??    " << "\n";
                string payer; cin >> payer;
                cout << "How much did he/she pay??   " << "\n";
                float money; cin >> money;
                outing_today.equalSplit(money, payer);
            }
            else {
                cout << "Who paid??    " << "\n";
                string payer; cin >> payer;
                cout << "How much did he/she pay??   " << "\n";
                float money; cin >> money;
                cout << "How many people are involved in this???    " << "\n";
                int noOfInvolved; cin noOfInvolved;
                outing_today.unequalSplit(float amount,string payer,int noOfInvolved);
            
            }
        }   


        else if (c=='=') {
            expenseManager optimizer;
            optimizer.expenseManager(outing_today.getDetails());
            optimizer.printOptimizedExpenses();
        }
    
        else {
            cout << "Thank you for using Group Expense Optimizer :)" << "\n";
            break;
        }
    }

}
