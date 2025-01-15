#include "node_factory.h"

namespace behaviorflow {

std::unique_ptr<BehaviorFlowNode> NodeFactory::createNodeInstance(std::string node_type_name,
                                                                  std::string node_instance_name) {
  auto it = node_type_map_.find(node_type_name);
  if (it != node_type_map_.end()) {
    return it->second(node_type_name, node_instance_name);
  }
  return nullptr;
}

}  // namespace behaviorflow