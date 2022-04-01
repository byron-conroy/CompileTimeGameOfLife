#pragma once

#include "State.h"

#include <iostream>

namespace GameOfLife
{
    template<size_t Width, size_t Height>
    constexpr void Print(const CellGrid<Width, Height>& cellGrid)
    {
        std::cout << "Iteration:" << '\n';
        for(const auto& row: cellGrid)
        {
            for(const auto& cell : row)
            {
                std::cout << (cell ? 'O' : ' ') << ' ';
            }

            std::cout << '\n';
        }
    }
}

