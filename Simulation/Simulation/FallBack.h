#pragma once

#include "FlowNode.h"

class FallBack : public FlowNode {
public:
	FallBack();
	FallBack(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds);
	virtual ~FallBack() override;

	virtual void OnChildEnd(ENodeState ChildResult) override;
};

