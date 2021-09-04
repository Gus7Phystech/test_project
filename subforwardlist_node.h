//
// Created by Kolya on 04.09.2021.
//

#include <iostream>

class Subforwardlist_node{
private:
    int data;
    Subforwardlist_node* next;

public:

    int get_data(){
        return this->data;
    }

    bool set_data(int d){
        this->data = d;
        return true;
    }

    Subforwardlist_node* get_next(){
        return this->next;
    }

    Subforwardlist_node* set_next(Subforwardlist_node* n){
        this->next = n;
    }
};
