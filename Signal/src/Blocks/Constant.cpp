#include "Blocks/Constant.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal::Blocks;

Constant::Constant()
        : Common::Block(1),
          Block(0,1)
{
  throw NotImplementedException();
}

void Constant::initialize()
{
  throw NotImplementedException();
}

void Constant::signalStep(double timeStep, double time)
{
  throw NotImplementedException();
}