#include <ros/ros.h>
#include "bumperbot_examples/AddTwoInts.h"

bool addCallback(bumperbot_examples::AddTwoInts::Request &req, bumperbot_examples::AddTwoInts::Response &res){
    ROS_INFO("Ready to sum %d and %d", (int)req.a, (int)req.b);
    res.sum = req.a + req.b;
    return true;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "simple_service_server_cpp");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("add_two_ints", addCallback);
    ROS_INFO("The service is ready to add ints");
    ros::spin();

    return 0;
}