#pragma once

#include <array>
#include <string>

#include "CommonStateLogic.h"

namespace GameOfLife
{
    template<size_t Width, size_t Height, size_t Iteration>
    struct State
    {
        constexpr State(const CellGrid<Width, Height>& initialState) :
            previousIteration{initialState},
            cellGrid{CommonStateLogic::GetNext(previousIteration.cellGrid)}
        {};


        State<Width, Height, Iteration - 1> previousIteration;
        CellGrid<Width, Height> cellGrid;

        constexpr void Print() const
        {
            previousIteration.Print();
            CommonStateLogic::PrintCellGrid(Iteration, cellGrid);
        };
    };

    template<size_t Width, size_t Height>
    struct State<Width, Height, 0> {

        constexpr State(const CellGrid<Width, Height>& initialState) :
            cellGrid{initialState}
        {};

        CellGrid<Width, Height> cellGrid;

        constexpr void Print() const
        {
            CommonStateLogic::PrintCellGrid(0, cellGrid);
        };
    };
}
