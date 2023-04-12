

#ifndef SDTOYSOCIALNETWORK_REPOUSERS_H
#define SDTOYSOCIALNETWORK_REPOUSERS_H
#include "../Domain/User.h"
#include "../TAD/OrderSet.h"
#include<vector>

/**
 * Clasa Repository pentru Useri de tip multime ordonata
 */
class RepoUsers {
private:
    OrderedSet<User> userset;
public:


    /**
     * Constructor implicit pentru clasa RepoUsers
     */
    RepoUsers();


    /**
     * Constructor cu parametrii
     * @param uset : multimea de useri data
     */
    RepoUsers(OrderedSet<User> & uset);


    /**
     * Adauga un user in multime
     * @param u: userul pe care il adauga
     */
    void addUser(User &u);


    /**
     * Cauta un user in multime
     * @param u : userul pe care il cauta
     * @return pozitia daca il gaseste, sau -1 daca nu il gaseste
     */
    int findUser(User &u);


    /**
     * Modifica un user din multime
     * @param uvechi : userul pe care vrea sa il modifice
     * @param unou : datele noului user cu care il modifica
     */
    void updateUser(User &uvechi, User &unou);


    /**
     * Sterge un user din multime
     * @param u : userul pe care il sterge
     */
    void deleteUser(User &u);


    /**
     * Cauta un user in functie de id
     * @param id : id-ul dupa care cauta userul
     * @return userul cautat
     */
    User findById(int id);


   /**
    * Obtine numarul de elemente
    * @return numarul de elemente
    */
    int size();


    /**
     * Obtine toate elementele din Repository
     * @return toate elementele din Repository
     */
    vector<User>getAll() ;


    /**
     * Destructor pentru clasa RepoUsers
     */
    ~RepoUsers();
};


#endif //SDTOYSOCIALNETWORK_REPOUSERS_H
