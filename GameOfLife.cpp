#include "GameOfLife/Constants.h"
#include "GameOfLife/State.h"

int main()
{
    using namespace GameOfLife;

    constexpr State<Constants::Width, Constants::Height, Constants::Iterations> states{Constants::InitialGrid};

    states.Print();

    return 0;
}
