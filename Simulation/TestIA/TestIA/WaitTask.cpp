#include "WaitTask.h"
#include "BehaviorTree.h"
#include "FlowNode.h"

WaitTask::WaitTask()
	: WaitTask(nullptr, nullptr) {
}

WaitTask::WaitTask(BehaviorTree* Tree, FlowNode* NodeParent)
	: TaskNode(Tree, NodeParent) {
}

WaitTask::~WaitTask()
{
}

void WaitTask::BeginExecute()
{
	EnnemiBlackBoard* _BlackBoard = static_cast<EnnemiBlackBoard*>(GetBlackBoard());
	if (_BlackBoard != nullptr) {
		timetowait = _BlackBoard->timestop;
	}
}

void WaitTask::Tick(float DeltaTime)
{
	timeActual += DeltaTime;
	if (timeActual >= timetowait)
	{
		EndExecute();
	}
}

void WaitTask::EndExecute()
{
	Parent->OnChildEnd(ENodeState::Success);
}
