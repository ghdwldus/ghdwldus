#include <ros/ros.h>

#include "p/problem3_msg.h"

using namespace std;

int64_t sum;
void subCallback(const p::problem3_msgPtr& msg){
    if(msg->id == "second message"){
        sum += msg->data;
    }
    else{
        sum = msg->data;
    }
    
    ROS_INFO_STREAM("first messsage & second message sim is "<< sum);
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem3_sub");
    ros::NodeHandle nh;

    ros::Subscriber first = nh.subscribe("problem3", 1000, subCallback);
    ros::Subscriber second = nh.subscribe("problem3", 1000, subCallback);

    ros::spin();
    return 0;
}