#include <iostream>
#include "string.h"
// using namespace std;


int main() {

    String test = "hello";

    String a = to_string(123);

    a.print();

    std::cout << a.length() << std::endl;

    return 0;
    
}
