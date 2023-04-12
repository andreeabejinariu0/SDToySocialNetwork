#include"../Domain/User.h"
#include "../Domain/Friendship.h"
#include "../Domain/Message.h"
#include <cassert>

void testClasaUser() {
    User u1(1, "Maria", 18, "Franta");
    User u2(u1);
    User u3(2, "Doris", 20, "Romania");
    User u4(3, "Andreea", 19, "Romania");
    User u5 = u4;
    u3.setName("Carla");

    assert(u4 == u5);
    assert(u2.getName() == "Maria");
    assert(u2 == u1);
    assert(u3.getCountry() == "Romania");
}

void testClasaFriendship(){
    User u1(1, "Maria", 18, "Franta");
    User u2(2, "Doris", 20, "Romania");
    User u3(3, "Andreea", 19, "Romania");
    Friendship f1(u1,u2, 5, "Italia");
    Friendship f2(f1);
    Friendship f3(u2,u3,3,"Romania");
    Friendship f4 = f3;

    assert(f1==f2);
    assert(f3==f4);
    assert(f3.getLenght()==3);
    assert(f3.getPlace()=="Romania");
}

void testClasaMesaje(){
    User u1(1, "Maria", 18, "Franta");
    User u2(2, "Doris", 20, "Romania");
    User u3(3, "Andreea", 19, "Romania");

    Message m1(1,2,"Neata!");
    Message m2(2,1,"Salut!");
    Message m3( 2,3,"Multumesc");
    Message m4(m3);
    Message m5 = m2;


    assert(m4==m3);
    assert(m5==m2);
    assert(m1.getContent()=="Neata!");
    assert(m3.getContent()=="Multumesc");
}

void testAllEntitati(){
    testClasaUser();
    testClasaFriendship();
    testClasaMesaje();
}

