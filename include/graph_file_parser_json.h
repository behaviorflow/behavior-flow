#include "graph_file_parser_interface.h"
#include <memory>

namespace behaviorflow
{
  class GraphFileParserJson : public GraphFileParserInterface
  {
  public:
    GraphFileParserJson() = default;
    std::unique_ptr<BehaviorFlowGraph> parseGraphString(std::string graph) override;
  };
} // end namespace behaviorflow