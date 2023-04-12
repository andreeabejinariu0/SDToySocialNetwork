

#ifndef SDTOYSOCIALNETWORK_UI_H
#define SDTOYSOCIALNETWORK_UI_H
#include "../Service/Service.h"
class UI {
private:
    Service service;


    void addUser();
    void getAllUser();
    void updateUser();
    void findUser();
    void deleteUser();
    void showSameAgeUser();


    void addFriendship();
    void getAllFriendship();
    void updateFrienship();
    void getFriendshipByUser();
    void orderFriendshipByLength();
    void findFriendship();
    void deleteFriendship();


    void addMessage();
    void getAllMessage();
    void updateMessage();
    void findMessage();
    void deleteMessage();
    void getConversation();

public:

    /**
     * Constructor implicit pentru clasa UI
     */
    UI();

    /**
     * Constructor cu parametrii
     * @param s : service-ul
     */
    UI(Service &s);


    /**
     * Meniu de operatii pentru useri
     */
    void menuUser();


    /**
     * Meniu de operatii pentru prietenii
     */
    void menuFriendship();


    /**
     * Meniu de operatii pentru mesaje
     */
    void menuMessage();


    /**
     * Meniul tuturor operatiilor
     */
    void run_menu();


    /**
     * Destructor pentru clasa UI
     */
    ~UI();
};


#endif //SDTOYSOCIALNETWORK_UI_H
