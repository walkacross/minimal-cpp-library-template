/*
 * In a C++ program, a symbol, for example a variable or function name, can be declared any number of times within its scope. However, it can only be defined once. This rule is the "One Definition Rule" (ODR). A declaration introduces (or reintroduces) a name into the program, along with enough information to later associate the name with a definition. A definition introduces a name and provides all the information needed to create it. If the name represents a variable, a definition explicitly creates storage and initializes it. A function definition consists of the signature plus the function body. A class definition consists of the class name followed by a block that lists all the class members. (The bodies of member functions may optionally be defined separately in another file.)

 * A translation unit refers to an implementation (.c/.cpp) file and all header (.h/.hpp) files it includes. If an object or function inside such a translation unit has internal linkage, then that specific symbol is only visible to the linker within that translation unit. If an object or function has external linkage, the linker can also see it when processing other translation units. The static keyword, when used in the global namespace, forces a symbol to have internal linkage. The extern keyword results in a symbol having external linkage.

 * The compiler defaults the linkage of symbols such that:

(1) Non-const global variables have external linkage by default
(2) Const global variables have internal linkage by default
(3) Functions have external linkage by default

 */

namespace libminimal { namespace global{
            extern int clock_rate;

}
}
