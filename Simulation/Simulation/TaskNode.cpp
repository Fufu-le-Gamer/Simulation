#include "TaskNode.h"

TaskNode::TaskNode() : TaskNode(nullptr, nullptr) {
}

TaskNode::TaskNode(BehaviorTree* Tree, FlowNode* NodeParent) : Node(Tree, NodeParent) {
}

TaskNode::~TaskNode()
{
}
