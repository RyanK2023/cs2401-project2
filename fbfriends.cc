/*
Name: Ryan Kilkenney
Date: 2/16/2020
Purpose: Contains all of the functions for the fbfriends.h class
*/

#include<iostream>
#include<string>
#include<fstream>
#include<cassert>
#include<algorithm>
#include "friend.h"
#include "fbfriends.h"

using namespace std;

FBFriends::FBFriends() {
    capacity = 5;
    used = 0;
    data = new Friend[capacity];
    current_index = 0;
} 

FBFriends::~FBFriends() {
    delete []data;
    cout << "In deconstructor" << endl;
}

FBFriends::FBFriends(const FBFriends& other) {
        used = other.used;
        current_index = other.current_index;
        capacity = other.capacity;
        data = new Friend[capacity];
        copy(other.data,other.data + used, data);
}

void FBFriends::operator = (const FBFriends& other) {
    if(this == &other) {
        return;
    }
    delete []data;
    used = other.used;
    capacity = other.capacity;
    data = new Friend[capacity];
    copy(other.data, other.data + used, data);
}

void FBFriends::start() {
    current_index = 0;
}

void FBFriends::advance() {
    current_index++;
}

bool FBFriends::is_item() {
    return (current_index < used);
}

Friend FBFriends::current() {
    return data[current_index];
}


void FBFriends::remove_current() {
    for (int i = current_index; i < used; i++) {
		data[i] = data[i+1];
	}
    used--;
}

void FBFriends::insert(const Friend& f) {
    
    if (used < capacity) {
        resize();
    }

    for (int i = used; i > current_index; i--) {
		data[i] = data[i-1];
	}
    data[current_index].set_name(f.get_name());
    data[current_index].set_bday(f.get_bday());
	used++;

}

void FBFriends::attach(const Friend& f) {
    if (used < capacity) {
        resize();
    }
    
    for (int i = used; i > current_index; i--) {
		data[i] = data[i-1];
	}	
    data[current_index].set_name(f.get_name());
    data[current_index].set_bday(f.get_bday());
	used++;
}

void FBFriends::show_all(std::ostream& outs)const {
    for(size_t i = 0; i < used; i++) { 
        cout << data[i].get_name() << " " << data[i].get_bday() << endl;
    }
}

void FBFriends::bday_sort(){
    bool done = false;
    int j;
    Friend tmp;
    while(!done){
	done = true;
	for(j=0; j < used - 1; j++){
        
        if(data[j].get_bday() > data[j+1].get_bday()){
		    done = false;
		    tmp.set_name(data[j].get_name());
            tmp.set_bday(data[j].get_bday());
		    data[j].set_name(data[j+1].get_name());
            data[j].set_bday(data[j+1].get_bday());
		    data[j+1].set_name(tmp.get_name());
            data[j+1].set_bday(tmp.get_bday());
	    }
	}
    }
}

void FBFriends::load(std::istream& ins){
    if (used < capacity) {
        resize();
    }
    
    Friend f;
    int i = 0;
    while (ins >> f)
        {
            if (used >= capacity) {
                resize();
            }
            data[i] = f;
            used++;
            i++;
        }

}
void FBFriends::save(std::ostream& outs){
    for(int i = 0; i < used; i++) {
        outs << data[i].get_name() << endl;
        outs << data[i].get_bday() << endl;
    }
}

void FBFriends::resize() {
    Friend *tmp;
    tmp = new Friend[capacity + 5];
    capacity += 5;
    copy(data, data + used, tmp);
    delete []data;
    data = tmp;
}

Friend FBFriends::find_friend(const std::string& name)const{
    Friend emptyFriend;
    Date d(1,1,2000);
    emptyFriend.set_name("N/A");
    emptyFriend.set_bday(d);
    
    for(size_t i = 0; i < used; i++) {
        if (data[i].get_name() == name) {
            return data[i];
        }
    }
    return emptyFriend;
}

bool FBFriends::is_friend(const Friend& f) const{
    for (size_t i = 0; i < used; i++) {
        if ((data[i].get_name() == f.get_name()) && data[i].get_bday() == f.get_bday()) {
            return true;
        }
    }
    return false;
}