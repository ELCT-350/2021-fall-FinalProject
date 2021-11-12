#include "Blocks/Ground.h"

using namespace ELCT350::Mna::Blocks;

Ground::Ground()
        : Common::Block(0),
          Block(1)
{
  setReference(G, true);
}

void Ground::initialize()
{
}

void Ground::mnaStep(double timeStep, double time)
{
}