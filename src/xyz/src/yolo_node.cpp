#include "ros/ros.h"
#include <darknet_ros_msgs/BoundingBoxes.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int64MultiArray.h"
#include "mavros_msgs/OverrideRCIn.h"
#include <time.h>
using namespace std;
	uint16_t my_pitch=1500;
   	uint16_t my_roll=1500;
   	uint16_t my_yaw=1500;
   	uint16_t my_throttle=1300;
   	//uint16_t my_throttle=1300;
   	bool flag=false;
   	bool flagtime=false;
   	bool object=true;
   	bool clockstart=false;
void boxesCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg)
{
    int y,c,r=640,h=460;//k have to be change when touch==1  k=(ymax-ymin)    1280x720 now
    int i;
    int rl;//right,left
    int td;//top,down
    float k=0.2;//right left k
    float v=0.2;//top down k
    clockstart=true;
    flag=true ;
    //cout << sizeof (msg-> bounding_boxes)<<endl;
   
    
       
     
   
	
	cout << "\033[2J\033[1;1H";
	//////////////////////////////////////////////////////////
 
	cout<<"probability ="<<msg->bounding_boxes[0].probability<<endl;
	
	/*
	if((msg->bounding_boxes[1].Class=="person"&&msg->bounding_boxes[1].probability>0.96)&&(msg->bounding_boxes[0].Class=="person"&&msg->bounding_boxes[0].probability>0.96))
	{
	ROS_INFO("Too many person DONT MOVE");
	my_roll=1500;
	my_yaw=1500;
	my_pitch=1500;
	
	}
	
	else*/ 
	if(msg->bounding_boxes[0].Class!="person"||(msg->bounding_boxes[0].Class=="person"&&msg->bounding_boxes[0].probability<0.96))
 {
   	ROS_INFO("No person DONT MOVE");
        //ROS_INFO("my_row=1500\nmy_yaw=1500\nmy_pitch=1500");
        my_roll=1499;
	my_yaw=1497;
	my_pitch=1499;
	
	
 }
	
	
	
	else if(msg->bounding_boxes[0].Class=="person"&&msg->bounding_boxes[0].probability>0.96)
 {

        

	if(((msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)>(h-50))&&((msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)<(h+50)))  //forward and back
	{
	ROS_INFO("DONT MOVE");
	//ROS_INFO("my_row=1500\nmy_yaw=1500\nmy_pitch=1500");
	my_pitch=1499;
	
	}
	else if((msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)<h)
        {
        td=(msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)-h;
        
        td=td*v;
        my_pitch=1499-td;
      
        ROS_INFO("my pitch =%d",my_pitch);
        
	}
    
        else if((msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)>h)
        {
        
        td=(msg->bounding_boxes[0].ymax-msg->bounding_boxes[0].ymin)-h;
        td=td*v;
        my_pitch=1499-td;
        
        ROS_INFO("my pitch =%d",my_pitch);
       
        
        
        
    

    }
    if(((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)>(r-50)&&((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)<(r+50)) //left and right
    {
        ROS_INFO("DONT MOVE");
        //ROS_INFO("my_row=1500\nmy_yaw=1500\nmy_pitch=1500");
        
	my_yaw=1497;
	
	
	
    }
    else if(((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)>r)
    {
    	rl=((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)-r;        
        rl=rl*k;
        my_yaw=1497+rl;
        ROS_INFO("my yaw =%d",my_yaw);
        
        
        
       

    }
    else if(((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)<r)
    {
      rl=((msg->bounding_boxes[0].xmin+msg->bounding_boxes[0].xmax)/2)-r;
      rl=rl*k;
      my_yaw=1497+rl;
      ROS_INFO("my yaw =%d",my_yaw);
      
      
    }
	
	
}

   

   
}

int main(int argc, char **argv)
{
  clock_t start,end ;
  
  
  ros::init(argc, argv, "yolo");
  ros::NodeHandle n;
 // mavros_msgs::OverrideRCIn yolo_msg;
  geometry_msgs::Twist    yolo_int_msg;
  ros::Rate loop_rate(100);
 // ros::Publisher       yolo_pub        = n.advertise<mavros_msgs::OverrideRCIn>("mavros/rc/override",100);
  ros::Publisher yolo_int_pub = n.advertise<geometry_msgs::Twist>("yoloint", 10);
  ros::Subscriber yolo_sub = n.subscribe("/darknet_ros/bounding_boxes/",10,boxesCallback);
 while (ros::ok())
 {
    
    start = clock();
    if(object==false){
    yolo_int_msg.linear.x=my_roll;
    yolo_int_msg.linear.y=my_yaw;
    yolo_int_msg.linear.z=my_pitch;
    yolo_int_msg.angular.x=0;
    }
    else
    {
    yolo_int_msg.linear.x=my_roll;
    yolo_int_msg.linear.y=my_yaw;
    yolo_int_msg.linear.z=my_pitch;
    yolo_int_msg.angular.x=1;
    }
  //yolo_msg.channels={my_roll,my_pitch,my_throttle,my_yaw,1500,1500,1500,1500};
 // yolo_pub.publish(yolo_msg);
  yolo_int_pub.publish(yolo_int_msg);
  if(flag == false && flagtime == false)
  {
 	end = clock();
 	
 	flagtime=true;
  }
  else if (flag == true)
  {
  	 end = 0;
  	 start = 0;
  	flagtime=false;
  }
  //cout << (double) abs((end-start)) <<endl;
  if(clockstart==true&& (double) abs((end-start))>=200000)
  {
  cout << "time' up"<<endl;
  object=false;
  }
  flag = false;
  ros::spinOnce();
  loop_rate.sleep();
  
}

  return 0;
}


