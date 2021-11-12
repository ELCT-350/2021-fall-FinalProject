#include "Exceptions/NotImplementedException.h"
#include "SignalBlock.h"

using namespace ELCT350::Common::Exceptions;
using namespace ELCT350::Signal;

Block::Block(size_t numberOfInputPorts, size_t numberOfOutputPorts)
{
  throw NotImplementedException();
}

Block::~Block()
{
  throw NotImplementedException();
}

void Block::setInputPortValue(size_t index, double value)
{
  throw NotImplementedException();
}

double Block::getOutputPortValue(size_t index) const
{
  throw NotImplementedException();
}

void Block::setOutputPortValue(size_t index, double value)
{
  throw NotImplementedException();
}

double Block::getInputPortValue(size_t index) const
{
  throw NotImplementedException();
}