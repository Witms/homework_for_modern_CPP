#include <concepts>
#include <string>
#include <iostream>


template <typename T> concept ComplexConcept = 
requires(const T v) { { v.hash() } ->std::convertible_to<long>; } && 
requires(const T v) { { v.toString() } -> std::same_as<std::string>; } &&
!std::has_virtual_destructor<T>::value;


struct CorStruct
{

    std::string _str{"String"};
    int _number{20};

    std::string toString() const { return _str;}
    int hash() const { return _number;}
};


void checkfunc(ComplexConcept auto &obj)
{
    std::cout << obj.toString() << std::endl;
    std::cout << obj.hash() << std::endl;
}



int main()
{
    CorStruct obj{};
    checkfunc(obj);

    return 0;
}