#include <iostream>
#include "subvector.h"
#include "subforwardlist.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Subvector s;
    s.init();
    s.push_back(1);
    s.push_back(2);
    s.print();
    s.pop_back();
    s.print();
    s.clear();
    s.print();

    std::cout << "subvec tested" <<std::endl;

    Subforwardlist l;
    l.init();


    return 0;
}
