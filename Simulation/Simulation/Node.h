#pragma once
class Blackboard;
class FlowNode;
class BehaviorTree;

enum class ENodeState{
	Unknow = 0,
	Success = 1,
	Failure = 2,
};


class BaseNode{
public:
	BaseNode();
	BaseNode(BehaviorTree* Tree);
	virtual ~BaseNode();

	virtual void BeginExecute();
	virtual void Tick(float DeltaTime);
	virtual void EndExecute();


	Blackboard* GetBlackBoard();
	BehaviorTree* GetBehaviorTree();
protected:
	BehaviorTree* OwnerTree;
};


class Node : public BaseNode {
public:
	Node();
	Node(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~Node() override;


protected:
	FlowNode* Parent;
};


class RootNode : public BaseNode {
public:
	RootNode();
	RootNode(BehaviorTree* Tree, BaseNode* NodeChild);
	virtual ~RootNode() override;

	void BeginExecute() override;
	void Tick(float DeltaTime) override;

	BaseNode* Child;
};


