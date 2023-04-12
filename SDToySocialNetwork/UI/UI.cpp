
#include "UI.h"

UI::UI()
= default;



UI::UI(Service &s)
{
    this->service = s;
}

void UI::menuUser(){

    int optiune;
    do{
        cout<<"1. Afiseaza toti useri."<<endl;
        cout<<"2. Insereaza un user."<<endl;
        cout<<"3. Modifica un user."<<endl;
        cout<<"4. Cauta un user."<<endl;
        cout<<"5. Sterge un user."<<endl;
        cout<<"6. Afiseaza toti useri cu aceeasi varsta data. "<<endl;
        cout<<"0. Iesire."<<endl;
        cout<<"Dati optiunea: "; cin>>optiune;
        switch (optiune) {
            case 1:
                getAllUser();
                break;
            case 2:
                addUser();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                findUser();
                break;
            case 5:
                deleteUser();
                break;
            case 6:
                showSameAgeUser();
                break;
            case 0:
                break;
            default:
                cout<<"Optiune gresita! Reincercati!"<<endl;
        }
    }while(optiune!=0);
}


void UI::getAllUser() {
    cout<<"Toti userii sunt: "<<endl;
    vector<User> all = this->service.getAllUser();
    for(User u : all)
        cout<<u<<endl;
}


void UI::addUser() {
    int id, age;
    string name, country;
    cout<<"Dati Userul:"<<endl;
    cout<<"Dati id-ul userului: "; cin>>id;
    cout<<"Dati numele userului: ";cin>>name;
    cout<<"Dati varsta userului : ";cin>>age;
    cout<<"Dati tara userului : ";cin>>country;
    this->service.addUser(id, name, age, country);
}

void UI::updateUser() {
    int id, age, agenou;
    string name, country, namenou, countrynou;
    cout<<"Dati userul care vreti sa il modificati:"<<endl;
    cout<<"Dati id-ul userului: "; cin>>id;
    cout<<"Dati numele userului: ";cin>>name;
    cout<<"Dati varsta userului : ";cin>>age;
    cout<<"Dati tara userului : ";cin>>country;
    User uvechi(id, name, age, country);
    cout<<"Dati noul nume al userului: ";cin>>namenou;
    cout<<"Dati noua varsta a userului : ";cin>>agenou;
    cout<<"Dati noua tara a userului : ";cin>>countrynou;
    User unou(id, namenou, agenou, countrynou);
    this->service.updateUser(id, name, age, country, namenou, agenou, countrynou);
}

void UI::findUser() {
    int id, age;
    string name, country;
    cout<<"Dati userul pe care il cautati:"<<endl;
    cout<<"Dati id-ul userului: "; cin>>id;
    cout<<"Dati numele userului: ";cin>>name;
    cout<<"Dati varsta userului : ";cin>>age;
    cout<<"Dati tara userului : ";cin>>country;
   if( this->service.findUser(id, name, age, country))
       cout<<"Userul a fost gasit."<<endl;
   else
       cout<<"Userul nu a fost gasit."<<endl;
}

void UI::deleteUser() {
    int id, age;
    string name, country;
    cout<<"Dati userul pe care vreti sa il stergeti:"<<endl;
    cout<<"Dati id-ul userului: "; cin>>id;
    cout<<"Dati numele userului: ";cin>>name;
    cout<<"Dati varsta userului : ";cin>>age;
    cout<<"Dati tara userului : ";cin>>country;
    this->service.deleteUser(id, name, age, country);
}

void UI::showSameAgeUser(){
    int age;
    cout<<"Dati varsta pentru care sa afiseze userii: "; cin>>age;
    vector<User> rezultat =service.showSameAge(age);
    cout<<"Userii cu varsta "<<age<<" sunt: "<<endl;
    for(User u: rezultat)
        cout<<u<<endl;
}

void UI::menuFriendship() {
    int optiune;
    do{
        cout<<"1. Afiseaza toate prieteniile."<<endl;
        cout<<"2. Insereaza o prietenie."<<endl;
        cout<<"3. Modifica o prietenie."<<endl;
        cout<<"4. Cauta o prietenie."<<endl;
        cout<<"5. Sterge o prietenie."<<endl;
        cout<<"6. Afiseaza prietenii unui user dat."<<endl;
        cout<<"7. Afiseaza prieteniile ordonate dupa durata prieteniei"<<endl;
        cout<<"0. Iesire."<<endl;
        cout<<"Dati optiunea: "; cin>>optiune;
        switch (optiune) {
            case 1:
                getAllFriendship();
                break;
            case 2:
                addFriendship();
                break;
            case 3:
                updateFrienship();
                break;
            case 4:
                findFriendship();
                break;
            case 5:
                deleteFriendship();
                break;
            case 6:
                getFriendshipByUser();
                break;
            case 7:
                orderFriendshipByLength();
                break;
            case 0:
                break;
            default:
                cout<<"Optiune gresita! Reincercati!"<<endl;
        }
    }while(optiune!=0);
}


void UI::addFriendship() {
    int idFriend1, idFriend2, lenght;
    string place;
    cout<<"Dati Prietenia:"<<endl;
    cout<<"Dati id-ul primului prieten: "; cin>>idFriend1;
    cout<<"Dati id-ul al doilea prieten: ";cin>>idFriend2;
    cout<<"Dati durata prieteniei (ani) : ";cin>>lenght;
    cout<<"Dati locul intalnirii : ";cin>>place;

    this->service.addFriendship( this->service.findById(idFriend1),  this->service.findById(idFriend2), lenght, place);
}

void UI::getAllFriendship()  {
    cout<<"Toate prietenile sunt sunt: "<<endl;
    vector<Friendship> all = this->service.getAllFriendship();
    for(int i=0;i<service.sizeFriendship();i++)
        cout<<all[i].getFriend1().getName()<<" este prieten cu: "<<
        all[i].getFriend2().getName()<<" cu durata de "<<all[i].getLenght()<<" ani si s-au intalnit la: "<<all[i].getPlace()<<endl;
}

void UI::updateFrienship() {
    int idFriend1, idFriend2, lenght, lenghtnou;
    string place;
    cout<<"Dati prietenia care sa se modifice:"<<endl;
    cout<<"Dati id-ul primului prieten: "; cin>>idFriend1;
    cout<<"Datiid-ul al doilea prieten: ";cin>>idFriend2;
    cout<<"Dati durata prieteniei (ani) : ";cin>>lenght;
    cout<<"Dati locul intalnirii : ";cin>>place;
    cout<<"Dati noua durata a  prieteniei (ani) : ";cin>>lenghtnou;
    this->service.updateFriendship(this->service.findById(idFriend1), this->service.findById(idFriend2), lenght, place, lenghtnou);
}

void UI::deleteFriendship() {
    int idFriend1, idFriend2, lenght;
    string place;
    cout<<"Dati prietenia pe care doriti sa o stergeti:"<<endl;
    cout<<"Dati id-ul primului prieten: "; cin>>idFriend1;
    cout<<"Datiid-ul al doilea prieten: ";cin>>idFriend2;
    cout<<"Dati durata prieteniei (ani) : ";cin>>lenght;
    cout<<"Dati locul intalnirii : ";cin>>place;
    this->service.deleteFriendship(this->service.findById(idFriend1), this->service.findById(idFriend2), lenght, place);
}

void UI::getFriendshipByUser(){
    int id;
    cout<<"Dati id-ul userului pentru care cautati prietenii: ";cin>>id;
    vector<Friendship> friend1 = this->service.getFriendshipByUserFriend1(service.findById(id));
    vector<Friendship> friend2 = this->service.getFriendshipByUserFriend2(service.findById(id));
    cout<<service.findById(id).getName()<<" este prieten cu: "<<endl;
    for(int i=0;i<friend1.size();i++)
       cout<<friend1[i].getFriend2().getName()<<" de "<<friend1[i].getLenght()<<" ani."<<endl;
    for(int i=0;i<friend2.size();i++)
        cout<<friend2[i].getFriend1().getName()<<" de "<<friend2[i].getLenght()<<" ani."<<endl;
}

void UI::orderFriendshipByLength(){
    vector<Friendship> rezultat = service.orderFriendshipByLength();
    cout<<"Prieteniile sortate crescator dupa durata prieteniei sunt: "<<endl;
    for(int i=0;i<rezultat.size();i++)
        cout<<rezultat[i].getFriend1().getName()<<" este prieten cu: "<<
        rezultat[i].getFriend2().getName()<<" cu durata de "<<rezultat[i].getLenght()<<endl;
}

void UI::findFriendship() {
    int idFriend1, idFriend2, lenght;
    string place;
    cout<<"Dati Prietenia pe care o cautati:"<<endl;
    cout<<"Dati id-ul primului prieten: "; cin>>idFriend1;
    cout<<"Dati id-ul al doilea prieten: ";cin>>idFriend2;
    cout<<"Dati durata prieteniei (ani) : ";cin>>lenght;
    cout<<"Dati locul intalnirii : ";cin>>place;
    if(this->service.findFriendship(this->service.findById(idFriend1), this->service.findById(idFriend2), lenght, place))
        cout<<"Prietenia a fost gasita."<<endl;
    else
        cout<<"Prietenia nu a fost gasita."<<endl;
}

void UI::menuMessage()  {
    int optiune;
    do{
        cout<<"1. Afiseaza toate mesajele."<<endl;
        cout<<"2. Insereaza un mesaj."<<endl;
        cout<<"3. Modifica  un mesaj."<<endl;
        cout<<"4. Cauta  un mesaj."<<endl;
        cout<<"5. Sterge  un mesaj."<<endl;
        cout<<"6. Afisare mesaje intre 2 useri"<<endl;
        cout<<"0. Iesire."<<endl;
        cout<<"Dati optiunea: "; cin>>optiune;
        switch (optiune) {
            case 1:
                getAllMessage();
                break;
            case 2:
                addMessage();
                break;
            case 3:
                updateMessage();
                break;
            case 4:
                findMessage();
                break;
            case 5:
                deleteMessage();
                break;
            case 6:
                getConversation();
                break;
            case 0:
                break;
            default:
                cout<<"Optiune gresita! Reincercati!"<<endl;
        }
    }while(optiune!=0);
}

void UI::addMessage() {
    int senderId, receiverId;
    string content;
    cout<<"Dati Mesajul:"<<endl;
    cout<<"Dati id-ul celui care trimite: "; cin>>senderId;
    cout<<"Dati id-ul celui care primeste: ";cin>>receiverId;
    cout<<"Dati continutul mesajului : ";cin>>content;
    this->service.addMessage(senderId, receiverId, content);
}

void UI::getAllMessage()   {
    cout<<"Toate mesajele sunt sunt: "<<endl;
    vector<Message> all = this->service.getAllMessage();
    for(int i=0;i<service.sizeMessage();i++)
        cout<<"De la "<<service.findById(all[i].getSenderId()).getName()<<
        " pentru "<<service.findById(all[i].getReceiverId()).getName()<<" cu mesajul: "<<all[i].getContent()<<endl;
}

void UI::updateMessage() {
    int senderId, receiverId;
    string content, contentNou;
    cout<<"Dati mesajul pe care vreti sa il modificati:"<<endl;
    cout<<"Dati id-ul celui care trimite: "; cin>>senderId;
    cout<<"Dati id-ul celui care primeste: ";cin>>receiverId;
    cout<<"Dati continutul mesajului : ";cin>>content;
    cout<<"Dati continutul noului mesaj: ";cin>>contentNou;
    this->service.updateMessage(senderId, receiverId, content, contentNou);
}

void UI::deleteMessage() {
    int senderId, receiverId;
    string content;
    cout<<"Dati mesajul pe care vreti sa il stergeti:"<<endl;
    cout<<"Dati id-ul celui care trimite: "; cin>>senderId;
    cout<<"Dati id-ul celui care primeste: ";cin>>receiverId;
    cout<<"Dati continutul mesajului : ";cin>>content;
    this->service.deleteMessage(senderId, receiverId, content);
}

void UI::findMessage() {
    int senderId, receiverId;
    string content;
    cout<<"Dati mesajul pe care vreti sa il stergeti:"<<endl;
    cout<<"Dati id-ul celui care trimite: "; cin>>senderId;
    cout<<"Dati id-ul celui care primeste: ";cin>>receiverId;
    cout<<"Dati continutul mesajului : ";cin>>content;
    if(this->service.findMessage(senderId, receiverId, content))
        cout<<"Mesajul a fost gasit."<<endl;
    else
        cout<<"Mesajul nu a fost gasit."<<endl;
}

void UI::getConversation(){
    int idfriend1, idfriend2;
    cout<<"Dati id-ul primului prieten pentru care cautati mesaje: ";cin>>idfriend1;
    cout<<"Dati id-ul celui de al doilea prieten : ";cin>>idfriend2;
    vector<Message> rez = service.getConversation(idfriend1, idfriend2);
    for(int i=0;i<rez.size();i++)
        cout<<"De la "<<service.findById(rez[i].getSenderId()).getName()<<
            " pentru "<<service.findById(rez[i].getReceiverId()).getName()<<" cu mesajul: "<<rez[i].getContent()<<endl;
}

void print_menu() {
    cout << "1. Meniu User" << endl;
    cout << "2. Meniu Prietenii" << endl;
    cout << "3. Meniu Mesaje" << endl;
    cout << "0. Inchidere" << endl;
}
void UI::run_menu() {
    int optiune;
    do {
        print_menu();
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        switch (optiune) {
            case 1:
            {
                menuUser();
                break;
            }
            case 2:
            {
                menuFriendship();
                break;
            }
            case 3: {
                menuMessage();
                break;
            }
            case 0: {
                break;
            }
            default:
                cout<<"Optiune gresita! Reincercati!"<<endl;
        }
    } while (optiune != 0);
}

UI::~UI()
= default;