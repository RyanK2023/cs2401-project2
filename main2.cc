//this is just used to test friend.cc
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"date.h"
#include"friend.h"

using namespace std;

int main() {

    Friend f1;
    Friend f2;

    cin >> f1;
    cin >> f2;

    cout << f1.get_name() << " " << f1.get_bday() << endl;
    cout << f2.get_name() << " " << f2.get_bday() << endl;

    if (f1 == f2) {
        cout << "Here" << endl;
    }

    if (f1 != f2) {
        cout << "Here too" << endl;
    }



}