

#include "RepoUsers.h"

RepoUsers::RepoUsers() =default;

RepoUsers::RepoUsers(OrderedSet<User> &uset) {
    this->userset = uset;
}

void RepoUsers::addUser(User &u) {
    userset.add(u);
}

int RepoUsers::findUser(User &u) {
    for(int i=0;i<userset.size();i++)
        if(userset[i]==u)
            return i;
    return -1;
}

User RepoUsers::findById(int id){
    for(int i=0;i<userset.size();i++)
        if(userset[i].getId() == id)
            return userset[i];
}

void RepoUsers::updateUser(User &uvechi, User &unou) {
    if(findUser(uvechi)!= -1)
        uvechi= unou;
}

void RepoUsers::deleteUser(User &u) {
    if(findUser(u)!= -1)
        userset.remove(findById(u.getId()));
}

vector<User> RepoUsers::getAll() {
    vector<User> all ;
    for(int i=0;i<userset.size();i++)
        all.push_back(userset[i]);
    return all;
}



int RepoUsers::size() {
    return userset.size();
}

RepoUsers::~RepoUsers() = default;