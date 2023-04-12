

#ifndef SDTOYSOCIALNETWORK_ABC_H
#define SDTOYSOCIALNETWORK_ABC_H
#include "ABCNode.h"

template<class T>
/**
* Implementarea arborelui  cu elemente generice
* @tparam T: tipul elementelor care contine arborele
*/
class ABC{
protected:
    ABCNode<T>* root;

    /**
     * Creeaza un nou nod in care pune elementul dorit
     * @param ad: pointer catre nod
     * @param elem : elementul pe care il pune
     */
    void add(ABCNode<T>* ad, T elem);


    /**
     * Cauta ce element trebuie sa stearga si modifica arborele dupu stergerea acestuia
     * @param current_node : pointer catre nodul curent
     * @param parent_node : pointer catre tatal nodului curent
     */
    void recursive_remove(ABCNode<T>* current_node, ABCNode<T>* parent_node);


    /**
     * Obtine nodul parinte al nodului curent
     * @param node: pointer catre nodul curent
     * @return pointer catre nodul parinte
     */
    ABCNode<T>* get_predecesor_parent(ABCNode<T>* node);


    /**
     * Sterge arborele in metoda postorder, adica sterge root,left, right
     * @param current_node: pointer catre nodul curent
     */
    void delete_postorder_recursive( ABCNode<T>* current_node);


public:

    /**
     * Constructor implicit pentru clasa ABC
    */
    ABC();


    /**
    * Adaunga un element in arbore
    * @param elem : elementul pe care il adauga
    */
    void add(T elem);

    /**
     * Sterge un element din arbore
     * @param e: elementul pe care vrea sa il stearga
     * @return adevarat/fals
     */
    bool remove(T e);


    /**
     * Cauta elementul in arbore
     * @param elem: elementul pe care il cauta
     * @return adevarat sau fals
     */
    bool search(T elem) const;

    /**
     * Destructor pentru clasa ABC
     */
    ~ABC();


    /**
    * Operatorul ==, compară doi arbori
    * @tparam T: tipul arborelui
    * @param t: arborele de comparat
     * @return adevarat/fals
    */
    bool operator==(const ABC&);


    /**
     * Obtine un pointer catre inceputul arborelui
     * @return un pointer catre inceputul arborelui
     */
    ABCNode<T>* getRoot();

};

template<class T>
void ABC<T>::add(ABCNode<T>* ad, T elem){

    if(ad->info > elem){ // adaugam pe stanga
        if(ad->left != nullptr) {
            add(ad->left, elem);
        }else{
            ad->left = new ABCNode<T>(elem, nullptr, nullptr);
        }
    }else{  //adaugam in dreapta
        if(ad->right != nullptr) {
            add(ad->right, elem);
        }else{
            ad->right = new ABCNode<T>(elem, nullptr, nullptr);
        }
    }
}
template<class T>
ABC<T>::ABC(){

    this->root = nullptr;
}

template<class T>
ABCNode<T> *ABC<T>::getRoot() {
    return this->root;
}

template<class T>
void ABC<T>::add(T elem){
    if(this->root == nullptr) this->root = new ABCNode<T>(elem, nullptr, nullptr);
    else add(this->root, elem);
}


template<class T>
ABCNode<T>* ABC<T>::get_predecesor_parent(ABCNode<T>* node)
{
    ABCNode<T>* predecesor ;
    ABCNode<T>* predecesor_parent ;

    predecesor_parent = node;
    predecesor = node->left;

    while (predecesor->right != nullptr)
    {
        predecesor_parent = predecesor;
        predecesor = predecesor->right;
    }
    return predecesor_parent;
}

template<class T>
void ABC<T>::recursive_remove(ABCNode<T>* current_node, ABCNode<T>* parent_node)
{
    if (current_node->left == nullptr && current_node->right == nullptr) //daca nodul curent nu are copii
    {
        if (current_node == this->root)
        {
            delete this->root;
            this->root = nullptr;
        }
        else
        {
            if (parent_node->left == current_node)
            {
                delete parent_node->left;
                parent_node->left = nullptr;
            }
            else
            {
                delete parent_node->right;
                parent_node->right = nullptr;
            }
        }
    }
    else if (current_node->left == nullptr) // daca nodul curent are doar un copil in dreapta
    {
        if (current_node == this->root)
        {
            this->root = this->root->right;
        }
        else
        {
            current_node->info = current_node->right->info;
            current_node->left = current_node->right->left;
            current_node->right = current_node->right->right;
        }
    }
    else if (current_node->right == nullptr) // daca nodul curent are doar un copil in stanga
    {
        if (current_node == this->root)
        {
            this->root = this->root->left;
        }
        else
        {
            current_node->info = current_node->left->info;
            current_node->right = current_node->left->right;
            current_node->left = current_node->left->left;
        }
    }
    else if (current_node->left != nullptr && current_node->right != nullptr) //daca nodul are 2 copii
    {
        ABCNode<T>* predecesor_parent =  get_predecesor_parent(current_node);
        if(predecesor_parent== current_node)
        {
            current_node->info = predecesor_parent->left->info;
            recursive_remove(predecesor_parent->left, predecesor_parent);
        }
        else
        {
            current_node->info = predecesor_parent->right->info;
            recursive_remove(predecesor_parent->right, predecesor_parent);
        }
    }
}


template<class T>
bool ABC<T>::remove(T e) {

    ABCNode<T>* current_node = new ABCNode<T>(e, nullptr, nullptr);
    ABCNode<T>* parent_node = new ABCNode<T>(e, nullptr, nullptr);

    parent_node = nullptr;
    current_node = this->root;
    while (current_node != nullptr && current_node->info != e)
    {
        parent_node = current_node;

        if(current_node->info > e)
            current_node = current_node->left;
        else
            current_node = current_node->right;

    }
    if (current_node == nullptr)	//daca nu am gasit elementul
    {
        return false;
    }
    else if (current_node->info == e) // daca am gasit elementul
    {

        recursive_remove(current_node, parent_node);
       // this->number_elements--;
        return true;

    }
    return false;
}

template<class T>
bool ABC<T>::search(T elem) const {

    ABCNode<T>* current_node = new ABCNode<T>(elem, nullptr, nullptr);

    current_node = this->root;
    while (current_node != nullptr && current_node->info != elem)
    {
        if (current_node->info > elem)
            current_node = current_node->left;
        else
            current_node = current_node->right;
    }
    if (current_node == nullptr)	//Daca nu am gasit elementul
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<class T>
void ABC<T>::delete_postorder_recursive( ABCNode<T>* current_node)
{
    if (current_node != nullptr)
    {
        delete_postorder_recursive(current_node->left);
        delete_postorder_recursive(current_node->right);
        delete current_node;
    }
}

template<class T>
bool ABC<T>::operator==(const ABC<T> & t) {
    return((this->root == t.root));
}

template<class T>
ABC<T>::~ABC() {

    delete_postorder_recursive(this->root);
}

#endif //SDTOYSOCIALNETWORK_ABC_H
