//
// Created by Jürgen Kaiser on 03.10.16.
//

#include "ListReservationsRequestBuilder.h"

bool ListReservationsRequestBuilder::BuildRequest(rpc::Request &request) const {

    request.set_type(rpc::Request_Type_DELETE);
    request.mutable_listjobsrequest();

    return true;
}
