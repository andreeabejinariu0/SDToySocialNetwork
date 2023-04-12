
#ifndef SDTOYSOCIALNETWORK_LIST_H
#define SDTOYSOCIALNETWORK_LIST_H


#include <iostream>
using namespace std;

template<class T>
/**
 * Lista cu elemente generice cu reprezentare pe array
 * @tparam T: tipul elementelor care contine lista
 */
class List{
private:
    T* list;
    int capacity;
    int numberOfElements;
public:

    /**
    * Constructor implicit pentru clasa Lista, fara parametrii
    */
    List();


    /**
    * Constructori cu parametrii
    *
    * @param paramList = pointer catre vector;
    * @param paramCapacity = capacitatea vectorului;
    * @param paramNumberOfElements = numarul de elemente din lista
    */
    List(T*, int, int);


    /**
    * Constructor de copiere
    * @tparam T :tipul listei
    * @param paramList : lista
    */
    List(List<T>&);


    /**
     * Destructor pentru lista
    */
    ~List();


    /**
    * Operator = pentru listă, modifica datele din aceasta în datele din paramList
    * @tparam T : tipul listei
    * @param paramList :lista care urmeaza sa fie copiata
    * @return lista, dupa ce s-au facut modificari
     */
    List<T>& operator=(const List<T>&);

    /**
    * Operatorul ==, compară două liste
    * @tparam T : tiupl listei
    * @param paramList : lista de comparat
    * @return adevarat/fals
    */
    bool operator==(const List<T>&);

    /**
     * Operatorul [],atribuie unui element din lista in fuctie de pozitie
     * @param index: pozitia din lista
     * @return elementul din pozitia respectiva
     */
    T& operator[](int index);


    /**
     * Adauga un element in lista
    * @tparam T :tipul elementului
     * @param elem :elementul
    */
    void pushBack(T);


    /**
    * Obține numărul de elemente din listă
    * @tparam T :tipul listei
    * @return numărul de elemente din listă
    */
    int size() const;


    /**
    * Obtine capacitatea listei
    * @tparam T :tipul listei
    * @return capacitatea listei
    */
    int getCapacity() const;


    /**
    * Verifica daca lista este goala
    * @tparam T :tipul listei
    * @return adevarat/fals
    */
    bool empty();


    /**
    * Inserează un element în poziția indexului
    * @param index: index
    * @param elem: element
    * @tparam T: tipul elementului
    */
    void insert(int, T);


    /**
     * Obține elementul dintr-o poziție
    * @tparam T :tipul elementului
    * @param index :pozitia
    * @return element din pozitia introdusa
    */
    T getElem(int);


    /**
    * Șterge elementul dintr-o poziție
     * @tparam T : tipul elementului
    * @param index :pozitia
    */
    void deleteElem(int);


    /**
     * Suprascrie operatorul de afisare <<
     * @param os : modalitatea de afisare
     * @param list : lista
     * @return os, indicatii despre afisare
     */
    friend ostream& operator<<(ostream& os, List<T>& list)
    {
        for(int i=0;i<list.size();i++) {
            os<< list[i]<<" "<<endl;
        }
        os<<endl;
        return os;
    }

};


#include "List.h"

template<class T>
List<T>::List()
{

    this->list = new T[10];
    this->capacity = 10;
    this->numberOfElements = 0;
}

template<class T>
List<T>::List(T *paramList, int paramCapacity, int paramNumberOfElements)
{

    this->list = new T[paramCapacity];
    for(int  i = 0; i < paramNumberOfElements; i++)
        this->list[i] = paramList[i];

    this->capacity = paramCapacity;

    this->numberOfElements = paramNumberOfElements;

}

template<class T>
List<T>::List(List<T> &paramList)
{

    if(this->list != nullptr)
    {
        delete[] this->list;
        this->list = nullptr;
    }

    this->list = new T[paramList.capacity];
    for(int i = 0; i < paramList.capacity; i++)
        this->list[i] = paramList.list[i];

    this->capacity = paramList.capacity;
    this->numberOfElements = paramList.numberOfElements;

}



template<class T>
List<T>::~List<T>()
{

    delete[] this->list;
    this->capacity = 0;
    this->numberOfElements = 0;
}

template<class T>
List<T>& List<T>::operator=(const List<T> &paramList)

{

    if(this == &paramList)
        return *this;

    this->list = new T[paramList.capacity];
    for(int i = 0; i < paramList.capacity; i++)
        this->list[i] = paramList.list[i];

    this->capacity = paramList.capacity;
    this->numberOfElements = paramList.numberOfElements;

    return *this;

}

template<class T>
T& List<T>::operator[](int index)
{

    if(index>=0 and index<=this->numberOfElements)
        return this->list[index];

}

template<class T>
bool List<T>::operator==(const List<T>& paramList)
{

    if(this->capacity != paramList.capacity)
        return false;

    if(this->numberOfElements!= paramList.numberOfElements)
        return false;

    for(int i = 0; i < this->numberOfElements; i++)
        if(this->list[i] != paramList.list[i])
            return false;

    return true;

}

template<class T>
void List<T>::pushBack(T elem)

{

    if(this->numberOfElements >= this->capacity)
    {
        this->capacity *= 2;
        T* aux = new T[capacity];

        for(int i = 0; i < this->numberOfElements; i++)
            aux[i] = this->list[i];

        delete[] this->list;
        this->list = aux;
    }

    this->list[this->numberOfElements] = elem;
    this->numberOfElements++;

}

template<class T>
int List<T>::size() const
{
    return this->numberOfElements;
}

template<class T>
int List<T>::getCapacity() const
{
    return this->capacity;
}

template<class T>
bool List<T>::empty()
{

    if(this->numberOfElements == 0)
        return true;
    else return false;

}

template<class T>
void List<T>::insert(int index, T elem)
{

    this->numberOfElements++;
    for(int i = this->numberOfElements; i > index; i--)
        this->list[i] = this->list[i - 1];
    this->list[index] = elem;

}

template<class T>
T List<T>::getElem(int index)
{

    return this->list[index];

}

template<class T>
void List<T>::deleteElem(int index)
{

    for(int i = index; i < this->numberOfElements - 1; i++)
        this->list[i] = this->list[i + 1];
    this->numberOfElements--;

}


#endif //SDTOYSOCIALNETWORK_LIST_H
