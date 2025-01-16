#include "behavior_flow_node.h"

namespace behaviorflow {

void BehaviorFlowNode::init(std::string node_instance_name, std::string node_type_name) {
  node_instance_name_ = node_instance_name;
  node_type_name_ = node_type_name;
	initialized_ = true;
}

std::string BehaviorFlowNode::getInstanceName() {
  return node_instance_name_;
}

std::string BehaviorFlowNode::getTypeName() {
  return node_type_name_;
}


}  // namespace behaviorflow