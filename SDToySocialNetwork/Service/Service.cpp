

#include "Service.h"
#include <fstream>
#include<algorithm>

Service::Service() =default;

Service::Service(RepoUsers &ru, const char *filenameUser, RepoFriendships &rf, const char *filenameFriendship,
                 RepoMesage &rm, const char *filenameMesage) {
    this->repoUsers = ru;
    this->filenameUser=filenameUser;
    this->repoFriendships = rf;
    this->filenameFriendship = filenameFriendship;
    this->repoMesage = rm;
    this->filenameMesage = filenameMesage;
    readFileUser(this->filenameUser);
    readFileFriendship(this->filenameFriendship);
    readFileMessage(this->filenameMesage);
}

void Service::addUser(int id, string name, int age, string country) {
    User u(id,std::move(name),age,std::move(country));
    this->repoUsers.addUser(u);
    this->saveToFileUser();
}


void Service::updateUser(int id, string name, int age, string country, string namenou, int agenou,
                             string countrynou) {
    User vechi(id,std::move(name),age,std::move(country));
    User nou(id, std::move(namenou), agenou, std::move(countrynou));
    this->repoUsers.updateUser(vechi, nou);
    this->saveToFileUser();
}

bool Service::findUser(int id, string name, int age, string country) {
    User u(id,std::move(name),age,std::move(country));
    if(this->repoUsers.findUser(u)!= -1) {
        return true;
        this->saveToFileUser();
    }
    else
        return false;

}

void Service::deleteUser(int id, string name, int age, string country) {
    User u(id,std::move(name),age,std::move(country));
    this->repoUsers.deleteUser(u);
    this->saveToFileUser();
}

vector<User> Service::showSameAge(int age)
{
    vector<User> all = this->repoUsers.getAll();
    vector<User> result;
    for(int i=0;i<=all.size();i++)
        if(all[i].getAge() == age)
            result.push_back(all[i]);
    return result;
}

User Service::findById(int id){
    return this->repoUsers.findById(id);

}

void Service::readFileUser(const char *f_name) {
    this->filenameUser = f_name;
    fstream f;
    f.open(f_name, ios::in);
    while (!f.eof())
    {
        int id;
        string name;
        int age;
        string country;
        f>>id>>name>>age>>country;
        User u(id, name, age, country);
        this->repoUsers.addUser(u);
    }
}

void Service::saveToFileUser() {
    fstream g;
    g.open(this->filenameUser, ios::out);
    for (User& u : repoUsers.getAll())
        g << u.getId() << " " << u.getName() << " " << u.getAge()<<" "<<u.getCountry() << endl;
}

int Service::sizeUser()  {
    return this->repoUsers.size();
}

vector<User> Service::getAllUser()
{
    return this->repoUsers.getAll();
}


void Service::addFriendship(const User& Friend1, const User& Friend2, int lenght, string place) {
    Friendship f (Friend1, Friend2, lenght, std::move(place));
    this->repoFriendships.addFriendship(f);
    this->saveToFileFriendship();
}

void Service::updateFriendship(const User& Friend1, const User& Friend2, int lenght, const string& place, int lenghtnou) {
    Friendship fvechi (Friend1, Friend2, lenght, place);
    Friendship fnou (Friend1, Friend2, lenghtnou, place);
    this->repoFriendships.updateFriendship(fvechi, fnou);
    this->saveToFileFriendship();
}

bool Service::findFriendship(const User& Friend1, const User& Friend2, int lenght, string place) {
    Friendship f (Friend1, Friend2, lenght, std::move(place));
    if(this->repoFriendships.findFriendship(f)!= -1) {
        return true;
        this->saveToFileFriendship();
    }
    else
        return false;
}

void Service::deleteFriendship(const User& Friend1, const User& Friend2, int lenght, string place) {
    Friendship f (Friend1, Friend2, lenght, std::move(place));
    this->repoFriendships.deleteFriendship(f);
    this->saveToFileFriendship();
}

void Service::readFileFriendship(const char *f_name) {
    this->filenameFriendship = f_name;
    fstream f;
    f.open(f_name, ios::in);
    while (!f.eof())
    {
        int  idfriend1, idfriend2;
        int lenght;
        string place;
        f>>idfriend1>>idfriend2>>lenght>>place;
        Friendship f(findById(idfriend1), findById(idfriend2), lenght, place);
        repoFriendships.addFriendship(f);
    }
}

void Service::saveToFileFriendship() {
    fstream g;
    g.open(this->filenameFriendship, ios::out);
    for (Friendship &f: repoFriendships.getAll())
        g << f.getFriend1().getName() << " " << f.getFriend2().getName() << " " << f.getLenght()<<" " <<f.getPlace() << endl;
}

vector<Friendship> Service::getFriendshipByUserFriend1(const User& u){
    vector<Friendship> friends = this->getAllFriendship();
    vector<Friendship>result;
    for(int i=0; i<friends.size();i++)
        if(friends[i].getFriend1().getId()== u.getId() )
            result.push_back(friends[i]);
    return result;
}

vector<Friendship> Service::getFriendshipByUserFriend2(const User& u){
    vector<Friendship> friends = this->getAllFriendship();
    vector<Friendship>result;
    for(int i=0; i<friends.size();i++)
        if(friends[i].getFriend2().getId()== u.getId() )
            result.push_back(friends[i]);
    return result;
}

bool compCrescByLength(Friendship& f1, Friendship& f2) {
    return f1.getLenght() < f2.getLenght();
}

vector<Friendship> Service::orderFriendshipByLength(){
    vector<Friendship> friends = this->getAllFriendship();
    vector<Friendship>result;
    std::vector<Friendship>::iterator it;
    for(Friendship f : friends) {
        Friendship ff(f.getFriend1(), f.getFriend2(), f.getLenght(), f.getPlace());
        it = std::find(result.begin(), result.end(), ff);
        if(it == result.end())
            result.emplace_back(f);
    }
    sort(result.begin(), result.end(), compCrescByLength);
    return result;
}

int Service::sizeFriendship()  {
    return this->repoFriendships.size();
}

vector<Friendship>Service::getAllFriendship()  {
    return this->repoFriendships.getAll();
}


void Service::addMessage(int senderId, int recieverId, string content)  {
    Message m(senderId, recieverId, std::move(content));
    this->repoMesage.addMesage(m);
    this->saveToFileMessage();
}

void Service::updateMessage(int senderId, int recieverId, string content, string contentnou) {
    Message mvechi(senderId, recieverId, std::move(content));
    Message mnou(senderId, recieverId, std::move(contentnou));
    this->repoMesage.updateMesage(mvechi, mnou);
    this->saveToFileMessage();
}

bool Service::findMessage(int senderId, int recieverId, string content){
    Message m(senderId, recieverId, std::move(content));
    if(this->repoMesage.findMesage(m)!= -1) {
        return true;
        this->saveToFileMessage();
    }
    else
        return false;
}

void Service::deleteMessage(int senderId, int recieverId, string content) {
    Message m(senderId, recieverId, std::move(content));
    this->repoMesage.deleteMesage(m);
    this->saveToFileMessage();
}

void Service::readFileMessage(const char *f_name) {
    this->filenameMesage = f_name;
    fstream f;
    f.open(f_name, ios::in);
    while (!f.eof())
    {
        int senderId, recieverId;
        string content;
        f>>senderId>>recieverId;
        getline(f,content);
        Message m(senderId, recieverId, content);
        repoMesage.addMesage(m);
    }
}

void Service::saveToFileMessage() {
    fstream g;
    g.open(this->filenameMesage, ios::out);
    for (Message& m : getAllMessage())
        g << findById(m.getSenderId()).getName() << " " <<findById(m.getReceiverId()).getName()<< " " <<m.getContent() << endl;
}

int Service::sizeMessage()  {
    return this->repoMesage.size();
}

vector<Message>Service::getAllMessage()
{
    return this->repoMesage.getAll();
}

vector<Message> Service::getConversation(int idfriend1, int idfriend2){
    vector<Message> message = this->getAllMessage();
    vector<Message> result;
    for(int i=0;i<repoMesage.size();i++)
        if((idfriend1== message[i].getSenderId() and idfriend2== message[i].getReceiverId()) ||
                (idfriend2== message[i].getSenderId() and idfriend1== message[i].getReceiverId()))
            result.push_back(message[i]);
    return result;
}

Service::~Service() {
    fstream fu(this->filenameUser);
    if (fu.is_open()) fu.close();
    fstream ff(this->filenameFriendship);
    if (ff.is_open()) ff.close();
    fstream fm(this->filenameMesage);
    if (fm.is_open()) fm.close();
}
