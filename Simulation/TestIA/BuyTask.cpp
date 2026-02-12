#include "BuyTask.h"
#include "BehaviorTree.h"
#include "FlowNode.h"

BuyTask::BuyTask():BuyTask(nullptr,nullptr)
{
}

BuyTask::BuyTask(BehaviorTree* Tree, FlowNode* NodeParent):TaskNode(Tree,NodeParent)
{
}

BuyTask::~BuyTask()
{
}

void BuyTask::BeginExecute()
{
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		ShopStock = _BlackBoard->IA->IAShop->stock;
		prixclient = _BlackBoard->IA->prix_demande;
		prixshop = _BlackBoard->IA->IAShop->prix;
	}
}

void BuyTask::Tick(float DeltaTime)
{
	EndExecute();
}

void BuyTask::EndExecute()
{
	if (ShopStock > 0 && prixclient >= prixshop) {
		ShopStock -= 1;
		Parent->OnChildEnd(ENodeState::Success);
	}
	else
	{
		Parent->OnChildEnd(ENodeState::Failure);
	}
}
