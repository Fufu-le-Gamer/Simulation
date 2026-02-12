#pragma once
#include "TaskNode.h"

class SeePlayerTask : public TaskNode {
public:
	SeePlayerTask();
	SeePlayerTask(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~SeePlayerTask() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

private:
	float IAToPlayerX;
	float IAToPlayerY;

	float IADirX;
	float IADirY;

	float DotProductResult;
};

