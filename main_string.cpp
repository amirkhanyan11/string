#include <iostream>
#include "string.h"
// using namespace std;


int main() {

    String str = "hello";

    char cp[10];

    size_t limit = str.copy(cp, 3, 0);

    cp[limit] = '\0';

    std::cout << cp << std::endl;

    return 0;
    
}
