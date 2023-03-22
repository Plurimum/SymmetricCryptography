#ifndef LAB_7_RANDOM_H
#define LAB_7_RANDOM_H

#endif

#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <random>
#include "AES128.h"

class RandomState {

    std::string key_st;


public:
    explicit RandomState(int key) {
        key_st = std::to_string(key);
        for (int i = key_st.size(); i < 16; i++) {
            key_st.push_back('9');
        }
        assert(key_st.size() == 16);
    }

    //! random value in [0, upper-1]
    int randint(int upper, std::string name) {
        name = name.size() > 16 ? name.substr(0, 16): name; // only 16 len supported
        for (int i = name.size(); i < 16; i++) {
            name.push_back('9');
        }
        std::vector<std::byte> out_bytes = AES::encrypt(name, key_st);
        return _mod(out_bytes, upper);
    }

private:
    int _mod(std::vector<std::byte> &out_bytes, int upper) {
        int ans = 0;
        for (int i = 0; i < out_bytes.size(); i++) {
            ans = (ans << 4) + std::to_integer<int>(out_bytes[i]);
            if (ans > upper) {
                return ans % upper;
            }
        }
        return ans;
    }

};
