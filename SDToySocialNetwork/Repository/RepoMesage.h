

#ifndef SDTOYSOCIALNETWORK_REPOMESAGE_H
#define SDTOYSOCIALNETWORK_REPOMESAGE_H
#include "../Domain/Message.h"
#include "../TAD/List.h"
#include <vector>

/**
 * Clasa Repository pentru Mesaje de tip lista
 */
class RepoMesage {
private:
    List<Message> messageList;
public:

    /**
     * Constructor implicit pentru clasa RepoMesage
     */
    RepoMesage();


    /**
     * Constructor cu parametrii
     * @param mlist : lista de mesaje data
     */
    RepoMesage(List<Message> & mlist);


    /**
     * Adauga un mesaj in lista
     * @param m : mesajul pe care il adauga
     */
    void addMesage(Message &m);


    /**
     * Cauta un mesaj in lista
     * @param m : mesajul pe care il cauta
     * @return pozitia daca il gaseste, sau -1 daca nu il gaseste
     */
    int findMesage(Message &m);


    /**
     * Modifica un mesaj din lista
     * @param mvechi : mesajul pe care vrea sa il modifice
     * @param mnou datele noului mesaj
     */
    void updateMesage(Message &mvechi, Message &mnou);


    /**
     * Sterge un mesaj din lista
     * @param m : mesajul pe care il sterge
     */
    void deleteMesage(Message &m);


    /**
     * Obtine numarul de elemente
     * @return numarul de elemente
     */
    int size();

    /**
     * Obtine toate elementele din Repository
     * @return toate elementele din Repository
     */
    vector<Message> getAll();


    /**
     * Destructor pentru clasa RepoMesage
     */
    ~RepoMesage();
};


#endif //SDTOYSOCIALNETWORK_REPOMESAGE_H
