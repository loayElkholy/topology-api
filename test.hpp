#pragma once
#include "TopologyList.hpp"
class test
{
    TopologyList tpl;

    bool test_readJSON();
    bool test_writeJSON();
    bool test_queryTopologies();
    bool test_deleteTopology();
    bool test_queryDevices();
    bool test_queryDevicesWithNetlistNode();
public:
    void run_tests();
};

