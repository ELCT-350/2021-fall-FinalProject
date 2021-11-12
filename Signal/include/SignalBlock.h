#pragma once
#include "Block.h"
#include "InputPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class Block : public virtual Common::Block
    {
    public:
      virtual ~Block();

      double getOutputPortValue(size_t index) const;

      virtual void signalStep(double timeStep, double time) = 0;
    protected:
      Block(size_t numberOfInputPorts, size_t numberOfOutputPorts);

      void setOutputPortValue(size_t index, double value);
      double getInputPortValue(size_t index) const;
    private:
      size_t _numberOfInputPorts;
      size_t _numberOfOutputPorts;

      InputPort* _inputPorts;
      OutputPort* _outputPorts;
    };
  }
}