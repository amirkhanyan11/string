#include <iostream>
#include "string.h"


int main() {

    String test = "hello";
    String other = "world";

    test.print();

    test.swap(other);

    test.print();

    other.print();

    return 0;
}
