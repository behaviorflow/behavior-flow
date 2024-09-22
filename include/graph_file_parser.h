// given a file, output a graph

#include "behavior_flow_graph.h"
#include <string>

namespace bf {

class GraphFileParser {
  public:
    GraphFileParser() = default;

    BehaviorFlowGraph parseGraphFile(std::string graph_file);
    virtual BehaviorFlowGraph parseGraphString(std::string graph) = 0;

  private:
    virtual std::string getGraphStringFromFile(std::string graph_file) = 0;  
};

}