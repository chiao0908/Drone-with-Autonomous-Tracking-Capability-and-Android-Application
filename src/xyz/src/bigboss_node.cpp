#include "ros/ros.h"
#include <sstream>
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "geometry_msgs/Twist.h"
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>


void sensorvalueCallback(const geometry_msgs::Twist& sensorvalue_msg)
{

}



 int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }
int main(int argc, char **argv)
{
    ros::init(argc,argv,"bigboss");
    ros::NodeHandle n;
    ros::Subscriber bigboss_sub=n.subscribe("sensorvalue",1000,sensorvalueCallback);

    ros::Rate loop_rate(60);



    }
    return 0;
}
