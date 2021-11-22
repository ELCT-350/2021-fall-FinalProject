#include "Blocks/Constant.h"
#include "Blocks/RCseries.h"
#include "Blocks/Resistor.h"
#include "MnaSolver.h"
#include "SignalSolver.h"
#include <iostream>
#include <fstream>

using namespace ELCT350::Math;
using namespace ELCT350::Mna::Blocks;
using namespace ELCT350::Signal::Blocks;
using namespace std;

using MnaSolver = ELCT350::Mna::Solver;
using SignalSolver = ELCT350::Signal::Solver;

enum ErrorCodes
{
  Ok = 0
};

int main(int argc, char* argv[])
{
  MnaSolver mnaSolver(0.01, 1e-7);
  SignalSolver signalSolver(0.01);

  Constant c1;
  c1.setParameterValue(Constant::ConstantValue, 10.0);

  RCseries rc1;
  rc1.setParameterValue(RCseries::Capacitance, 0.001);
  rc1.setParameterValue(RCseries::Resistance, 1000);
  rc1.setParameterValue(RCseries::IntegrationType, RCseries::ForwardEuler);

  signalSolver.connect(c1, Constant::Output,
                       rc1, RCseries::VoltageSource);

  //Example, modify this to perform RC Series simulation
  //Don't forget to get parameter values from argv
  Resistor r1;
  Resistor r2;
  r1.setParameterValue(Resistor::Resistance, 1000);
  r2.setParameterValue(Resistor::Resistance, 1000);

  mnaSolver.connect(r1, r1.getMnaPort(Resistor::N),
                    r2, r2.getMnaPort(Resistor::P));
 
  mnaSolver.initialize();
  signalSolver.initialize();
  while(mnaSolver.getTime() <= 10.0)
  {
    mnaSolver.step();
    signalSolver.step();

    r1.getAcross(Resistor::P);
    r1.getThrough(Resistor::P);
    rc1.getOutputPortValue(RCseries::CapacitorVoltage);
  }

  return Ok;
}