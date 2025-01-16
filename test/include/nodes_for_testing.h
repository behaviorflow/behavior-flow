#ifndef BEHAVIOR_FLOW__TEST__TEST_NODES_H_
#define BEHAVIOR_FLOW__TEST__TEST_NODES_H_

#include <iostream>

#include "behavior_flow_node.h"

namespace behaviorflow {

class TestNodeSimple : public BehaviorFlowNode {
 public:
  TestNodeSimple() = default;
};

class TestNodeWithConstructorParams : public BehaviorFlowNode {
 public:
  TestNodeWithConstructorParams() = delete;
  TestNodeWithConstructorParams(int param1, std::string param2)
      : param1_(param1), param2_(param2) {}

  int getParam1() { return param1_; }

  std::string getParam2() { return param2_; }

 private:
  int param1_;
  std::string param2_;
};

}  // end namespace behaviorflow

#endif  // BEHAVIOR_FLOW__BEHAVIOR_FLOW_NODE_H_
