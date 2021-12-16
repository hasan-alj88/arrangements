//
// Created by hhj on 14/12/2021.
//

#ifndef ARRANGEMENTS_PERMUTATION_H
#define ARRANGEMENTS_PERMUTATION_H
#include "tools.h"
#include <algorithm>
#include <random>
#include <iostream>

namespace arrangement {
    class permutation {

    public:
        array2d cycles;
        size_t size{};
        explicit permutation(size_t);
        explicit permutation(array1d);
        explicit permutation(const ziptype&);

        [[nodiscard]] ziptype swap_list()const;
        void apply(array1d& arr)const;
        [[nodiscard]] bool is_idle()const;
        [[nodiscard]] bool is_derangement()const;


        [[nodiscard]] array1d arrangement()const;
        [[nodiscard]] permutation inv()const;
        permutation operator+(const permutation& other)const;
        permutation operator-(const permutation& other)const;
        static permutation random(size_t n);

        [[nodiscard]] permutation next()const;
        [[nodiscard]] permutation next_derangement()const;


    };
}

#endif //ARRANGEMENTS_PERMUTATION_H
