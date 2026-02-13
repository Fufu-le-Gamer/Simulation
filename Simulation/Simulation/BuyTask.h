#pragma once
#include "TaskNode.h"

class BuyTask :public TaskNode {
public:
	BuyTask();
	BuyTask(BehaviorTree* Tree, FlowNode* NodeParent);
	virtual ~BuyTask() override;

	virtual void BeginExecute() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndExecute() override;

public:
	int ShopStock;
	int prixclient;
	int prixshop;
};

