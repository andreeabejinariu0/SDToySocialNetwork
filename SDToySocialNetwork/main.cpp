#include <iostream>
#include "TAD/List.h"
#include "Domain/User.h"
#include "Domain/Friendship.h"
#include "Domain/Message.h"
#include "Repository/RepoUsers.h"
#include "Repository/RepoFriendships.h"
#include "Repository/RepoMesage.h"
#include "UI/UI.h"
#include "Tests/TestAll.h"
using namespace std;

int main() {
    testAll();

    RepoUsers repoUser;
    RepoMesage repoMesage;
    RepoFriendships repoFriendships;

    Service service(repoUser,"users.txt",
                    repoFriendships,"friendships.txt",
                    repoMesage, "messages.txt");
    UI ui(service);
    ui.run_menu();


    return 0;

}
