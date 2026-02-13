#pragma once
#include <vector>

#include "FlowNode.h"

class Sequence : public FlowNode {
public:
	Sequence();
	Sequence(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds);
	virtual ~Sequence() override;

	virtual void OnChildEnd(ENodeState ChildResult) override;
};

