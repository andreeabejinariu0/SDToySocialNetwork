

#include "Message.h"

#include <utility>

Message::Message() {

    this->senderId = 0;
    this->recieverId = 0;
    this->content = "";
}

Message::Message(int sId, int rId, string content) {

    this->senderId = sId;
    this->recieverId = rId;
    this->content= std::move(content);
}

Message::Message(const Message &m) {

    this->senderId = m.senderId;
    this->recieverId = m.recieverId;
    this->content = m.content;
}

Message::~Message() {

    this->senderId = 0;
    this->recieverId = 0;
    this->content = "";
}

int Message::getSenderId() const {

    return this->senderId;
}

int Message::getReceiverId() const {

    return this->recieverId;
}

string Message::getContent() {

    return this->content;
}

void Message::setSenderId(int sId) {
    this->senderId = sId;
}

void Message::setReceiverId(int rId) {
    this->recieverId = rId;
}

void Message::setContent(string c) {
    this->content = std::move(c);
}

Message&Message::operator=(const Message &m) {
    if(this != &m)
    {
        this->senderId = m.senderId;
        this->recieverId = m.recieverId;
        this->content = m.content;
    }
    return * this;
}

bool Message::operator==(const Message &m) {
    return ((this->senderId == m.senderId) and (this->recieverId == m.recieverId)
    and (this->content == m.content));
}

istream& operator>>(istream& is, Message &m){
    cout<<"Dati Mesajul:"<<endl;
    cout<<"Dati id-ul celui care trimite: ";is>>m.senderId;
    cout<<"Dati id-ul celui care primite "; is>>m.recieverId;
    cout<<"Dati continutul mesajului ";is>>m.content;
    return is;
}

ostream& operator<<(ostream& os,  Message &m){
    os<<"De la  "<<m.senderId<<" catre   "<<m.recieverId<<" cu mesajul: "<<m.content;
    return os;
}