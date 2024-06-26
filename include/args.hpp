/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#pragma once

#include <array>
#include <vector>
#include <type_traits>

#include "split.hpp"


namespace utilities
{
    template <typename T, size_t N>
    bool parse_string(const std::string& argument_string, std::array<T, N>& arguments, const std::string& delimiter = ",")
    {
        std::vector<std::string> result = split_string(argument_string, delimiter);

        if (N != result.size())
        {
            return false;
        }

        for (size_t i = 0; i < N; i++)
        {
            if (std::is_integral<T>::value)
            {
                arguments[i] = std::stoi(result[i]);
            }

            if (std::is_floating_point<T>::value)
            {
                arguments[i] = std::stof(result[i]);
            }
        }

        return true;
    }
}
