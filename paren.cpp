#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

void test(stringstream &ss){
    char c;
    stack <char> sta;
    while(ss>>c){
        if (c=='{' || c=='(' || c=='[') {
            sta.push(c);
        }
        if (c=='}') {
            if (sta.empty()) {
                cout<<"NO"<<endl;
                return;
            }
            if (sta.top()!='{') {
                cout<<"NO"<<endl;
                return;
            }
            sta.pop();
        }
        if (c==']') {
            if (sta.empty()) {
                cout<<"NO"<<endl;
                return;
            }
            if (sta.top()!='[') {
                cout<<"NO"<<endl;
                return;
            }
            sta.pop();
        }
        if (c==')') {
            if (sta.empty()) {
                cout<<"NO"<<endl;
                return;
            }
            if (sta.top()!='(') {
                cout<<"NO"<<endl;
                return;
            }
            sta.pop();
        }
    }
    if (sta.empty()){
        cout<<"YES"<<endl;
    }
    else { cout <<"NO"<<endl; }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    string *str= new string[n];
    getline(cin,str[0]);

    for (int i=0; i<n; i++){
        getline(cin,str[i]);
    }
    for (int i=0; i<n; i++){
        stringstream ss;
        ss.clear();
        ss<<str[i];
        test(ss);
    }
    return 0;
}
