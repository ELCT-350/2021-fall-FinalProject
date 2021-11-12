#pragma once
#include "MnaBlock.h"
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class Solver
    {
    public:
      #pragma region Constructors
      Solver(double timeStep, double errorTolerance);
      #pragma endregion

      #pragma region Modifiers
      //Initializes all the Mna blocks
      //(calls initialize() on them)
      //Optional: if using member variable node list
      //update node list here
      void initialize();
      //Connect block ports together
      //1. Add block to our block set
      //2. Take node from each port and merge
      void connect(Block& block1, Port& port1,
                   Block& block2, Port& port2);
      
      //Steps all the blocks
      //Copy block stamps into appropriate cells in system
      //Jacobian and Intercept
      //Solve for across values (at every node)
      //Copy solved across values into the ports
      //Ask blocks to solve for through values
      //---Blocks could be non-linear
      //Run through Newton-Raphson iterations until convergence
      //compute error: get updated stamps from the components
      //if not converged
      //Run the newton-raphson equation
      //copy across values to ports
      //tell blocks to update currents
      //repeat until converged
      //Updates time
      void step();
      #pragma endregion

      #pragma region Observers
      double getTimeStep() const;
      double getTime() const;
      #pragma endregion
    private:
      #pragma region Constants
      const double _timeStep;
      const double _errorTolerance;
      #pragma endregion

      #pragma region Variables
      double _time;
      std::set<Block*> _blocks;

      //Optional:
      //Either have it as class member or
      //rebuild it when you circuit is solved
      //std::set<std::shared_ptr<Node>> _nodes;
      #pragma endregion
    };
  }
}