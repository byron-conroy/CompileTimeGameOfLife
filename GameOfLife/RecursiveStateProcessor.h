#pragma once

#include "State.h"

namespace GameOfLife
{
    template<size_t Iterations>
    struct RecursiveStateProcessor
    {
        template<size_t Width, size_t Height>
        constexpr auto Process(CellGrid<Width, Height> initialState) const
        {
            constexpr RecursiveStateProcessor<Iterations - 1> stateProcessor;
            auto previousState = stateProcessor.Process(initialState);
            auto currentState = State::GetNext(previousState);
            return currentState;
        }
    };

    template<>
    struct RecursiveStateProcessor<0>
    {
        template<size_t Width, size_t Height>
        constexpr auto Process(CellGrid<Width, Height> initialState) const
        {
            return initialState;
        }
    };
}
