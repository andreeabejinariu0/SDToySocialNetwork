
#ifndef SDTOYSOCIALNETWORK_FRIENDSHIP_H
#define SDTOYSOCIALNETWORK_FRIENDSHIP_H
#include <iostream>
#include "User.h"
#include "../Repository/RepoUsers.h"
using namespace std;

class Friendship {
private:
    User friend1, friend2;
    int lenght;
    string place;
public:

    /**
     * Constructor implicit pentru clasa Friendship
     */
    Friendship();


    /**
     * Constructor de parametrii
     * @param friend1: primul prieten de tip User
     * @param friend2: al doilea prieten de tip User
     * @param len: durata prieteniei
     * @param place: locul intalnirii
     */
    Friendship(User friend1, User friend2, int len, string place);


    /**
     * Constructor de copiere
     * @param f : prietenia pe care o copieaza
     */
    Friendship(const Friendship &f);

    /**
     * Destructor al clasei Friendship
     */
    ~Friendship();


    /**
     * Obtine detalii despre primul prieten
     * @return un user
     */
    User getFriend1();


    /**
     * Obtine detalii despre al doilea prieten
     * @return un user
     */
    User getFriend2();


    /**
     * Obtine durata prieteniei
     * @return : durata prieteniei de tip int
     */
    int getLenght() const;


    /**
     * Obtine locul intalnirii
     * @return  locul intalnirii, de tip string
     */
    string getPlace();


    /**
     * Atribuie un user primului prieten
     * @param friend1 : userul pe care il atribuie
     */
    void setfriend1(const User& friend1);


    /**
     * Atribuie un userla al doilea prieten
     * @param friend2 : userul pe care il atribuie
     */
    void setfriend2(const User& friend2);


    /**
     * Atribuie durata prieteniei
     * @param len : durata pe care o atribuie
     */
    void setLength(int len);


    /**
     * Atribuie locul de intalnire
     * @param meet_at : locul de intalnire pe care il atribuie
     */
    void setPlace(string meet_at);


    /**
     * Operatorul =, de atribuire a unei prietenii
     * @return o prietenie
     */
    Friendship& operator = (const Friendship&);


    /**
     * Operatorul ==, compara 2 prietenii daca sunt egale
     * @return adevarat/fals
     */
    bool operator==(const Friendship& );


    /**
     *  Suprascrie operatorul de citire >>
     * @param is : modalitatea de citire
     * @param f : prietenia
     * @return is, indicatii despre citire
     */
    friend istream& operator>>(istream& is, Friendship & f);


    /**
     * Suprascrie operatorul de afisare <<
     * @param os  :  modalitatea de afisare
     * @param f : prietenia
     * @return os, indicatii despre afisare
     */
    friend ostream& operator<<(ostream& os, Friendship & f);

};


#endif //SDTOYSOCIALNETWORK_FRIENDSHIP_H
