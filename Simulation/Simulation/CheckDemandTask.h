#pragma once
#include "TaskNode.h"

class Ia;

class CheckDemandTask : public TaskNode {
public:
	CheckDemandTask();
	CheckDemandTask(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~CheckDemandTask() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

public:
	Ia* Client;
};

