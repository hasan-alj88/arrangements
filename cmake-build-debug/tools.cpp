//
// Created by hhj on 14/12/2021.
//

#include "tools.h"

namespace tools {
    std::string to_sting(array1d arr) {
        std::string out("[");
        for (size_t i = 0; i < arr.size(); i++)
            out += std::to_string(arr[i]) + ", ";
        out += "]";
        return out;
    }

    std::string to_sting(const array2d& arr2d) {
        std::string out("{");
        for (const auto& arr: arr2d)
            out += tools::to_sting(arr);
        out += "}";
        return out;
    }

    std::string to_sting(const ziptype& pairs) {
        std::string out("{");
        for (auto pair: pairs) {
            out += "[";
            out += std::to_string(pair.first) + ",";
            out += std::to_string(pair.second) + "]";
        }
        out += "}";
        return out;
    }

    ziptype zip(array1d arr1, array1d arr2) {
        ziptype zip_pair;
        size_t n = std::min(arr1.size(), arr2.size());
        for (size_t i = 0; i < n; i++) {
            zip_pair.push_back(std::make_pair(arr1[i], arr2[i]));
        }
        return zip_pair;
    }

    array1d range(size_t end, size_t start, size_t step) {
        array1d ret;
        for (size_t i = start; i < end; i += step)
            ret.push_back(i);
        return ret;
    }

    ziptype enumerate(const array1d& arr) {
        return tools::zip(tools::range(arr.size()), arr);
    }

    ziptype consecutive(const array1d& arr) {
        ziptype consecutive_pair;
        for (size_t i = 0; i < arr.size() - 1; i++)
            consecutive_pair.push_back(std::make_pair(arr[i], arr[i + 1]));
        return consecutive_pair;
    }

    size_t get_index(array1d arr, size_t val) {
        auto itr = std::find(arr.begin(), arr.end(), val);
        return std::distance(arr.begin(), itr);
    }

    size_t get_index(std::vector<bool> arr, bool val) {
        auto itr = std::find(arr.begin(), arr.end(), val);
        return std::distance(arr.begin(), itr);
    }

    array1d flatten(const ziptype& arr2d) {
        array1d arr1d;
        for (auto p: arr2d) {
            arr1d.push_back(p.first);
            arr1d.push_back(p.second);
        }
        return arr1d;
    }

    array1d flatten(array2d arr2d) {
        array1d arr1d;
        for (auto p: arr2d) {
            arr1d.insert(arr1d.end(), p.begin(), p.end());
        }
        return arr1d;
    }

    bool is_derangement(const array1d& arr)
    {
        ziptype enm = enumerate(arr);
        bool derangement = std::all_of(
                enm.begin(),
                enm.end(),
                tools::non_equal_pair
        );
        bool idle = std::all_of(
                enm.begin(),
                enm.end(),
                tools::equal_pair
        );
        return derangement or idle;
    }
    bool is_idle(const array1d& arr)
    {
        ziptype enm = enumerate(arr);
        return std::all_of(
                enm.begin(),
                enm.end(),
                tools::equal_pair
        );

    }

    bool equal_pair(const std::pair<size_t, size_t> &pair) {
        return pair.first == pair.second;
    }

    bool non_equal_pair(const std::pair<size_t, size_t> &pair) {
        return pair.first != pair.second;
    }

    size_t max(const ziptype& ziparr)
    {
        array1d flat = flatten(ziparr);
        return *std::max_element(flat.begin(), flat.end());
    }

    array1d apply_swaps(const array1d& arr,const ziptype& swaps)
    {
        array1d array1D = arr;
        size_t max_swap = max(swaps)+1;
        if(max_swap > array1D.size())
        {
            array1d appending_array = range(max_swap,array1D.size());
            array1D.insert(
                    array1D.end(),
                    appending_array.begin(),
                    appending_array.end());
        }
        for (auto swap: swaps) {
            auto itr1 = array1D.begin() + swap.first;
            auto itr2 = array1D.begin() + swap.second;
            std::iter_swap(itr1, itr2);
        }
        return array1D;
    }
}