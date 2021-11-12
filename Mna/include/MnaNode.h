#pragma once
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class Port;
    class Node
    {
    public:
      Node(Port& port);

      size_t getIndex() const;
      double getAcross() const;
      bool isReference() const;

      void setIndex(size_t index);
      void setAcross(double value);


      void joinNode(std::shared<Node>& oldNode);
    private:
      size_t _index;
      std::set<Port*> _ports;
    };
  }
}