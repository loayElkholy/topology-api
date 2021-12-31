#include "test.hpp"
#include <assert.h>

TopologyList tpl;

bool test::test_readJSON()
{
    tpl.readJSON("topology.json");
    tpl.readJSON("topology2.json");
    if (tpl.topology_list.size() != 2)return false;
    if (tpl.topology_list[0].get_id() !="top1")return false;
    if (tpl.topology_list[1].get_id() != "top2")return false;
    if (tpl.topology_list[0].get_component_list().size() != 2)return false;
    if (tpl.topology_list[1].get_component_list().size() != 4)return false;
    cout << "readJSON passed all the tests successfully....\n";

    return true;
}
bool test::test_writeJSON()
{
    tpl.writeJSON("top2");
    TopologyList tpl2;
    tpl2.readJSON("top2.json");
    if (tpl2.topology_list[0].get_id() != "top2")return false;
    cout << "writeJSON passed all the tests successfully....\n";
    return true;
}
bool test::test_queryTopologies()
{
    auto top = tpl.queryTopologies();
    if (top.size() != 2)return false;
    if (top[0].get_id() != "top1")return false;
    if (top[1].get_id() != "top2")return false;

    cout << "queryTopologies passed all the tests successfully....\n";
    return true;
}
bool test::test_deleteTopology()
{
    tpl.deleteTopology("top2");
    if (tpl.topology_list.size() != 1)return false;
    if (tpl.topology_list[0].get_id() != "top1")return false;
    cout << "deleteTopology passed all the tests successfully....\n";
    return true;
}
bool test::test_queryDevices()
{
    auto comp =tpl.queryDevices("top1");
    if (comp.size() != 2)return false;
    if (comp[0].getComponentId() != "res1")return false;
    if (comp[1].getComponentId() != "m1")return false;
    cout << "queryDevices passed all the tests successfully....\n";
    return true;
}
bool test::test_queryDevicesWithNetlistNode()
{
    auto comp = tpl.queryDevicesWithNetlistNode("top1","m1");
    if (comp.getComponentId() != "m1")return false;
    cout << "queryDevicesWithNetlistNode passed all the tests successfully....\n";
    return true;
}
void test::run_tests()
{
    assert(test_readJSON());
    assert(test_writeJSON());
    assert(test_queryTopologies());
    assert(test_deleteTopology());
    assert(test_queryDevices());
    assert(test_queryDevicesWithNetlistNode());
    cout << "APIs passed all the tests successfully....";
}