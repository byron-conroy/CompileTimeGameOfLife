#include "GameOfLife/Constants.h"
#include "GameOfLife/RecursiveStateProcessor.h"
#include "GameOfLife/Printer.h"

int main()
{
    using namespace GameOfLife;

    constexpr RecursiveStateProcessor<Constants::Iterations> stateProcessor;
    constexpr auto finalState = stateProcessor.Process(Constants::InitialGrid);
    Print(finalState);

    return 0;
}
