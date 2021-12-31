#include "TopologyList.hpp"

using TL = TopologyList;
namespace pt = boost::property_tree;

bool TL::readJSON(string FileName)
{
    pt::ptree topology_list;
    pt::read_json(FileName, topology_list);
    Topology topology(topology_list.get<string>("id"));
    for (auto cm : topology_list.get_child("components"))
    {
        Component component(cm.second.get<string>("id"), cm.second.get<string>("type"));
        for (auto nl : cm.second.get_child("netlist"))
        {
            component.netlist[nl.first] = nl.second.data();
        }
        for (auto pro : cm.second)
        {
            if (pro.first != "id" && pro.first != "type" && pro.first != "netlist")
            {
                Properties p;
                p.name = pro.first;
                p.default_value = pro.second.get<float>("default");
                p.min = pro.second.get<float>("min");
                p.max = pro.second.get<float>("max");
                component.add_property(p);
            }
        }
        topology.addComponent(component);
    }
    this->topology_list.push_back(topology);

    return true;
}

vector<Topology> TL::queryTopologies()
{
    return topology_list;
}

bool TL::deleteTopology(string TopologyID)
{
    for (int i = 0; i < topology_list.size(); i++)
    {
        if (topology_list[i].TopologyId == TopologyID)
        {
            topology_list.erase(topology_list.begin() + i);
        }
    }
    return true;
}

vector<Component> TL::queryDevices(string TopologyID)
{
    for (int i = 0; i < topology_list.size(); i++)
    {
        if (topology_list[i].TopologyId == TopologyID)
        {
            return topology_list[i].component_list;
        }
    }
    return vector<Component>();
}

Component TL::queryDevicesWithNetlistNode(string TopologyID, string NetlistNodeID)
{
    vector<Component> comp = queryDevices(TopologyID);
    for (int i = 0; i < comp.size(); i++)
    {
        if (comp[i].ComponentId == NetlistNodeID)
        {
            return comp[i];
        }
    }
}

bool TL::writeJSON(string TopologyID)
{
    for (int i = 0; i < topology_list.size(); i++)
    {
        if (topology_list[i].TopologyId == TopologyID)
        {
            pt::ptree topology;
            topology.put("id", TopologyID);
            pt::ptree comp_list;
            for (auto c : topology_list[i].component_list)
            {
                pt::ptree comp;
                comp.put("type", c.type);
                comp.put("id", c.ComponentId);

                pt::ptree pro;
                pro.add<float>("default", c.properties.default_value);
                pro.add<float>("min", c.properties.min);
                pro.add<float>("max", c.properties.max);
                comp.add_child(c.properties.name.c_str(),pro);

                pt::ptree netlist;
                for(auto it = c.netlist.begin(); it != c.netlist.end(); it++)
                {
                    netlist.put(it->first,it->second);
                }
                comp.add_child("netlist",netlist);

                comp_list.push_back(make_pair("", comp));
            }
            topology.push_back(make_pair("components", comp_list));
            pt::write_json(TopologyID + ".json", topology);
        }
    }
    return true;
}

