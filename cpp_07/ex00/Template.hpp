#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

// swap, min, max

template <typename T> 
void swap(T &first, T &second) {
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
T max(T first, T second) {
    if (first > second)
        return first;
    else
        return second;
}

template <typename T>
T min(T first, T second) {
    if (first < second)
        return first;
    else
        return second;
}

#endif