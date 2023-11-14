#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
#include "std_msgs/String.h"

void bigbossCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}
int main(int argc, char **argv)
{

  ros::init(argc, argv, "maincontrol");


  ros::NodeHandle n;


  ros::Publisher maincontrol_pub = n.advertise<geometry_msgs::Twist>("car/cmd_vel", 1000);
  ros::Subscriber maincontrol_sub= n.subscribe("bigboss",1000,bigbossCallback);
  ros::Rate loop_rate(10);

  int count =0;

  while (ros::ok())
  {

    geometry_msgs::Twist run_msg;

    run_msg.linear.x=count;
    run_msg.linear.y=0;
    run_msg.linear.z=0;
    run_msg.angular.x=0;
    run_msg.angular.y=0;
    run_msg.angular.z=0;




    maincontrol_pub.publish(run_msg);

    ros::spinOnce();
    loop_rate.sleep();
   ++count;
  }


  return 0;
}
