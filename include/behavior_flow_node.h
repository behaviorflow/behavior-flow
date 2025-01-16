// Copyright (c) 2024, Mitch Adams

#ifndef BEHAVIOR_FLOW__BEHAVIOR_FLOW_NODE_H_
#define BEHAVIOR_FLOW__BEHAVIOR_FLOW_NODE_H_

#include <string>

namespace behaviorflow {

class BehaviorFlowNode {
 public:
  BehaviorFlowNode() {}
  virtual ~BehaviorFlowNode() = default;

  void init(std::string node_instance_name, std::string node_type_name);

  std::string getInstanceName();

  std::string getTypeName();

  // virtual void parameters() = 0;
  // virtual void returnTypes() = 0;
  // virtual void run() = 0;

 private:
  bool initialized_ = false;
  std::string node_instance_name_;
  std::string node_type_name_;
  // std::string node_description_;
};

}  // end namespace behaviorflow

#endif  // BEHAVIOR_FLOW__BEHAVIOR_FLOW_NODE_H_