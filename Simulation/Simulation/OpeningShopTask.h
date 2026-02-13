#pragma once
#include "TaskNode.h"

class Ia;

class OpeningShopTask : public TaskNode {
public:
	OpeningShopTask();
	OpeningShopTask(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~OpeningShopTask() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

public:

	Ia* ShopOwner;
};

