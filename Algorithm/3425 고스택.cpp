#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<cmath>
#define INF 1e9

using namespace std;
typedef long long ll;
vector <string> command;
stack <ll> goStack;
bool flag;
void excute(string op) {
    
    if (op[0] == 'N') {
        int X = stoi(op.substr(4));
        goStack.push(X);
    }
    else if (op == "POP") {
        if (goStack.empty())
        {
            flag = false;
            return;
        }
        else goStack.pop();
    }
    else if (op == "INV") {
        if (goStack.empty())
        {
            flag = false;
            return;
        }
        else
        {
            long long temp = goStack.top();
            goStack.pop();
            goStack.push(-temp);
        }
    }
    else if (op == "DUP") {
        if (goStack.empty()) 
        {
            flag = false;
            return;
        }
        else {
            goStack.push(goStack.top());
        }
    }
    else {
        if (goStack.size() < 2) {
            flag = false;
            return;
        }
        long long first = goStack.top();
        goStack.pop();
        long long second = goStack.top();
        goStack.pop();
        if (op == "SWP") {
            goStack.push(first);
            goStack.push(second);
        }
        else if (op == "ADD") {
            long long tmp = first + second;
            if (abs(tmp) > INF) 
            {
                flag = false;
                return;
            }
            goStack.push(tmp);
        }
        else if (op == "SUB") {
            long long tmp = second - first;
            if (abs(tmp) > INF)
            {
                flag = false;
                return;
            }
            goStack.push(tmp);
        }
        else if (op == "MUL") {
            long long tmp = first * second;
            if (abs(tmp) > INF)
            {
                flag = false;
                return;
            }
            goStack.push(tmp);
        }
        else if (op == "DIV") {
            if (first == 0)
            {
                flag = false;
                return;
            }
            long long tmp = abs(second) / abs(first);
            int minus = 0;
            if (first < 0) minus++;
            if (second < 0) minus++;
            if (minus == 1) tmp = -tmp;
            goStack.push(tmp);
        }
        else if (op == "MOD") {
            if (first == 0)
            {
                flag = false;
                return;
            }
            long long tmp = abs(second) % abs(first);
            if (second < 0) tmp = -tmp;
            goStack.push(tmp);
        }
    }
}
int main() {
    while (1) {
        command.clear();
        string op;
        while (cin >> op) {
            if (op == "QUIT") return 0;
            if (op == "END") break;
            if (op == "NUM") {
                long long num;
                cin >> num;
                command.push_back(op + " " + to_string(num));
            }
            else command.push_back(op);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            while (!goStack.empty()) goStack.pop();
            long long operand;
            cin >> operand;
            goStack.push(operand);
            flag = true;
            for (int j = 0; j < command.size(); j++) {
                excute(command[j]);
            }
            if (!flag) cout << "ERROR\n";
            else if (goStack.size() != 1) cout << "ERROR\n";
            else {
                cout << goStack.top() << "\n";
                goStack.pop();
            }
        }
        cout << "\n";
    }
}