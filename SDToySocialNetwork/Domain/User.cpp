

#include "User.h"
#include <utility>

User::User() {
    this->id = 0;
    this->name = "";
    this->age=0;
    this->country = "";
}
User::User(int id, string name, int age, string country) {
    this->id= id;
    this->name = std::move(name);
    this->age= age;
    this->country = std::move(country);
}


User::User(const User &u) {
    this->id = u.id;
    this->name = u.name;
    this->age = u.age;
    this->country = u.country;

}

int User::getId() const {
    return this->id;
}

string User::getName() {
    return this->name;
}

int User::getAge() const {
    return this->age;
}

string User::getCountry() {
    return this->country;
}


void User::setId(int id) {
    this->id = id;
}

void User::setName(string n) {
    this->name = std::move(n);
}

void User::setAge(int a) {
    this->age = a;
}

void User::setCountry(string c) {
    this->country = std::move(c);
}


User&User::operator=(const User &u) {
    if (this != &u)
    {
        this->id = u.id;
        this->name= u.name;
        this->age = u.age;
        this->country = u.country;
    }
    return * this;
}

bool User::operator==(const User &u) {
    return ((this->id == u.id) and (this->name == u.name) and
            (this->age == u.age) and (this->country == u.country)  );
}

bool User::operator<(const User & u) const {
    if(this->id<u.id)
        return true;
    else
        return false;
}

bool User::operator>(const User & u) const {
    if(this->id>u.id)
        return true;
    else
        return false;
}

bool User::operator!=(const User &u) const {
    if(this->id != u.id)
        return true;
    return false;
}

istream& operator>>(istream& is, User &u){
    cout<<"Dati Userul:"<<endl;
    cout<<"Dati id-ul userului: ";is>>u.id;
    cout<<"Dati numele userului: "; is>>u.name;
    cout<<"Dati varsta userului: ";is>>u.age;
    cout<<"Dati tara userului: ";is>>u.country;
    return is;
}

ostream& operator<<(ostream& os, User &u){
    os<<"Userul cu id: "<<u.id<<", nume:  "<<u.name<<", varsta:  "<<u.age<<" si tara: "<<u.country ;
    return os;
}
string User::toString()
{
    return "Userul cu id: "+ to_string(this->id) +
    ", nume:  "+this->name+", varsta:  "+ to_string(this->age)+" si tara: "+this->country;

}
User::~User() {
    this->id = 0;
    this->name = "";
    this->age=0;
    this->country = "";
}