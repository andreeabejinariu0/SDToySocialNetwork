

#ifndef SDTOYSOCIALNETWORK_SERVICE_H
#define SDTOYSOCIALNETWORK_SERVICE_H
#include "../Repository/RepoUsers.h"
#include "../Repository/RepoFriendships.h"
#include "../Repository/RepoMesage.h"

class Service {
private:
    RepoUsers repoUsers;
    const char *filenameUser;
    RepoFriendships repoFriendships;
    const char *filenameFriendship;
    RepoMesage repoMesage;
    const char *filenameMesage;
public:


    /**
     * Constructor implicit pentru clasa Service
     */
    Service();


    /**
     * Constructor cu parametrii
     * @param ru : repository cu useri
     * @param filenameUser : fisierul cu useri
     * @param rf : repository cu prietenii
     * @param filenameFriendship : fisierul cu prietenii
     * @param rm : repository cu mesaje
     * @param filenameMesage : fisierul cu mesaje
     */
    Service(RepoUsers &ru, const char *filenameUser,
            RepoFriendships &rf,const char *filenameFriendship,
            RepoMesage &rm ,const char *filenameMesage);


    /**
     * Adauga un user in repository
     * @param id : id-ul userului
     * @param name : numele userului
     * @param age : varsta userului
     * @param country : tara userului
     */
    void addUser(int id, string name, int age, string country);


    /**
     * Cauta un user in repository
     * @param id : id-ul userului
     * @param name  : numele userului
     * @param age : varsta userului
     * @param country : tara userului
     * @return adevarat/fals
     */
    bool findUser(int id, string name, int age, string country);


    /**
     * Modifica un user din repository
     * @param id : id-ul vechi al  userului
     * @param name : numele vechi al userului
     * @param age : varsta veche a  userului
     * @param country : tara veche a userului
     * @param namenou : noul nume al userului
     * @param agenou : noua varsta a userului
     * @param countrynou : noua tara a userului
     */
    void updateUser(int id,string name, int age, string country, string namenou, int agenou, string countrynou );


    /**
     * Sterge un user din repository
     * @param id :  id-ul userului pe care il sterge
     * @param name  : numele userului pe care il sterge
     * @param age : varsta userului pe care il sterge
     * @param country  : tara userului pe care il sterge
     */
    void deleteUser(int id, string name, int age, string country);


    /**
     * Cauta un user in functie de id
     * @param id : id-ul dat
     * @return un user
     */
    User findById(int id);


    /**
     * Filtreaza userii in functie de o varsta data
     * @param age : varsta data
     * @return un vector cu userii cu aceeasi varsta
     */
    vector<User> showSameAge(int age);


    /**
     * Citeste userii din fisier
     * @param f_name : numele fisierului
     */
    void readFileUser(const char *f_name);


    /**
     * Salveaza userii in fisier
     */
    void saveToFileUser();


    /**
     * Obtine numarul userilor din repository
     * @return numarul userilor din repository
     */
    int sizeUser();


    /**
     * Obtine toti userii din repository
     * @return toti userii din repository
     */
    vector<User>getAllUser() ;



    /**
     * Adauga o prietenie in repository
     * @param Friend1 : userul primului prieten
     * @param Friend2 : userul al doilea prieten
     * @param lenght : durata prieteniei
     * @param place : locul intalnirii
     */
    void addFriendship( const User& Friend1,const User& Friend2,int lenght, string place);


    /**
     * Cauta o prietenie in repository
     * @param Friend1 : userul primului prieten
     * @param Friend2  : userul al doilea prieten
     * @param lenght : durata prieteniei
     * @param place : locul intalnirii
     * @return adevarat/fals
     */
    bool findFriendship(const User& Friend1, const User& Friend2, int lenght, string place);


    /**
     * Modifica o prietenie din repository
     * @param Friend1 : userul primului prieten
     * @param Friend2 : userul al doilea prieten
     * @param lenght : durata  veche a prieteniei
     * @param place : locul intalnirii
     * @param lenghtnou : durata  noua a prieteniei
     */
    void updateFriendship(const User& Friend1,const User& Friend2,int lenght, const string& place, int lenghtnou );


    /**
     * Sterge o prietenie din repository
     * @param Friend1 : userul primului prieten
     * @param Friend2 : userul al doilea prieten
     * @param lenght : durata prieteniei
     * @param place : locul intalnirii
     */
    void deleteFriendship( const User& Friend1,const User& Friend2,int lenght, string place);


    /**
     * Citeste prietenii din fisier
     * @param f_name : numele fisierului
     */
    void readFileFriendship(const char *f_name);


    /**
     * Salveaza prietenii in fisier
     */
    void saveToFileFriendship();


    /**
     * Obtine prietenii in functie de userul primului prieten
     * @param u : userul primului prieten
     * @return prietenii in functie de userul primului prieten
     */
    vector<Friendship> getFriendshipByUserFriend1(const User& u);


    /**
     * Obtine prietenii in functie de userul celui de-al doilea prieten
     * @param u : userul celui de-al doilea prieten
     * @return prietenii in functie de userul celui de-al doilea prieten
     */
    vector<Friendship> getFriendshipByUserFriend2(const User& u);


    /**
     * Ordoneaza prieteniile crescator dupa durata prieteniei
     * @return un vector ordonat crescator dupa durata prieteniei
     */
    vector<Friendship> orderFriendshipByLength();


    /**
     * Obtine numarul de prietenii din repository
     * @return numarul de prietenii din repository
     */
    int sizeFriendship();


    /**
     * Obtine toate prieteniile din repository
     * @return toate prieteniile din repository
     */
    vector<Friendship> getAllFriendship();



    /**
     * Adauga un mesaj in repository
     * @param senderId : id-ul celui care trimite mesajul
     * @param recieverId : id-ul celui care primeste mesajul
     * @param content : continutul mesajului
     */
    void addMessage(  int senderId, int recieverId, string content);


    /**
     * Modifica un mesaj din  repository
     * @param senderId : id-ul celui care trimite mesajul
     * @param recieverId : id-ul celui care primeste mesajul
     * @param content : continutul vechi al  mesajului
     * @param contentnou : continutul nou al mesajului
     */
    void updateMessage(int senderId, int recieverId, string content, string contentnou );


    /**
     * Cauta un mesaj in repository
     * @param senderId : id-ul celui care trimite mesajul
     * @param recieverId : id-ul celui care primeste mesajul
     * @param content : continutul mesajului
     * @return adevarat/fals
     */
    bool findMessage(int senderId, int recieverId, string content);


    /**
     * Sterge un mesaj din repository
     * @param senderId  : id-ul celui care trimite mesajul
     * @param recieverId : id-ul celui care primeste mesajul
     * @param content : continutul mesajului
     */
    void deleteMessage( int senderId, int recieverId, string content);


    /**
     * Citeste mesajele din fisier
     * @param f_name: numele fisierului
     */
    void readFileMessage(const char *f_name);


    /**
     * Salveaza prieteniile in fisier
     */
    void saveToFileMessage();


    /**
     * Obtine numarul mesajelor din repository
     * @return
     */
    int sizeMessage();


    /**
     * Obtine mesajele dintre 2 useri
     * @param idfriend1 : id-ului primului prieten
     * @param idfriend2 : id-ul celui de-al doilea prieten
     * @return un vector ce contine mesajele celor 2 useri
     */
    vector<Message> getConversation(int idfriend1, int idfriend2);


    /**
     * Obtine toate mesajele din repository
     * @return toate mesajele din repository
     */
    vector<Message>getAllMessage();


    /**
     * Destructor pentru clasa Service
     */
    ~Service();

};


#endif //SDTOYSOCIALNETWORK_SERVICE_H
