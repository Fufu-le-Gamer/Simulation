#include "FlowNode.h"

FlowNode::FlowNode() : FlowNode(nullptr, nullptr, {}){
}

FlowNode::FlowNode(BehaviorTree* Tree, FlowNode* NodeParent, const std::vector<Node*>& NodeChilds) : Node(Tree, NodeParent), Childs(NodeChilds){
}

FlowNode::~FlowNode(){
}

void FlowNode::OnChildEnd(ENodeState ChildResult){
	auto It = std::find(Childs.begin(), Childs.end(), CurrentExecuteChild);
	if (It != Childs.end()){
		int Index = std::distance(Childs.begin(), It) + 1;
		if (Index < Childs.size()){
			CurrentExecuteChild = Childs[Index];
		}
		else{
			CurrentExecuteChild = nullptr;
		}

	}
}

void FlowNode::BeginExecute(){
	CurrentExecuteChild = *Childs.begin();
	if (CurrentExecuteChild != nullptr){
		CurrentExecuteChild->BeginExecute();
	}
}

void FlowNode::Tick(float DeltaTime){
	CurrentExecuteChild->Tick(DeltaTime);
	Node::Tick(DeltaTime);
}

void FlowNode::AddChild(Node* Child){
	Childs.push_back(Child);
}
