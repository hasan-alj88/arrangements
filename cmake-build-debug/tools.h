//
// Created by hhj on 14/12/2021.
//

#ifndef ARRANGEMENTS_TOOLS_H
#define ARRANGEMENTS_TOOLS_H
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using array1d = std::vector<size_t>;
using array2d = std::vector<std::vector<size_t>>;
using ziptype = std::vector<std::pair<size_t,size_t>>;

namespace tools{
    std::string to_sting(array1d arr);
    std::string to_sting(const array2d& arr);
    std::string to_sting(const ziptype& pairs);
    ziptype zip(array1d arr1,array1d arr2);
    array1d range(size_t end, size_t start=0,size_t step=1);
    ziptype enumerate(const array1d& arr);
    ziptype consecutive(const array1d& arr);
    size_t get_index(array1d arr, size_t val);
    size_t get_index(std::vector<bool> arr, bool val);
    array1d flatten(const ziptype& arr2d);
    array1d flatten(array2d arr2d);
    bool equal_pair(const std::pair<size_t,size_t>& pair);
    bool non_equal_pair(const std::pair<size_t,size_t>& pair);
    bool is_derangement(const array1d& arr);
    bool is_idle(const array1d& arr);
    size_t max(const ziptype& ziparr);
    array1d apply_swaps(const array1d&  arr, const ziptype& swaps);
}


#endif //ARRANGEMENTS_TOOLS_H
