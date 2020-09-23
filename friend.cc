/*
Name: Ryan Kilkenney
Date: 2/16/2020
Purpose: Contains all of the functions for the friends.h class
*/
#include<iostream>
#include<string>
#include "friend.h"

using namespace std;

Friend::Friend() {
    name = " ";
    bday = Date(0,0,0);
}

string Friend::get_name()const {
    return name;
}

Date Friend::get_bday()const {
    return bday;
}

bool Friend::operator == (const Friend& other)const {
    return (name == other.get_name()) && (bday == other.get_bday());
}

bool Friend::operator != (const Friend& other)const {
    return !(name == other.get_name()) && (bday == other.get_bday());
}

void Friend::input(std::istream& ins) {
    while(ins.peek() == '\n') {
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
}

void Friend::output(std::ostream& outs)const {
    outs<<name;
    outs<< " ";
    outs<<bday;
}

istream& operator >>(std::istream& ins,Friend& f) {
    f.input(ins);
    return ins;
}

ostream& operator <<(std::ostream& outs,const Friend& f) {
    f.output(outs);
    return outs;
}

void Friend::set_name(std::string n) {
    name = n;
}

void Friend::set_bday(Date bd) {
    bday = bd;
}