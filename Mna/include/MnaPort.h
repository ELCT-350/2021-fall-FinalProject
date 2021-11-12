#pragma once
#include <memory>

namespace ELCT350
{
  namespace Mna
  {
    class Node;
    class Port
    {
    public:
      #pragma region Constructor
      Port();
      #pragma endregion

      #pragma region Modifiers
      void setIndex(size_t index);
      void setAcross(double value);
      void setThrough(double value);
      void setReference(bool reference);
      void setNode(std::shared_ptr<Node>& node);

      std::shared_ptr<Node>& getNode();
      #pragma endregion

      #pragma region Observers
      size_t getIndex() const;
      double getAcross() const;
      double getThrough() const;
      bool isReference() const;
      #pragma endregion
    private:
      #pragma region Variables
      size_t _index;
      double _across;
      double _through;
      bool _reference;
      std::shared_ptr<Node> _node;
      #pragma endregion
    };
  }
}