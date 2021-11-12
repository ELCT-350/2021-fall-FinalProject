#include "MnaSolver.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Mna;

#pragma region Constructors
Solver::Solver(double timeStep, double errorTolerance)
      : _timeStep(timeStep), _errorTolerance(errorTolerance)
{
  throw NotImplementedException();
}
#pragma endregion

#pragma region Modifiers
void Solver::initialize()
{
  throw NotImplementedException();
}

void Solver::connect(Block& block1, Port& port1,
                     Block& block2, Port& port2)
{
  throw NotImplementedException();
}

void Solver::step()
{
  throw NotImplementedException();
}
#pragma endregion

#pragma region Observers
double Solver::getTimeStep() const
{
  throw NotImplementedException();
}

double Solver::getTime() const
{
  throw NotImplementedException();
}
#pragma endregion