#pragma once
#include "OutputPort.h"

namespace ELCT350
{
  namespace Signal
  {
    class InputPort : public Port
    {
    public:
      InputPort();

      //set connected port address
      void connect(OutputPort& port);

      //copy value from connected port
      void copyValue();

      //is connected port ready
      bool areDependenciesSatisfied() const;
    private:
      OutputPort* _connectedPort;
    };
  }
}