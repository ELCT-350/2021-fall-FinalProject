#pragma once
#include "Block.h"
#include "Vector.h"
#include "Matrix.h"
#include "MnaPort.h"
#include <memory>

namespace ELCT350
{
  namespace Mna
  {
    class Block : public virtual Common::Block
    {
    public:
      #pragma region Modifiers
      void computeThroughValues();

      virtual void mnaMinorStep(double timeStep, double time) {};
      virtual void mnaStep(double timeStep, double time) = 0;
      #pragma endregion

      #pragma region Observers
      size_t getNumberOfPorts() const;
      double getAcross(size_t index) const;
      double getThrough(size_t index) const;

      double getJacobian(size_t rowIndex, size_t columnIndex) const;
      double getIntercept(size_t index) const;

      Port& getMnaPort(size_t index) const;
      #pragma endregion
    protected:
      #pragma region Constructors
      Block(size_t numberOfPorts);
      #pragma endregion

      #pragma region Modifiers
      void setJacobian(size_t rowIndex, size_t columnIndex, double value);
      void setIntercept(size_t index, double value);
      void setReference(size_t portIndex, bool reference);
      #pragma endregion
    private:
      #pragma region Variables
      Math::Vector<double> _intercept;
      Math::Matrix<double> _jacobian;
      std::unique_ptr<Port[]> _ports;
      #pragma endregion
    };
  }
}