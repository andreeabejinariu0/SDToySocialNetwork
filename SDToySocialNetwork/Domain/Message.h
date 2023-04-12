

#ifndef SDTOYSOCIALNETWORK_MESSAGE_H
#define SDTOYSOCIALNETWORK_MESSAGE_H
#include <iostream>
using namespace std;

class Message {
private:
    int senderId, recieverId;
    string content;
public:

    /**
     * Constructor implicit pentru clasa Message
     */
    Message();


    /**
     * Constructor cu parametrii
     * @param sId :id-ul celui care trimite mesajul
     * @param rId: id-ul celui care primeste mesajul
     * @param content : continutul mesajului
     */
    Message(int sId, int rId, string content);


    /**
     * Constructor de copiere
     * @param m : mesajul pe care il copieaza
     */
    Message(const Message &m);


    /**
     *  Destructor al clasei Message
     */
    ~Message();


    /**
     * Obtine id-ul celui care trimite mesajul
     * @return id-ul celui care trimite mesajul
     */
    int getSenderId() const;


    /**
     * Obtine id-ul celui care primeste mesajul
     * @return id-ul celui care primeste mesajul
     */
    int getReceiverId() const;


    /**
     * Obtine continutul mesajului
     * @return continutul mesajului
     */
    string getContent();


    /**
     * Atribuie id-ul celui care trimite mesajul
     * @param sId : id-ul celui care trimite mesajul
     */
    void setSenderId(int sId);


    /**
     * Atribuie id-ul celui care primeste mesajul
     * @param rId : id-ul celui care primeste mesajul
     */
    void setReceiverId(int rId);


    /**
     * Atribuie continutul unui mesaj
     * @param c :  continutul unui mesaj
     */
    void setContent(string c);


    /**
     * Operatorul =, de atribuire a unui mesaj
     * @return un mesaj
     */
    Message& operator = (const Message&);


    /**
     * Operatorul ==, compara 2 mesaje daca sunt egale
     * @return adevarat/fals
     */
    bool operator==(const Message& );

    /**
     * Suprascrie operatorul de citire >>
     * @param is : modalitatea de citire
     * @param m : mesajul
     * @return is, indicatii despre citire
     */
    friend istream& operator>>(istream& is, Message & m);


    /**
     * Suprascrie operatorul de afisare <<
     * @param os :  modalitatea de afisare
     * @param m  : mesajul
     * @return os, indicatii despre afisare
     */
    friend ostream& operator<<(ostream& os, Message & m);

};


#endif //SDTOYSOCIALNETWORK_MESSAGE_H
