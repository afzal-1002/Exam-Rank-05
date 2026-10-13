#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP
#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : virtual public array_bag {
    public:
        searchable_array_bag();
        searchable_array_bag(const array_bag& a_bag);
        searchable_array_bag(const searchable_array_bag& copy);
        searchable_array_bag& operator=(const searchable_array_bag& other);
        ~searchable_array_bag();
}

#endif