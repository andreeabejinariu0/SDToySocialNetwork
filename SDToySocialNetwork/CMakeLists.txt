cmake_minimum_required(VERSION 3.21)
project(SDToySocialNetwork)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDToySocialNetwork main.cpp
        Domain/User.cpp Domain/User.h
        Domain/Friendship.cpp Domain/Friendship.h
        Tests/TestList.cpp Tests/TestList.h Tests/TestEntitati.cpp Tests/TestEntitati.h Tests/TestAll.h UI/UI.cpp UI/UI.h Repository/RepoUsers.cpp Repository/RepoUsers.h TAD/ABCNode.h TAD/ABC.h Domain/Message.cpp Domain/Message.h TAD/List.h Repository/RepoFriendships.cpp Repository/RepoFriendships.h Repository/RepoMesage.cpp Repository/RepoMesage.h TAD/OrderSet.h Service/Service.cpp Service/Service.h Tests/TestRepository.cpp Tests/TestRepository.h)
