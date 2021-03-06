//===----------------------------------------------------------------------===//
//
//                         PelotonDB
//
// nested_loop_join_node.h
//
// Identification: src/backend/planner/nested_loop_join_node.h
//
// Copyright (c) 2015, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "abstract_join_plan.h"
#include "backend/common/types.h"
#include "backend/expression/abstract_expression.h"
#include "backend/planner/project_info.h"

namespace peloton {
namespace planner {

class NestedLoopJoinPlan : public AbstractJoinPlan {
 public:
  NestedLoopJoinPlan(const NestedLoopJoinPlan &) = delete;
  NestedLoopJoinPlan &operator=(const NestedLoopJoinPlan &) = delete;
  NestedLoopJoinPlan(NestedLoopJoinPlan &&) = delete;
  NestedLoopJoinPlan &operator=(NestedLoopJoinPlan &&) = delete;

  NestedLoopJoinPlan(PelotonJoinType join_type,
                     const expression::AbstractExpression *predicate,
                     const ProjectInfo *proj_info,
                     const catalog::Schema *proj_schema)
      : AbstractJoinPlan(join_type, predicate, proj_info, proj_schema) {
    // Nothing to see here...
  }

  inline PlanNodeType GetPlanNodeType() const {
    return PLAN_NODE_TYPE_NESTLOOP;
  }

  inline std::string GetInfo() const { return "NestedLoopJoin"; }
};

}  // namespace planner
}  // namespace peloton
