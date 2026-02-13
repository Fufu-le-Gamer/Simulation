#pragma once
#include <vector>
#include "Ia.h"
#include "Shop.h"

class RootNode;
class BaseNode;

class Blackboard {
public:

};


class BehaviorTree {
public:
	BehaviorTree();
	BehaviorTree(Blackboard* BB);
	virtual ~BehaviorTree();

	void BeginExecute();
	void Tick(float DeltaTime);

	virtual void BuildTree();
	void CleanTree();

	Blackboard* GetBlackBoard();
protected:
	Blackboard* InternBlackBoard;
	RootNode* Root;
	std::vector<BaseNode*> AllSubNodes;
};


class EnnemiBlackBoard : public Blackboard {
public:
	int PlayerX;
	int PlayerY;

	int MyPosX;
	int MyPosY;

	int MyDirX;
	int MyDirY;

	bool SeePlayer;

	int Point1X;
	int Point1Y;

	int Point2X;
	int Point2Y;

	Ia* IA;
	float timestop;
};


class EnnemyBehaviorTree : public BehaviorTree {
public:
	EnnemyBehaviorTree();
	EnnemyBehaviorTree(Blackboard* BB);
	virtual ~EnnemyBehaviorTree();

	virtual void BuildTree() override;
};



class ClientBehaviorTree : public BehaviorTree {
public:
	ClientBehaviorTree();
	ClientBehaviorTree(Blackboard* BB);
	virtual ~ClientBehaviorTree();

	virtual void BuildTree() override;
};