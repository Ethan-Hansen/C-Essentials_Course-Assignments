//
//  ECGraph.cpp
//
//
//  Created by Neil Malik on 2/10/2020.

#include "ECGraph.h"
#include <vector>
#include<iostream>

using namespace std;


//*****************************************************************
// graph node class

    ECGraphNode::ECGraphNode(int nid)
	{
		nodeId = nid;
	}
    ECGraphNode::~ECGraphNode()
	{
	}
	void ECGraphNode::SetEdge(const ECGraphNode *pNode)
	{
		edgeList.push_back(pNode);
	}
	
    int ECGraphNode::GetId() const
	{
		return nodeId;
	}
	
	vector<const ECGraphNode *> ECGraphNode::GetEdgeList() const
	{
		return edgeList;
	}

//*****************************************************************
// graph class
// assume the graph is directed

    ECGraph::ECGraph()
    {
	}
    ECGraph::~ECGraph()
    {
	}


    // basic graph editing functions
    void ECGraph::AddNode( ECGraphNode *pNode )
    {
		//Your code goes here
		//Remember that nodes are distinct. 
		//You cannot add a node with ID nid if a node with nid already exists in a graph
		bool check = false;
		for(int i = 0; i < nodeList.size(); ++i)
		{
			if((*nodeList[i]).GetId() == (*pNode).GetId())
			{
				check = true;
			}
		}
		if(check == false)
		{
			nodeList.push_back(pNode);
		}
		
	}

    void ECGraph::AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 )
    {
		//Your code goes here
		//Remember to account for adding an edge node which does not yet exist in the graph (should be supported)
		bool check = false;
		for(int i = 0; i < listofedges.size(); ++i)
		{
			if((*std::get<0>(listofedges[i])).GetId() == (*pNode1).GetId())
			{
				if((*std::get<1>(listofedges[i])).GetId() == (*pNode2).GetId())
				{
					check = true;
				}
			}
			if((*std::get<1>(listofedges[i])).GetId() == (*pNode1).GetId())
			{
				if((*std::get<0>(listofedges[i])).GetId() == (*pNode2).GetId())
				{
					check = true;
				}
			}	
		}
		if(check == false)
		{
			listofedges.push_back(std::make_tuple(pNode2, pNode1));
			AddNode(const_cast<ECGraphNode*>(pNode2));
			AddNode(pNode1);
		}
	}
	

    // basic graph access functions
    int ECGraph::GetNumofNodes() const
    {
		return nodeList.size();
	}
    int ECGraph::GetNumofEdges() const
    {
		return listofedges.size();
	}
	
	ECGraphNode* ECGraph::GetNodeById(const int nid) const
	{
		for(int i = 0; i < nodeList.size(); ++i)
		{
			if((*nodeList[i]).GetId() == nid)
			{
				return nodeList[i];
			}
		}
		return NULL;
	}
	
	vector<int> ECGraph::GetAllNodeIds() const
	{
		vector<int> temp;
		for(int i = 0; i < nodeList.size(); ++i)
		{
			temp.push_back((*nodeList[i]).GetId());
		}
		return temp;
	}




