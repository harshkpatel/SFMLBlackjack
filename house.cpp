#include "house.h"

//determines if house needs to hit
bool House::isHitting() const
{
    if(getTotal() <= 16)
        return true;
    else
        return false;
}

//shows off first card that was originally hidden
void House::flipFirstCard(){
    std::cout <<"House:\t" + toString() + "(";
    std::cout << getTotal();
    std::cout << ")" << std::endl;
}
