#pragma once
#include "TaskNode.h"

class WaitTask : public TaskNode {
public:
	WaitTask();
	WaitTask(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~WaitTask() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

public:
	float timetowait;
	float timeActual;
};
