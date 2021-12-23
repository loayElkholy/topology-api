#pragma once
#include <iostream>
#include "Topology.hpp"
#include "Component.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;

class TopologyList
{
    string FileName;
    int TopologyListId;
    vector<Topology> topology_list;

public:
    bool readJSON(string FileName); 
    bool writeJSON(string TopologyID);
    vector<Topology> queryTopologies();
    bool deleteTopology(string TopologyID);
    vector<Component> queryDevices(string TopologyID);
    Component queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID);
};