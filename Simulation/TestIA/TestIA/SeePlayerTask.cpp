#include "SeePlayerTask.h"

#include <valarray>

#include "BehaviorTree.h"
#include "FlowNode.h"

SeePlayerTask::SeePlayerTask()
	: SeePlayerTask(nullptr, nullptr) {
}

SeePlayerTask::SeePlayerTask(BehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent){
}

SeePlayerTask::~SeePlayerTask(){
}

void SeePlayerTask::BeginExecute() {
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
	}
}

void SeePlayerTask::Tick(float DeltaTime){
	TaskNode::Tick(DeltaTime);

	DotProductResult = (IAToPlayerX * IADirX + IAToPlayerY * IADirY) / (std::sqrt(IAToPlayerX * IAToPlayerX + IAToPlayerY * IAToPlayerY) + std::sqrt(IADirX * IADirX + IADirY * IADirY));

	EndExecute();
}

void SeePlayerTask::EndExecute(){
	if (DotProductResult > 0.8){
		Parent->OnChildEnd(ENodeState::Success);
	}
	else{
		Parent->OnChildEnd(ENodeState::Failure);
	}
}
