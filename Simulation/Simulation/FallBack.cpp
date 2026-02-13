#include "FallBack.h"

FallBack::FallBack() : FallBack(nullptr, nullptr, {}) {
}

FallBack::FallBack(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds) : FlowNode(Tree, NodeParent, NodeChilds) {
}

FallBack::~FallBack() {
}

void FallBack::OnChildEnd(ENodeState ChildResult) {
	if (ChildResult == ENodeState::Failure) {
		FlowNode::OnChildEnd(ChildResult);
		if (CurrentExecuteChild != nullptr) {
			CurrentExecuteChild->BeginExecute();
		}
		else {
			if (Parent != nullptr) {
				Parent->OnChildEnd(ENodeState::Success);
			}
			else {
				CurrentExecuteChild = *Childs.begin();
				CurrentExecuteChild->BeginExecute();
			}
		}
	}
	else {
		if (Parent != nullptr) {
			Parent->OnChildEnd(ENodeState::Failure);
		}
		else {
			CurrentExecuteChild = *Childs.begin();
			CurrentExecuteChild->BeginExecute();
		}
	}
}
