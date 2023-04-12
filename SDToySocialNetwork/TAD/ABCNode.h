

#ifndef SDTOYSOCIALNETWORK_ABCNODE_H
#define SDTOYSOCIALNETWORK_ABCNODE_H
#include<iostream>
using namespace std;
template<typename T>
class ABC;

template<class T>
/**
* Implementarea nodului pentru arbore cu elemente generice
* @tparam T: tipul elementelor care contine nodul
*/
class ABCNode{
private:
    T info;
    ABCNode<T>* left;
    ABCNode<T>* right;
public:

    /**
    * Constructor implicit pentru clasa ABCNode, doar cu informatia nodului
    */
    explicit ABCNode(T info);


    /**
     * Constructor cu parametrii
     * @tparam T: tipul nodului
     * @param info = informatia nodului
     * @param left = pointer catre nodul din stanga
     * @param right = pointer catre nodul din dreapta
     */
    ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right) ;

    /**
     * Operatorul ==, compară două noduri
     * @tparam T: tipul nodului
     * @param paramNode: nodul de comparat
     * @return adevarat/fals
     */
    bool operator==(const ABCNode&) ;


    /**
     * Obtine informatia nodului
     * @return informatia nodului
     */
    T getInfo();


    /**
     * Obtine pointerul catre nodul din stanga
     * @return pointer catre nodul din stanga
     */
    ABCNode<T>* getLeft();


    /**
     * Obtine pointerul catre nodul din dreapta
     * @return  pointerul catre nodul din dreapta
     */
    ABCNode<T>* getRight();

    friend class ABC<T>;

    /**
    * Suprascrie operatorul de afisare <<
    * @param os : modalitatea de afisare
    * @param node : nodul
    * @return os, indicatii despre afisare
    */
    friend ostream& operator<<(ostream& os, ABCNode&);
};


template<class T>
ABCNode<T>::ABCNode(T info) {

    this->info = info;
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
ABCNode<T>::ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right){

    this->info = info;
    this->left = left;
    this->right = right;
}

template<class T>
T ABCNode<T>::getInfo() {

    return this->info;
}


template<class T>
ABCNode<T>* ABCNode<T>::getLeft() {

    return this->left;
}

template<class T>
ABCNode<T>* ABCNode<T>::getRight() {

    return this->right;
}

template<class T>
bool ABCNode<T>::operator==(const ABCNode<T> &node) {

    return((this->info == node.info) and (this->right == node.right) and (this->left == node.left));
}

template<class T>
ostream& operator<<(ostream& os, ABCNode<T>& node){

    os<<node.info;
    return os;
}

#endif //SDTOYSOCIALNETWORK_ABCNODE_H
