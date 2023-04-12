

#ifndef SDTOYSOCIALNETWORK_ORDERSET_H
#define SDTOYSOCIALNETWORK_ORDERSET_H
#include "ABC.h"
#include <vector>

template<class T>
class ABC;

template<class T>
/**
* Implementarea multimii ordonate cu reprezentare pe arbore
* @tparam T: tipul elementelor care contine nodul
*/
class OrderedSet{
private:
    ABC<T> tree;
    int numberOfElements{};


    /**
     * Afiseaza toate elementele multimii
     * @param node: pointer catre inceputul arborelui
     * @param all : multimea
     */
    void getAll(ABCNode<T>*node, vector<T> & all);
public:

    /**
     * Constructor implicit pentru clasa OrderSet
     */
    OrderedSet();

    /**
     * Constructor cu parametrii
     *
     * @param t: arborele
     * @param nr : numarul de elemente al multimii
     */
    OrderedSet(ABC<T>& t  , int nr);


    /**
     * Constructor de copiere
     * @tparam T :tipul multimii
     * @param paramSet : multimea
     */
    OrderedSet(OrderedSet<T> &paramSet);


    /**
    * Adauga un element in multime
    * @tparam T :tipul elementului
    * @param elem :elementul
    */
    void add(T &elem);


    /**
    * Sterge un element din multime
    * @tparam T :tipul elementului
    * @param elem :elementul
    */
    void remove(T elem);


    /**
    * Cauta un element in multime
    * @tparam T :tipul elementului
    * @param elem :elementul
    */
    void search(T &elem);


    /**
    * Operatorul ==, compară două multimi
    * @tparam T : tiupl multimii
    * @param m : multimea de comparat
    * @return adevarat/fals
    */
    bool operator==(const OrderedSet<T>&);


    /**
    * Obține numărul de elemente din multime
    * @return numărul de elemente din multime
    */
    int size();


    /**
    * Operatorul [],atribuie unui element din multime in fuctie de pozitie
    * @tparam T : tiupl multimii
    * @param poz: pozitia din multime
    * @return elementul din pozitia respectiva
    */
    T operator[](int poz);


    /**
     * Obtine toate elementele din multime
     * @return multimea
     */
    vector<T> getAll();


    /**
    * Destructor pentru multime
     */
    ~OrderedSet();

    friend class ABC<T>;

};
template<class T>
OrderedSet<T>::OrderedSet() {
    this->tree = ABC<T>();
    this->numberOfElements= 0;
}

template<class T>
OrderedSet<T>::OrderedSet(ABC<T>& t,int nr) {
    this->tree= t;
    this->numberOfElements = nr;
}


template<class T>
OrderedSet<T>::OrderedSet(OrderedSet<T> &paramSet) {

    this->tree= paramSet.tree;
    this->numberOfElements = paramSet.numberOfElements;

}

template<class T>
void OrderedSet<T>::add(T &elem) {
    if(!this->tree.search(elem)) {
        this->tree.add(elem);
        this->numberOfElements++;
    }
}

template<class T>
int OrderedSet<T>::size() {
    return this->numberOfElements;
}

template<class T>
void OrderedSet<T>::remove(T elem) {
    this->tree.remove(elem);
    this->numberOfElements--;
}

template<class T>
void OrderedSet<T>::search(T& elem) {
    this->tree.search(elem);
}


template<class T>
void OrderedSet<T>::getAll(ABCNode<T> *node, vector <T> &all) {
    if(node != nullptr)
    {
        getAll(node->getLeft(), all);
        all.push_back(node->getInfo());
        getAll(node->getRight(), all);
    }
}

template<class T>
vector<T> OrderedSet<T>::getAll() {
    vector<T> all;
    getAll(this->tree.getRoot(), all);
    return all;
}


template<class T>
T OrderedSet<T>::operator[](int poz) {
    if(poz >= 0 && poz< this->numberOfElements)
        return getAll()[poz];
}

template<class T>
bool OrderedSet<T>::operator==(const OrderedSet<T>& m) {
    return((this->tree == m.tree) and (this->numberOfElements == m.numberOfElements));
}

template<class T>
OrderedSet<T>::~OrderedSet<T>() {
    this->numberOfElements = 0;
}


#endif //SDTOYSOCIALNETWORK_ORDERSET_H
