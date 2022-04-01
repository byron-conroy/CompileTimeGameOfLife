#pragma once

#include "Constants.h"

#include <iostream>

namespace GameOfLife
{
    // Create a bool alias with the same number of characters to make it easier to define the initial state
    enum CellValue : bool
    {
        DEAD,
        LIVE
    };

    template<size_t Width, size_t Height>
    using CellGrid = std::array<std::array<CellValue, Width>, Height>;

    namespace CommonStateLogic
    {
        template<size_t Width, size_t Height>
        constexpr void PrintCellGrid(const size_t iteration, const CellGrid<Width, Height>& cellGrid)
        {
            std::cout << "Iteration " << iteration <<  ":\n";
            for(const auto& row: cellGrid)
            {
                for(const auto& cell : row)
                {
                    std::cout << (cell ? 'O' : ' ') << ' ';
                }

                std::cout << '\n';
            }
        }

        template<size_t Max>
        constexpr bool OutsideRange(int64_t value)
        {
            return value < 0 || value >= Max;
        }

        template<size_t Width, size_t Height>
        constexpr size_t CountLivingNeighbours(int64_t X, int64_t Y, const CellGrid<Width, Height>& cellGrid)
        {
            size_t livingNeighbours = 0;

            for(auto xOffset = -1; xOffset <= 1; ++xOffset)
            {
                int64_t neighbourX = X + xOffset;
                if(OutsideRange<Width>(neighbourX))
                {
                    continue;
                }

                for(auto yOffset = -1; yOffset <= 1; ++yOffset)
                {
                    int64_t neighbourY = Y + yOffset;
                    if(OutsideRange<Height>(neighbourY))
                    {
                        continue;
                    }

                    if(neighbourX == X && neighbourY == Y)
                    {
                        continue;
                    }

                    if(cellGrid[neighbourX][neighbourY])
                    {
                        ++livingNeighbours;
                    }
                }
            }
            return livingNeighbours;
        }

        template<size_t Width, size_t Height>
        constexpr CellGrid<Width, Height> GetNext(const CellGrid<Width, Height>& currentState)
        {
            // Take a copy of the previous state as a base
            CellGrid<Width, Height> nextState = currentState;

            // Iterate through each cell
            for(int64_t X = 0; X < Width; ++X)
            {
                for(int64_t Y = 0; Y < Height; ++Y)
                {
                    auto cell = currentState[X][Y];

                    // Count how many living neighbours the cell has
                    auto livingNeighbours = CountLivingNeighbours(X, Y, currentState);

                    switch (cell)
                    {
                        case LIVE:
                            if(
                                livingNeighbours < 2    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
                                ||
                                livingNeighbours > 3    // Any live cell with more than three live neighbours dies, as if by overpopulation.
                                )
                            {
                                nextState[X][Y] = DEAD;
                            }
                            break;
                        case DEAD:
                            // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
                            if(livingNeighbours == 3)
                            {
                                nextState[X][Y] = LIVE;
                            }
                            break;
                    }
                }
            }

            return nextState;
        }
    }
}
