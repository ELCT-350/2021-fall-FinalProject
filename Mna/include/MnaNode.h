#pragma once
#include <memory>
#include <set>

namespace ELCT350
{
  namespace Mna
  {
    class Port;
    class Node : private std::enable_shared_from_this<Node>
    {
    public:
      #pragma region Constructors
      Node(Port& port);
      #pragma endregion

      #pragma region Modifiers
      void setIndex(size_t index);
      void setAcross(double value);

      void joinNode(std::shared_ptr<Node>& oldNode);
      #pragma endregion

      #pragma region Observers
      size_t getIndex() const;
      double getAcross() const;
      bool isReference() const;
      #pragma endregion
    private:
      #pragma region Variables
      size_t _index;
      std::set<Port*> _ports;
      #pragma endregion
    };
  }
}