

#include "RepoFriendships.h"

RepoFriendships::RepoFriendships() =default;

RepoFriendships::RepoFriendships(List<Friendship> &flist) {
    this->friendslist = flist;
}

void RepoFriendships::addFriendship(Friendship &f) {
    friendslist.pushBack(f);
}

int RepoFriendships::findFriendship(Friendship &f) {
    for(int i=0;i<=friendslist.size();i++)
        if(friendslist[i]==f)
            return i;
    return -1;
}

void RepoFriendships::updateFriendship(Friendship &fvechi, Friendship &fnou) {
    if(findFriendship(fvechi)!= -1)
        fvechi= fnou;
}

void RepoFriendships::deleteFriendship(Friendship &f) {
    if(findFriendship(f)!= -1)
        friendslist.deleteElem(findFriendship(f));
}

vector<Friendship>RepoFriendships::getAll(){
    vector<Friendship> all ;
    for(int i=0;i<friendslist.size();i++)
        all.push_back(friendslist[i]);
    return all;
}

int RepoFriendships::size() {
    return friendslist.size();
}

RepoFriendships::~RepoFriendships() = default;