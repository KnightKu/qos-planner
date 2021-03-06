//
// Created by Jürgen Kaiser on 03.10.16.
//

#include <gtest/gtest.h>

#include <ListReservationsRequestBuilder.h>

TEST(ListReservationsRequestBuilderTest, CreatesMessage) {
    ListReservationsRequestBuilder rb;
    rpc::Request message;

    ASSERT_TRUE(rb.BuildRequest(message));

    ASSERT_EQ(rpc::Request_Type_LISTJOBS, message.type());

    ASSERT_FALSE(message.has_deleterequest());
    ASSERT_FALSE(message.has_resourcerequest());

}
