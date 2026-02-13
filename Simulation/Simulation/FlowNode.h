#pragma once
#include <vector>

#include "Node.h"

class FlowNode : public Node {
public:
	FlowNode();
	FlowNode(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds);
	virtual ~FlowNode() override;

	virtual void OnChildEnd(ENodeState ChildResult);

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;

	void AddChild(Node* Child);

protected:
	std::vector<Node*> Childs;
	Node* CurrentExecuteChild;
};

