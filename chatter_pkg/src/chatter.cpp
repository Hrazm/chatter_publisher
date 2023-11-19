#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "int_pup");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("integer", 10);

    ros::Rate rate(1); // Publish at 1 Hz

    int count = 20;
    while (ros::ok())
    {
        std_msgs::Int32 msg;
        msg.data = count;
        pub.publish(msg);
        ROS_INFO("Published integer: %d", count);
        count++;
        if (count > 100)
        {
            break;
        }
        rate.sleep();
    }

    return 0;
}