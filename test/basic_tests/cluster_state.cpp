//
// Created by jkaiser on 08.03.16.
//


#include "gtest/gtest.h"

#include <ClusterState.h>
#include <Lustre.h>
#include "MockLustre.h"


TEST(MemClusterState, InitTeardown) {
    common::MockLustre *lustre = new common::MockLustre();
    std::shared_ptr<common::Lustre> l (lustre);
    common::MemoryClusterState mcs(l);
    EXPECT_TRUE(mcs.Init());

    std::this_thread::sleep_for(std::chrono::seconds(1)); // give the thread time to start
    EXPECT_TRUE(mcs.TearDown());
};

TEST(MemClusterState, GetState) {
    common::MockLustre *lustre = new common::MockLustre();
    std::shared_ptr<common::Lustre> l (lustre);
    common::MemoryClusterState mcs(l);
    EXPECT_TRUE(mcs.Init());

    EXPECT_TRUE(mcs.GetOSTList()->empty());
    common::OSTWorkload ns = {"n1", 42, 17};
    mcs.UpdateNode("n1", ns);

    common::OSTWorkload rt;
    EXPECT_TRUE(mcs.getOstState("n1", &rt));
    EXPECT_STREQ(rt.name.c_str(), "n1");
    EXPECT_EQ(ns.rpcSec, rt.rpcSec);
    EXPECT_EQ(ns.maxRpcSec, rt.maxRpcSec);

    EXPECT_TRUE(mcs.TearDown());
};


