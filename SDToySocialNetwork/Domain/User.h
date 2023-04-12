

#ifndef SDTOYSOCIALNETWORK_USER_H
#define SDTOYSOCIALNETWORK_USER_H
#include <iostream>
using namespace std;

class User {
private:
    int id;
    string name;
    int age;
    string country;

public:

    /**
     * Constructor implicit pentru clasa User
     */
    User();


    /**
     * Constructor cu parametrii
     * @param id :id-ul userului
     * @param name: numele userului
     * @param age: varsta userului
     * @param country: tara de provenienta a userului
     */
    User(int id, string name, int age, string country );


    /**
     * Constructor de copiere
     * @param u : userul pe care il copieaza
     */
    User(const User &u);


    /**
     * Destructor al clasei User
     */
    ~User();


   /**
    * Obtine id-ul userului
    * @return : id-ul userului
    */
    int getId() const;


    /**
     * Obtine numele userului
     * @return : numele userului
     */
    string getName();


    /**
     * Obtine varsta userului
     * @return : varsta userului
     */
    int getAge() const;


    /**
     * Obtine tara userului
     * @return : tara userului
     */
    string getCountry();


    /**
     * Seteaza/atribuie  id-ul userului
     * @param id : id-ul pe care il pune userului
     */
    void setId(int id);


    /**
     * Atribuie un nume userului
     * @param n : numele pe care sa il puna userului
     */
    void setName(string n);


    /**
     * Atribuie o varsta unui user
     * @param age: varsta pe care sa o puna userului
     */
    void setAge(int age);


    /**
     * Atribuie tara de provenienta unui user
     * @param c : tara pe care sa o puna userului
     */
    void setCountry(string c);


    /**
     * Operatorul =, de atribuire a unui user
     * @return : un user
     */
    User& operator = (const User&);


    /**
     * Operatorul ==, compara 2 useri daca sunt egali
     * @return adevarat/fals
     */
    bool operator==(const User& );


    /**
     * Operatorul <, compara  2 useri in functie de id
     * @return adevarat/fals
     */
    bool operator < (const User&) const;


    /**
     * Operatorul >, compara  2 useri in functie de id
     * @return adevarat/fals
     */
    bool operator > (const User&) const;


    /**
     * Operator !=, compara daca 2 useri dunt diferiti, in functie de id
     * @return adevarat/fals
     */
    bool operator !=(const User &) const;


    /**
     * Converteste intr-un string un mesaj
     * @return mesajul de tip string
     */
    string toString();


    /**
     * Suprascrie operatorul de citire >>
     * @param is : modalitatea de citire
     * @param u : userul
     * @return is, indicatii despre citire
     */
    friend istream& operator>>(istream& is, User & u);


    /**
     * Suprascrie operatorul de afisare <<
     * @param os :  modalitatea de afisare
     * @param u : userul
     * @return os, indicatii despre afisare
     */
    friend ostream& operator<<(ostream& os, User & u);
};


#endif //SDTOYSOCIALNETWORK_USER_H
