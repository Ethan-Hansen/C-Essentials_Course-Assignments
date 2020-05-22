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
		locked = false;
	}
    ECGraphNode::~ECGraphNode()
	{
	}
	void ECGraphNode::SetEdge(const ECGraphNode *pNode)
	{
		if(locked = true)
		{
			edgeList.push_back(pNode);
		}
	}
	
    int ECGraphNode::GetId() const
	{
		return nodeId;
	}
	
	vector<const ECGraphNode *> ECGraphNode::GetEdgeList() const
	{
		return edgeList;
	}

	bool ECGraphNode :: IsLocked() const
	{
		return locked;
	}

	void ECGraphNode :: ClearEdges()
	{
		edgeList.clear();
	}

	void ECGraphNode :: Lock(const bool &status)
	{
		locked = status;
	}

	bool ECGraphNode :: operator==(const ECGraphNode &n2) const
	{
		if(nodeId == n2.GetId())
		{
			return true;
		}
		return false;
	}

	bool ECGraphNode :: operator!=(const ECGraphNode &n2) const
	{
		if((*this) == n2)
		{
			return false;
		}
		return true;
	}

	bool ECGraphNode :: operator<(const ECGraphNode &n2) const
	{
		if(nodeId < n2.GetId())
		{
			return true;
		}
		return false;
	}

	void ECGraphNode :: DeleteEdge(const ECGraphNode *pNode)
	{
		std::vector <const ECGraphNode*>:: iterator check = find(edgeList.begin(), edgeList.end(), pNode);
		if(check != edgeList.end())
		{
			edgeList.erase(check);
		}
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
		if((*pNode).IsLocked() == false)
		{
			nodeList.insert(nodeList.begin(), pNode);
			(*pNode).Lock(true);
		}
	}

    void ECGraph::AddEdge( ECGraphNode *pNode1, const ECGraphNode *pNode2 )
    {
		AddNode(pNode1);
		AddNode(const_cast <ECGraphNode*> (pNode2));
		vector<const ECGraphNode*> e1 = (*pNode1).GetEdgeList();
		vector<const ECGraphNode*> e2 = (*pNode2).GetEdgeList();
		bool check = false;
		for(int i = 0; i < e1.size(); i++)
		{
			if(e1[i] == pNode2)
			{
				check = true;
			}
		}
		if(check == false)
		{
			(*pNode1).SetEdge(pNode2);
		}
	}
	

    // basic graph access functions
    int ECGraph::GetNumofNodes() const
    {
		return nodeList.size();
	}
    int ECGraph::GetNumofEdges() const
    {
		int total = 0;
		std::set<ECGraphNode*>::iterator iter = nodeList.begin();
		for(int i = 0; i < nodeList.size(); i++)
		{
			vector<const ECGraphNode*> list = (**iter).GetEdgeList();
			total = total + list.size();
			++iter;
		}
		return total;
	}
	
	ECGraphNode* ECGraph::GetNodeById(const int nid) const
	{
		std::set<ECGraphNode*>::iterator iter = nodeList.begin();
		for(int i = 0; i < nodeList.size(); i++)
		{
			if((**iter).GetId() == nid)
			{
				return (*iter);
			}
			++iter;
		}
		return (*iter);
	}
	
	vector<int> ECGraph::GetAllNodeIds() const
	{
		std::set<ECGraphNode*>::iterator iter = nodeList.begin();
		vector<int> ids;
		for(int i = 0; i < nodeList.size(); i++)
		{
			ids.push_back((**iter).GetId());
			++iter;
		}
		return ids;
	}
	
	void ECGraph::Unlink(ECGraphNode* pNode)
	{
		vector <const ECGraphNode*> uedges = (*pNode).GetEdgeList();
		std::set<ECGraphNode*>::iterator iter = nodeList.begin();
		while(iter != nodeList.end())
		{
			vector<const ECGraphNode*> edges = (**iter).GetEdgeList();
			std::vector <const ECGraphNode*>:: iterator check = find(edges.begin(), edges.end(), pNode);
			if(check != edges.end())
			{
				for(int i = 0; i < uedges.size(); ++i)
				{
					if((*uedges[i]) != (*pNode))
					{
						AddEdge((*iter), uedges[i]);
					}
				}
			}
			(**iter).DeleteEdge(pNode);
			++iter;
		}
		nodeList.erase(pNode);
		(*pNode).ClearEdges();
		(*pNode).Lock(false);
	}

	void ECGraph :: DFS(const ECGraphNode *pNodeStart, std::vector<int> &listNodesInDFS, std::vector<int> &loopTrack)
	{
			listNodesInDFS.push_back((*pNodeStart).GetId());
			loopTrack.push_back((*pNodeStart).GetId());
			for(int i = 0; i < loopTrack.size(); ++i)
			{
				cout << loopTrack[i] << ", ";
			}

			int temp = loopTrack[0];
			cout << endl;
			vector<const ECGraphNode*> edges = (*pNodeStart).GetEdgeList();
			for(int i = 0; i < edges.size(); ++i)
			{
				vector <int> branchtrack;
				branchtrack.push_back((*pNodeStart).GetId());
				branchtrack.push_back(temp);
				int mindex = -1;
				for(int k = 0; k < edges.size(); k++)
				{
					if(find(loopTrack.begin(), loopTrack.end(), (*edges[k]).GetId()) == loopTrack.end())
					{
						mindex = k;
					}	
				}
				if(mindex != -1)
				{
					for (int k = 0; k < edges.size(); k++)
					{
						if((*edges[k]).GetId() < (*edges[mindex]).GetId())
						{
							if(find(loopTrack.begin(), loopTrack.end(), (*edges[k]).GetId()) == loopTrack.end())
							{
								mindex = k;
							}
						}
					}
					if(find(loopTrack.begin(), loopTrack.end(), (*edges[mindex]).GetId()) == loopTrack.end())
					{
						DFS(edges[mindex], listNodesInDFS, branchtrack);
					}
					loopTrack.push_back((*edges[mindex]).GetId());
				}
			}
	}





