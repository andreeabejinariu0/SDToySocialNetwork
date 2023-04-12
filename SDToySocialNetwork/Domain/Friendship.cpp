
#include "Friendship.h"

#include <utility>

Friendship::Friendship() {
    this->friend1 = User();
    this->friend2 = User();
    this->lenght = 0;
    this->place = "";
}

Friendship::Friendship(User friend1, User friend2, int len, string place) {
    this->friend1 = friend1;
    this->friend2 = friend2;
    this->lenght = len;
    this->place = std::move(place);

}

Friendship::Friendship(const Friendship &f) {
    this->friend1 = f.friend1;
    this->friend2 = f.friend2;
    this->lenght = f.lenght;
    this->place = f.place;
}

Friendship::~Friendship() {
    this->friend1 = User();
    this->friend2 = User();
    this->lenght = 0;
    this->place = "";
}

User Friendship::getFriend1() {
    return this->friend1;
}

User Friendship::getFriend2() {
    return this->friend2;
}

int Friendship::getLenght() const {
    return this->lenght;
}

string Friendship::getPlace() {
    return this->place;
}

void Friendship::setfriend1(const User& friend1) {
    this->friend1 = friend1;
}

void Friendship::setfriend2(const User& friend2) {
    this->friend2= friend2;
}

void Friendship::setLength(int len) {
    this->lenght= len;
}

void Friendship::setPlace(string meet_at) {
    this->place = std::move(meet_at);
}

Friendship&Friendship::operator=(const Friendship &f) {
    if (this != &f)
    {
        this->friend1 = f.friend1;
        this->friend2 = f.friend2;
        this->lenght = f.lenght;
        this->place = f.place;
    }
    return * this;
}

bool Friendship::operator==(const Friendship &f) {
    return ((this->friend1 == f.friend1) and (this->friend2 ==f.friend2) and
            (this->lenght == f.lenght) and (this->place == f.place) );
}

istream& operator>>(istream& is, Friendship & f){
    cout<<"Dati Prietenia:"<<endl;
    cout<<"Dati detalii primul prieten: ";is>>f.friend1;
    cout<<"Dati detalii al doilea prieten "; is>>f.friend2;
    cout<<"Dati durata prieteniei: ";is>>f.lenght;
    cout<<"Dati locul unde s-au cunoscut: ";is>>f.place;
    return is;
}

ostream& operator<<(ostream& os, Friendship & f){
    os<<"Pretenia dintre  "<<f.friend1<<" si   "<<f.friend2<<" cu durata de  "<<f.lenght<<
    " ani si s-au intalnit la "<<f.place;
    return os;
}
