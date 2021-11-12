#include "Blocks/RCseries.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal::Blocks;

RCseries::RCseries()
        : Common::Block(3),
          Block(1, 2)
{
  throw NotImplementedException();
}

void RCseries::initialize()
{
  throw NotImplementedException();
}

void RCseries::signalStep(double timeStep, double time)
{
  throw NotImplementedException();
}