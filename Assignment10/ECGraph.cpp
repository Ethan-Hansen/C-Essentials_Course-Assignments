
//  ECGraph.cpp
//
//
//  Created by Neil Malik on 2/10/2020.

#include "ECGraph.h"
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

//*****************************************************************
// graph node class

    ECGraphNode::ECGraphNode(int nid)
	{
		nodeId = nid;
		locked = false;
	}
	ECGraphNode :: ECGraphNode(const ECGraphNode &rhs)
	{
		nodeId = rhs.GetId();
		locked = rhs.IsLocked();

		for(int i = 0; i < rhs.edgeList.size(); i++)
		{
			ECGraphNode* temp = new ECGraphNode((*rhs.edgeList[i]).GetId());
			edgeList.push_back(temp);
		}
	}
	ECGraphNode& ECGraphNode :: operator=(const ECGraphNode &rhs)
	{
		nodeId = rhs.GetId();
		locked = rhs.IsLocked();

		for(int i = 0; i < rhs.edgeList.size(); i++)
		{
			ECGraphNode* temp = new ECGraphNode((*rhs.edgeList[i]).GetId());
			edgeList.push_back(temp);
		}

		return *this;
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

	bool ECGraphNode :: operator>(ECGraphNode const &temp) const
	{
		if(nodeId > temp.GetId())
		{
			return true;
		}
		return false;
	}

//*****************************************************************
// graph class
// assume the graph is directed

    ECGraph::ECGraph()
    {
	}
	ECGraph :: ECGraph(const ECGraph &rhs)
	{
		set<ECGraphNode*> listtocopy = rhs.nodeList;
		std::set<ECGraphNode*>::iterator iter = listtocopy.begin();
		for(int i = 0; i < listtocopy.size(); ++i)
		{
			ECGraphNode* temp = new ECGraphNode((**iter).GetId());
			(*this).AddNode(temp);

			vector<const ECGraphNode*> edges = (**iter).GetEdgeList();
			for(auto k : edges)
			{
				auto check = (*this).GetNodeById((*k).GetId());
				if(check == (*nodeList.end()))
				{
					(*this).AddEdge(temp, k);
				}
				else
				{
					(*this).AddEdge(temp, check);
				}
				
			}

			iter++;
		}
	}
	ECGraph& ECGraph :: operator=(const ECGraph &rhs)
	{
		set<ECGraphNode*> listtocopy = rhs.nodeList;
		std::set<ECGraphNode*>::iterator iter = listtocopy.begin();
		for(int i = 0; i < listtocopy.size(); ++i)
		{
			ECGraphNode* temp = new ECGraphNode((**iter).GetId());
			(*this).AddNode(temp);

			vector<const ECGraphNode*> edges = (**iter).GetEdgeList();
			for(auto k : edges)
			{
				auto check = (*this).GetNodeById((*k).GetId());
				if(check == (*nodeList.end()))
				{
					(*this).AddEdge(temp, k);
				}
				else
				{
					(*this).AddEdge(temp, check);
				}
				
			}

			iter++;
		}
		return *this;
	}
    ECGraph::~ECGraph()
    {
		std::set<ECGraphNode*>::iterator iter = nodeList.begin();
		for (int i = 0; i < nodeList.size(); i++)
		{
			delete (*iter);
			iter++;
		}	
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
		//Your code goes here
		//Remember to account for adding an edge node which does not yet exist in the graph (should be supported)
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
	
	ECGraphNode* ECGraph::Unlink(ECGraphNode* pNode)
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
		return pNode;
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
	bool ECGraph :: operator==(const ECGraph &rhs)
	{
		std::vector<int> n1 = (*this).GetAllNodeIds();
		std::vector<int> n2 = rhs.GetAllNodeIds();
		if(n1.size() != n2.size())
		{
			return false;
		}
		for(int i = 0; i < n1.size(); i++)
		{
			if(find(n2.begin(), n2.end(), n1[i]) == n2.end())
			{
				return false;
			}
		}

		for(int i = 0; i < n2.size(); i++)
		{
			if(find(n1.begin(), n1.end(), n2[i]) == n1.end())
			{
				return false;
			}
		}

		std::set<ECGraphNode*>::iterator iter1 = nodeList.begin();
		std::set<ECGraphNode*>::iterator iter2 = rhs.nodeList.begin();
		while(iter1 != nodeList.end() && iter2 != rhs.nodeList.end())
		{
			std::vector<const ECGraphNode*> e1 = (**iter1).GetEdgeList();
			std::vector<const ECGraphNode*> e2 = (**iter2).GetEdgeList();
			std::vector<int> eID1;
			std::vector<int> eID2;
			for(int i = 0; i < e1.size(); i++)
			{
				eID1.push_back((*e1[i]).GetId());
			}
			for(int i = 0; i < e2.size(); i++)
			{
				eID2.push_back((*e2[i]).GetId());
			}

			for (int i = 0; i < eID1.size(); i++)
			{
				if(std::find(eID2.begin(), eID2.end(), eID1[i]) == eID2.end())
				{
					return false;
				}
			}
			for (int i = 0; i < eID2.size(); i++)
			{
				if(std::find(eID1.begin(), eID1.end(), eID2[i]) == eID1.end())
				{
					return false;
				}
			}
			iter1++;
			iter2++;
		}
		return true;
	}



