//
// Created by hhj on 14/12/2021.
//

#include "permutation.h"



namespace arrangement {



    permutation::permutation(array1d arr) {
        this->size = arr.size();
        // Arrangement validity tests
        array1d idle_permutation = tools::range(this->size);
        try {
            if (not std::is_permutation(arr.begin(), arr.end(), idle_permutation.begin()))
                throw ("The array " + tools::to_sting(arr) + " is not a permutation.");
        }
        catch (std::string error)
        {
            std::cout << "\n====Error===\n" << error << std::endl;
        }
        //calculating cycles
        std::vector<bool> checked(this->size, false);
        size_t index1 = 0, index2;
        array1d cycle;
        this->cycles.clear();
        cycle.clear();
        while (not std::all_of(checked.begin(), checked.end(), [](bool x) { return x; })) {
            index2 = tools::get_index(arr, index1);
            if (index1 == index2) {
                checked[index1]=true;
                index1 = tools::get_index(checked, false);
            } else if (not checked[index2]) {
                cycle.push_back(index2);
                checked[index1] = true;
                index1 = index2;
            } else {
                cycle.insert(cycle.begin(), index2);
                checked[index1] = true;
                this->cycles.push_back(cycle);
                cycle.clear();
                index1 = tools::get_index(checked, false);
            }
        }
    }

    permutation::permutation(const ziptype& swaps) {
        size_t n = tools::max(swaps);
        array1d arrangement = tools::range(n);
        arrangement = tools::apply_swaps(arrangement,swaps);
        *this = permutation(arrangement);
    }

    ziptype arrangement::permutation::swap_list() const {
        ziptype swaps, swap;
        for (const auto& cycle: this->cycles) {
            swap = tools::consecutive(cycle);
            swaps.insert(swaps.end(), swap.begin(), swap.end());
        }
        std::reverse(swaps.begin(), swaps.end());
        return swaps;
    }

    void permutation::apply(array1d &arr) const {
        ziptype swaps = this->swap_list();
        arr = tools::apply_swaps(arr, swaps);
    }
    bool permutation::is_idle() const
    {
        return tools::is_idle(this->arrangement());
    }
    bool permutation::is_derangement() const
    {
        return tools::is_derangement(this->arrangement());
    }

    array1d permutation::arrangement() const {
        array1d arrange = tools::range(this->size);
        this->apply(arrange);
        return arrange;
    }

    permutation permutation::inv() const
    {
        array1d arrange = tools::range(this->size);
        ziptype swaps = this->swap_list();
        std::reverse(swaps.begin(),swaps.end());
        arrange = tools::apply_swaps(arrange, swaps);
        return permutation(arrange);
    }

    permutation permutation::operator+(const permutation &other) const {
        ziptype swaps = this->swap_list();
        ziptype others_swaps = other.swap_list();
        swaps.insert(swaps.end(),others_swaps.begin(),others_swaps.end());
        return permutation(swaps);
    }

    permutation permutation::operator-(const permutation &other) const {
        return *this+other.inv();
    }

    permutation permutation::random(size_t n) {
        array1d arr = tools::range(n);
        std::shuffle(arr.begin(),arr.end(), std::mt19937(std::random_device()()));
        return permutation(arr);
    }

    permutation permutation::next() const {
        array1d arr = this->arrangement();
        std::next_permutation(arr.begin(),arr.end());
        return permutation(arr);
    }

    permutation permutation::next_derangement() const {
        permutation the_next_permutation = this->next();
        while (not the_next_permutation.is_derangement())
        {
            the_next_permutation = the_next_permutation.next();
        }
        return the_next_permutation;
    }

    permutation::permutation(size_t n) {
        this->size = n;
        this->cycles.clear();
    }


}