#include "FollowPlayerTask.h"

#include <valarray>

#include "BehaviorTree.h"
#include "FlowNode.h"


FollowPlayerTask::FollowPlayerTask()
	: FollowPlayerTask(nullptr, nullptr) {
}

FollowPlayerTask::FollowPlayerTask(BehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent) {
}

FollowPlayerTask::~FollowPlayerTask() {
}

void FollowPlayerTask::BeginExecute() {
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		IAToPlayerX = _BlackBoard->PlayerX - _BlackBoard->MyPosX;
		IAToPlayerY = _BlackBoard->PlayerY - _BlackBoard->MyPosY;
		
		IADirX = _BlackBoard->MyDirX;
		IADirY = _BlackBoard->MyDirY;


		vecteur_normaliser = std::sqrt(IAToPlayerX*IAToPlayerX+IAToPlayerY*IAToPlayerY);
	}
}