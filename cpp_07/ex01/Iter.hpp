#ifndef ITER_HPP
# define ITER_HPP

#include <stdlib.h>

template <typename T, typename F>
void iter(T *array, const int length, F func) {
    for (int i = 0; i < length; i++) 
        func(array[i]);
}

#endif
