#include "SignalSolver.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal;

#pragma region Constructors
Solver::Solver(double timeStep)
      : _timeStep(timeStep)
{
  throw NotImplementedException();
}
#pragma endregion

#pragma region Modifiers
void Solver::initialize()
{
  throw NotImplementedException();
}

void Solver::connect(const Block& outputBlock, size_t outputPortIndex,
                     Block& inputBlock, size_t inputPortIndex)
{
  throw NotImplementedException();
}

void Solver::step()
{
  throw NotImplementedException();
}
#pragma endregion