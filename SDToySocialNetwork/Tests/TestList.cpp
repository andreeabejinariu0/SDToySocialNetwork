

#include "TestList.h"
#include "../TAD/List.h"
#include <iostream>
#include <cassert>
void testImplicitConstructor(){

    List<int> list;

}

void testConstructorList(){

    int* array = new int[2];
    array[0] = 1;

    List<int> list(array, 2, 1);

    delete[] array;
}

void testEqualOperatorList(){

    int* array = new int[2];
    array[0] = 1;

    List<int> list(array, 2, 1);

    int* newArray = new int[3];
    newArray[0] = 1;
    newArray[1] = 2;

    List<int> newList(newArray, 3, 2);

    list = newList;

    assert(list == newList);

    delete[] array;
    delete[] newArray;

}

void testGetCapacity(){

    List<int> list;

    assert(list.getCapacity() == 10);

}

void testPushBack(){

    List<int> list;

    list.pushBack(1);
    list.pushBack(7);

    assert(list.size() == 2);

}

void testEmpty(){


    List<int> list;

    assert(list.empty());

    list.pushBack(1);

    assert(list.empty() == false);

}

void testInsert(){


    List<int> list;

    list.pushBack(1);
    list.pushBack(3);

    list.insert(1, 2);

    assert(list.size() == 3);
}

void testGetElem(){

    List<int> list;

    list.pushBack(1);
    list.pushBack(12);
    list.pushBack(3);

    assert(list.getElem(1) == 12);

}

void testDeleteElem()
{
    List<int> list;

    list.pushBack(1);
    list.pushBack(12);
    list.pushBack(3);

    list.deleteElem(1);
    assert(list.size() == 2);
}

void testAllList(){

    testImplicitConstructor();
    testConstructorList();
    testEqualOperatorList();
    testGetCapacity();
    testPushBack();
    testEmpty();
    testInsert();
    testGetElem();
    testDeleteElem();

}
