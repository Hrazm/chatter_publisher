#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "turtle_velocity_publisher");  // Initialize the ROS node
    ros::NodeHandle nh;  // Create a ROS NodeHandle
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);  // Create a publisher for the "/turtle1/cmd_vel" topic
    ros::Rate rate(1);  // Set the rate of publishing (1 Hz in this example)

    // Create a Twist message with linear x and angular z velocities
    geometry_msgs::Twist twist_msg;
    twist_msg.linear.x = 0.5;  // Linear speed of 0.5 m/s
    twist_msg.angular.z = 0.0;  // No angular velocity

    // Publish the Twist message to make the turtlesim move forward
    while (ros::ok()) {
        pub.publish(twist_msg);

        // Log the published velocities
        ROS_INFO("Published Twist message - Linear: %f m/s, Angular: %f rad/s", twist_msg.linear.x, twist_msg.angular.z);

        // Wait for the next iteration
        rate.sleep();
    }

    // Node has finished publishing, and the program ends
    return 0;
}
