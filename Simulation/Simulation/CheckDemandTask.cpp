#include "CheckDemandTask.h"
#include "BehaviorTree.h"
#include "FlowNode.h"

CheckDemandTask::CheckDemandTask() : CheckDemandTask(nullptr,nullptr){
}

CheckDemandTask::CheckDemandTask(BehaviorTree* Tree, FlowNode* NodeParent) : TaskNode(Tree, NodeParent){

}

CheckDemandTask::~CheckDemandTask()
{
}

void CheckDemandTask::BeginExecute()
{
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		Client = _BlackBoard->IA;
	}
}

void CheckDemandTask::Tick(float DeltaTime)
{
	if (Client != nullptr) {
		Client->Setdemande();
		EndExecute();
	}
}

void CheckDemandTask::EndExecute()
{
	if (Client->IAShop->stock <= 0)
	{
		Parent->OnChildEnd(ENodeState::Failure);
	}
	else {
		Parent->OnChildEnd(ENodeState::Success);
	}
}
