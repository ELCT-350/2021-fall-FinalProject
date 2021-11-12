#include "Blocks/Resistor.h"
#include "MnaSolver.h"
#include <iostream>
#include <fstream>

using namespace ELCT350::Math;
using namespace ELCT350::Mna::Blocks;
using namespace ELCT350::Mna;
using namespace std;

enum ErrorCodes
{
  Ok = 0
};

int main(int argc, char* argv[])
{
  Solver solver(0.01, 1e-7);

  //Example, modify this to perform RC Series simulation
  //Don't forget to get parameter values from argv
  Resistor r1;
  Resistor r2;
  r1.setParameterValue(Resistor::Resistance, 1000);
  r2.setParameterValue(Resistor::Resistance, 1000);

  solver.connect(r1, r1.getMnaPort(Resistor::N),
                 r2, r2.getMnaPort(Resistor::P));

  solver.initialize();
  while(solver.getTime() <= 10.0)
  {
    solver.step();

    r1.getAcross(Resistor::P);
    r1.getThrough(Resistor::P);
  }

  return Ok;
}