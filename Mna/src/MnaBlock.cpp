#include "MnaBlock.h"
#include "Exceptions/NotImplementedException.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Mna;
using namespace std;

Block::Block(size_t numberOfMnaPorts)
     : _intercept(numberOfMnaPorts),
       _jacobian(numberOfMnaPorts, numberOfMnaPorts),
       _ports(make_unique<Port[]>(numberOfMnaPorts))
{
}

#pragma region Modifiers
void Block::computeThroughValues()
{
  throw NotImplementedException();
}

void Block::setJacobian(size_t rowIndex, size_t columnIndex, double value)
{
  throw NotImplementedException();
}

void Block::setIntercept(size_t index, double value)
{
  throw NotImplementedException();
}

void Block::setReference(size_t portIndex, bool reference)
{
  throw NotImplementedException();
}
#pragma endregion

#pragma region Observers
double Block::getAcross(size_t index) const
{
  throw NotImplementedException();
}

double Block::getThrough(size_t index) const
{
  throw NotImplementedException();
}

double Block::getJacobian(size_t rowIndex, size_t columnIndex) const
{
  throw NotImplementedException();
}

double Block::getIntercept(size_t index) const
{
  throw NotImplementedException();
}

Port& Block::getMnaPort(size_t index) const
{
  throw NotImplementedException();
}
#pragma endregion