#include "Blocks/Resistor.h"

using namespace ELCT350::Mna::Blocks;

Resistor::Resistor()
        : Common::Block(1),
          Block(2)
{
}

void Resistor::initialize()
{
}

void Resistor::mnaStep(double timeStep, double time)
{
  double conductance = 1.0 / getParameterValue(Resistance);

  setJacobian(P, P, conductance);
  setJacobian(P, N, -conductance);
  setJacobian(N, P, -conductance);
  setJacobian(N, N, conductance);
}