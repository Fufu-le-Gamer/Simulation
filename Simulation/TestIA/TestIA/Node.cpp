#include "Node.h"

#include "BehaviorTree.h"

BaseNode::BaseNode() : BaseNode(nullptr){
}

BaseNode::BaseNode(BehaviorTree* Tree) : OwnerTree(Tree){
}

BaseNode::~BaseNode(){
}

void BaseNode::BeginExecute(){
}

void BaseNode::Tick(float DeltaTime){
}

void BaseNode::EndExecute(){
}

Blackboard* BaseNode::GetBlackBoard(){
	return GetBehaviorTree()->GetBlackBoard();
}

BehaviorTree* BaseNode::GetBehaviorTree(){
	return OwnerTree;
}

Node::Node() : Node(nullptr, nullptr){
}

Node::Node(BehaviorTree* Tree, FlowNode* NodeParent) : BaseNode(Tree), Parent(NodeParent) {
}

Node::~Node(){
}



RootNode::RootNode() : RootNode(nullptr, nullptr){
}

RootNode::RootNode(BehaviorTree* Tree, BaseNode* NodeChild) : BaseNode(Tree), Child(NodeChild){
}

RootNode::~RootNode()
{
}

void RootNode::BeginExecute(){
	Child->BeginExecute();
}

void RootNode::Tick(float DeltaTime){
	Child->Tick(DeltaTime);
}
