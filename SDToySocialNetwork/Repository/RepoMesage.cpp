

#include "RepoMesage.h"

RepoMesage::RepoMesage() =default;

RepoMesage::RepoMesage(List<Message> &ulist) {
    this->messageList = ulist;
}

void RepoMesage::addMesage(Message &u) {
    messageList.pushBack(u);
}

int RepoMesage::findMesage(Message &m) {
    for(int i=0;i<=messageList.size();i++)
        if(messageList[i]==m)
            return i;
    return -1;
}

void RepoMesage::updateMesage(Message &mvechi, Message &mnou) {
    if(findMesage(mvechi)!= -1)
        mvechi= mnou;
}


void RepoMesage::deleteMesage(Message &m) {
    if(findMesage(m) != -1)
        messageList.deleteElem(findMesage(m));
}




vector<Message>RepoMesage::getAll(){
    vector<Message> all ;
    for(int i=0;i<messageList.size();i++)
        all.push_back(messageList[i]);
    return all;
}

int RepoMesage::size() {
    return messageList.size();
}

RepoMesage::~RepoMesage() {
}