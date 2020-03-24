#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>


union FlexType {
    int intValue;
    double doubleValue;
    float floatValue;
    char charValue;
    char active;
    void setActive(const char& type) {
        active = type;
    }
    template <typename T>
    void set(const T& val) {
        std::cerr << "val is of type " << typeid(val).name() << std::endl;
        if (typeid(val).name() == typeid(0).name()) {
            setActive('i');
            intValue = val;
        } else if (typeid(val).name() == typeid(0.0).name()) {
            setActive('d');
            doubleValue = val;
        } else if (typeid(val).name() == typeid(0.0f).name()) {
            setActive('f');
            floatValue = val;
        } else if (typeid(val).name() == typeid('0').name()) {
            setActive('c');
            charValue = val;
        }
    }
};

int main() {
    // ProgramContext context;
    // VariableContext var;
    // std::string id = "test";
    // context.variableBindings[id].back()
    FlexType x;
    x.set(1.1948357298475928437f);
    std::cerr << x.floatValue << std::endl;
    return 0;
}