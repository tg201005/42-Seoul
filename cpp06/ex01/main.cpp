#include "Serializer.hpp"

int main(){

    Data data;
    uintptr_t raw;

    data.s1 = "Hello World!";
    
    std::cout << "origin data: " << &data << std::endl;

    raw = Serializer::serialize(&data);
    std::cout << "raw: " << raw << std::endl;
    std::cout << "deserialized data: " << Serializer::deserialize(raw) << std::endl;

    return 0;
}