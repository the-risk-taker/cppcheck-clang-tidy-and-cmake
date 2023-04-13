#include "libmath.hpp"
#include "libthirdparty.hpp"

void use_third_party(third_party::fancy_struct_interface& object)
{
    object.do_something();
}

int main()
{
    third_party::fancy_struct_impl object;
    use_third_party(object);

    return math::add(1, 2);
}
