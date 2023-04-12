

#ifndef SDTOYSOCIALNETWORK_REPOFRIENDSHIPS_H
#define SDTOYSOCIALNETWORK_REPOFRIENDSHIPS_H
#include "../Domain/Friendship.h"
#include "../TAD/List.h"
#include <vector>

/**
 * Clasa Repository pentru Friendships de tip lista
 */
class RepoFriendships {
private:
    List<Friendship> friendslist;
public:

    /**
     * Constructor implicit pentru clasa RepoFriendships
     */
    RepoFriendships();


    /**
     * Constructor cu parametrii
     * @param flist : lista de prietenii data
     */
    RepoFriendships(List<Friendship> & flist);


    /**
     * Adauga o prietenie in lista
     * @param f : prietenia pe care o adauga
     */
    void addFriendship(Friendship &f);


    /**
     * Cauta o prietenie in lista
     * @param f : prietenia pe care o cauta
     * @return pozitia daca il gaseste, sau -1 daca nu il gaseste
     */
    int findFriendship(Friendship &f);


    /**
     * Modifica o prietenie din lista
     * @param fvechi : prietenia pe care vrea sa o modifice
     * @param fnou datele noii prietenii
     */
    void updateFriendship(Friendship &fvechi, Friendship &fnou);


    /**
     * Sterge o prietenie din lista
     * @param f : prietenia pe care o sterge
     */
    void deleteFriendship(Friendship &f);


    /**
     * Obtine numarul de elemente
     * @return numarul de elemente
     */
    int size();


    /**
     * Obtine toate elementele din Repository
     * @return toate elementele din Repository
     */
    vector<Friendship> getAll();


    /**
     * Destructor pentru clasa RepoFriendships
     */
    ~RepoFriendships();
};



#endif //SDTOYSOCIALNETWORK_REPOFRIENDSHIPS_H
