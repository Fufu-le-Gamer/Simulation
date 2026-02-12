#include "OpeningShopTask.h"
#include "BehaviorTree.h"

OpeningShopTask::OpeningShopTask()
	: OpeningShopTask(nullptr, nullptr) {
}

OpeningShopTask::OpeningShopTask(BehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent){
}

OpeningShopTask::~OpeningShopTask()
{
}

void OpeningShopTask::BeginExecute()
{
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		ShopOwner = _BlackBoard->IA;
	}
}

void OpeningShopTask::Tick(float DeltaTime)
{
	if (ShopOwner != nullptr){
		ShopOwner->IAShop->setstock();
		ShopOwner->IAShop->setPrix();
	}
}

void OpeningShopTask::EndExecute()
{
}
