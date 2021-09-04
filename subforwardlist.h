//
// Created by Kolya on 04.09.2021.
//
#include "subforwardlist_node.h"

class Subforwardlist{
private:
    Subforwardlist_node** origin;

public:
    void init(){
        *origin = nullptr;
    }

    void push_back(int d){
        if (*origin == nullptr){
            Subforwardlist_node* node;
            *origin = node;
            (**origin).set_next(nullptr);
            (**origin).set_data(d);
        }else{
            Subforwardlist_node *current = *origin;
            while((*current).get_next() != nullptr){
                current = (*current).get_next();
            }
            Subforwardlist_node* node;
            (*current).set_next(node);
            current = (*current).get_next();
            (*current).set_next(nullptr);
            (*current).set_data(d);
        }
    }
//добавление элемента в конец недосписка


    int pop_back(subforwardlist **sfl){
        if (*sfl == NULL){
            cout << "No elements in the list" << endl;
            return -1;
        }
        if ((**sfl).next == NULL){
            int deleted = (**sfl).data;
            delete *sfl;
            *sfl = NULL;
            return deleted;
        }

        subforwardlist *precurrent;
        subforwardlist *current = *sfl;
        while((*current).next != NULL){
            precurrent = current;
            current = (*current).next;
        }
        int deleted = (*current).data;
        (*precurrent).next = NULL;
        delete current;
        return deleted;
    }
//удаление элемента с конца недосписка


    bool push_forward(subforwardlist **sfl, int d){
        subforwardlist *second = *sfl;
        *sfl = new subforwardlist;
        (**sfl).next = second;
        (**sfl).data = d;
        return true;
    }
//добавление элемента в начало недосписка


    int pop_forward(subforwardlist **sfl){
        if (*sfl == NULL){
            cout << "No elements in the list" << endl;
            return -1;
        }
        subforwardlist *first = *sfl;
        *sfl = (**sfl).next;
        int deleted = (*first).data;
        delete first;
        return deleted;
    }
//удаление элемента из начала недосписка


    unsigned int size(subforwardlist **sfl){
        if (*sfl == NULL){
            return 0;
        }
        int i = 1;
        subforwardlist *current = *sfl;
        while((*current).next != NULL){
            current = (*current).next;
            i++;
        }
        return i;
    }
//определить размер недосписка


    bool push_where(subforwardlist **sfl, unsigned int where, int d){
        if (where == 0){
            push_forward(sfl, d);
            return 1;
        }
        int i = 1;
        subforwardlist *current = *sfl;
        while(i < where){
            current = (*current).next;
            i++;
        }
        subforwardlist *right = (*current).next;
        (*current).next = new subforwardlist;
        (*((*current).next)).data = d;
        (*((*current).next)).next = right;
        return 1;
    }
//добавление элемента с поряд-
//ковым номером where


    bool erase_where (subforwardlist **sfl, unsigned int where){
        if (where == 0){
            pop_forward(sfl);
            return 1;
        }
        int i = 1;
        subforwardlist *current = *sfl;
        while(i < where){
            current = (*current).next;
            i++;
        }

        subforwardlist *to_delete = (*current).next;
        (*current).next = (*to_delete).next;
        delete to_delete;
        return 1;
    }
//удаление элемента с порядковым номером where

    int get_element (subforwardlist **sfl, unsigned int number){
        int i = 0;
        subforwardlist *current = *sfl;
        if (current == NULL){return -1;}
        while(i < number && current->next != NULL){
            current = current->next;
            i++;
        }
        if (current->next == NULL && i < number){return -1;}
        else{return current->data;}
    }


    void clear(subforwardlist **sfl){
        while(*sfl != NULL){
            pop_forward(sfl);
        }
    }

};