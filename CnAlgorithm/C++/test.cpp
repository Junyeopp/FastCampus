#include <iostream>
#include <string>

namespace A {
void function() { std::cout << "A Namespace" << std::endl; }
}  // namespace A

namespace B {
void function() { std::cout << "B Namespace" << std::endl; }
}  // namespace B

int main(void) {
    A::function();
    B::function();
    system("pause");
    return 0;
}