
#include "TestRepository.h"
#include "../Repository/RepoUsers.h"
#include "../Repository/RepoFriendships.h"
#include "../Repository/RepoMesage.h"
#include <cassert>


void testRepoUsers(){
    User u1(1, "Maria", 18, "Franta");
    User u2(2, "Doris", 20, "Romania");
    User u3(3, "Andreea", 19, "Romania");
    User u4 = u3;
    u3.setName("Carla");

    RepoUsers repoUsers;
    repoUsers.addUser(u1);
    assert(repoUsers.size()==1);

    repoUsers.addUser(u2);
    repoUsers.addUser(u3);

    assert(repoUsers.size()==3);

    repoUsers.deleteUser(u3);

    assert(repoUsers.size()==2);
    assert(repoUsers.findUser(u1)==0);
    assert(repoUsers.findUser(u4)==-1);

}

void testRepoFriendships(){
    User u1(1, "Maria", 18, "Franta");
    User u2(2, "Doris", 20, "Romania");
    User u3(3, "Andreea", 19, "Romania");

    Friendship f1(u1,u2, 5, "Italia");
    Friendship f2(u2,u3,3,"Romania");
    Friendship f3(u3, u1, 1, "Oradea");

    RepoFriendships repoFriendships;
    repoFriendships.addFriendship(f1);

    assert(repoFriendships.size()==1);

    repoFriendships.addFriendship(f2);
    repoFriendships.addFriendship(f3);

    assert(repoFriendships.size()==3);

    repoFriendships.deleteFriendship(f3);

    assert(repoFriendships.size()==2);
    assert(repoFriendships.findFriendship(f1)==0);

}

void testRepoMessage(){
    User u1(1, "Maria", 18, "Franta");
    User u2(2, "Doris", 20, "Romania");
    User u3(3, "Andreea", 19, "Romania");

    Message m1(1,2,"Neata!");
    Message m2(2,1,"Salut!");
    Message m3( 2,3,"Multumesc");

    RepoMesage repoMesage;
    repoMesage.addMesage(m1);

    assert(repoMesage.size()==1);

    repoMesage.addMesage(m2);
    repoMesage.addMesage(m3);

    assert(repoMesage.size()==3);

    repoMesage.deleteMesage(m3);

    assert(repoMesage.size()==2);
    assert(repoMesage.findMesage(m1)==0);

}

void testAllRepository(){
    testRepoUsers();
    testRepoFriendships();
    testRepoMessage();
}