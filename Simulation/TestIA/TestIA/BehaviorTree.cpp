#include "BehaviorTree.h"

#include "FallBack.h"
#include "Node.h"
#include "SeePlayerTask.h"
#include "Sequence.h"
#include "OpeningShopTask.h"
#include "WaitTask.h"
#include "CheckDemandTask.h"
#include "BuyTask.h"

BehaviorTree::BehaviorTree() : BehaviorTree(nullptr){

}

BehaviorTree::BehaviorTree(Blackboard* BB) : InternBlackBoard(BB){

}

BehaviorTree::~BehaviorTree(){

}

void BehaviorTree::BeginExecute(){
	Root->BeginExecute();
}

void BehaviorTree::Tick(float DeltaTime){
	Root->Tick(DeltaTime);
}

void BehaviorTree::BuildTree(){
	Root = new RootNode();
	AllSubNodes.push_back(Root);
}

void BehaviorTree::CleanTree(){
	for (auto Node : AllSubNodes){
		delete Node;
		Node = nullptr;
	}
	AllSubNodes.clear();
}

Blackboard* BehaviorTree::GetBlackBoard()
{
	return InternBlackBoard;
}

EnnemyBehaviorTree::EnnemyBehaviorTree() : EnnemyBehaviorTree(nullptr){
}

EnnemyBehaviorTree::EnnemyBehaviorTree(Blackboard* BB) : BehaviorTree(BB){
}

EnnemyBehaviorTree::~EnnemyBehaviorTree(){
}

void EnnemyBehaviorTree::BuildTree(){
	BehaviorTree::BuildTree();

	FallBack* FallBack1 = new FallBack(this, nullptr, {});
	Root->Child = FallBack1;

	Sequence* Sequence1 = new Sequence(this, FallBack1, {});
	FallBack1->AddChild(Sequence1);

	SeePlayerTask* Task1 = new SeePlayerTask(this, Sequence1);
	Sequence1->AddChild(Task1);

	


	AllSubNodes.push_back(Task1);
	AllSubNodes.push_back(Sequence1);
	AllSubNodes.push_back(FallBack1);
}

ClientBehaviorTree::ClientBehaviorTree() :ClientBehaviorTree(nullptr){
}

ClientBehaviorTree::ClientBehaviorTree(Blackboard* BB) : BehaviorTree(BB){
}

ClientBehaviorTree::~ClientBehaviorTree()
{
}

void ClientBehaviorTree::BuildTree()
{
	BehaviorTree::BuildTree();

	Sequence* Sequence1 = new Sequence(this, nullptr, {});
	Root->Child = Sequence1;

	OpeningShopTask* OpeningTask = new OpeningShopTask(this, Sequence1);
	Sequence1->AddChild(OpeningTask);

	WaitTask* WaitingTask = new WaitTask(this, Sequence1);
	Sequence1->AddChild(WaitingTask);

	CheckDemandTask* CheckTask = new CheckDemandTask(this, Sequence1);
	Sequence1->AddChild(CheckTask);

	BuyTask* BuyingTask = new BuyTask(this, Sequence1);
	Sequence1->AddChild(BuyingTask);

	AllSubNodes.push_back(OpeningTask);
	AllSubNodes.push_back(WaitingTask);
	AllSubNodes.push_back(CheckTask);
	AllSubNodes.push_back(BuyingTask);
	AllSubNodes.push_back(Sequence1);
}
