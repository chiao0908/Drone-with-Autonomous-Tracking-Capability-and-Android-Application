#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int64MultiArray.h"
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Thrust.h>
#include <mavros_msgs/BatteryStatus.h>
#include <sstream>
#include "mavros_msgs/OverrideRCIn.h"
#include <stdint.h>
#include <time.h>
using namespace std;
///yolo control yaw pitch roll
int yoloyaw,yolopitch,yoloroll,object;
int controlyaw,controlpitch,controlroll,controlthrottle;
bool control=true;
///
bool sta,loi,cir,land,arm,disarm,fol;
bool flag=false;//control?
bool flagtime=false;//time
bool follow=false;
bool clockstart=false;
int armflag = 100;
int stateflag =1;
int x=100;//data 2 
bool i,a=0,b=0,c=0,d=0;
/////////////////////////////
uint16_t pitch=1499;//1075 1932  uint16_t
uint16_t roll=1499;//1075 1932
uint16_t yaw=1497;//1930 1070
uint16_t throttle=1069;//max 1928
void print();
void Batterycallback(const std_msgs::Header::ConstPtr& msg);


//void state_cb(const mavros_msgs::State::ConstPtr& msg);

void testCallback(const std_msgs::Int64MultiArray::ConstPtr& msg);
void yoloCallback(const geometry_msgs::Twist msg);

//mavros_msgs::State current_state;

int main(int argc, char **argv)
{
  clock_t start,end ;
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  mavros_msgs::CommandBool arm_cmd;
  mavros_msgs::State current_state;
   //geometry_msgs::Twist phone_msg;
  mavros_msgs::OverrideRCIn phone_msg;
  mavros_msgs::SetMode offb_set_mode;
  mavros_msgs::BatteryStatus remaining_msg;
  ros::ServiceClient arming_client = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
  ros::ServiceClient set_mode_client = n.serviceClient<mavros_msgs::SetMode> ("mavros/set_mode");
  //ros::Publisher     main_pub      = n.advertise<geometry_msgs::Twist>("mavros/setpoint_velocity/cmd_vel_unstamped",100);
  ros::Publisher     main_pub      = n.advertise<mavros_msgs::OverrideRCIn>("mavros/rc/override",100);
 // ros::Subscriber state_sub = n.subscribe("mavros/state", 10, state_cb);
  ros::Subscriber sub = n.subscribe("test", 1000, testCallback);
  ros::Subscriber yolo_sub = n.subscribe("yoloint", 10, yoloCallback);
  ros::Rate loop_rate(100);
   
   while(ros::ok())
{
   start = clock();
   ros::spinOnce();
   //if(control==false||object==0)
   if(control==false)
   {
   offb_set_mode.request.custom_mode = "LAND";
    if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {
                	land = true;
         	       //ROS_INFO("Land");
         	}
   }
 else if(stateflag==1&&follow==false)
   {
   
   offb_set_mode.request.custom_mode = "STABILIZE";
   if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {      
                       sta=true;	
         	       //ROS_INFO("Stabilize");
         	       stateflag=100;
         	       
                }
 }
 else if(follow==true&&(control!=false||object!=0))
  {
   
    offb_set_mode.request.custom_mode = "LOITER";
    if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {
                	fol=true;
         	      
         	        stateflag=100;
         	      
                }
 
   
  }
  
   
   
   
   else if(stateflag==2&&follow==false)
   {
    offb_set_mode.request.custom_mode = "LOITER";
    if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {
                	loi=true;
         	      // ROS_INFO("Loiter");
         	       stateflag=100;
         	      
                }
   
   }
   else if(stateflag==3&&follow==false)
   {
    offb_set_mode.request.custom_mode = "CIRCLE";
    if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {
                	cir=true;
         	      
         	       stateflag=100;
         	       
                }
   }
   else if(stateflag==4&&follow==false)
   {
    offb_set_mode.request.custom_mode = "LAND";
    if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent)
                {
                	land = true;
         	       stateflag=100;
         	       
                }
   }
   //////////////arm////////////////////////////////
   if (armflag==1)
   {
   	
   	arm_cmd.request.value = true;//if throttle=1000
  	
  	if(arming_client.call(arm_cmd) &&arm_cmd.response.success)
   	{
   		arm=true;
   		disarm=false;
     		//ROS_INFO("%s",current_state.armed);
    	       armflag=100;
    		
    		
        }
  }
  
  else if(armflag==0)//disarm
  {
  	arm_cmd.request.value = false;
  	//my_throttle=1000;
  	//phone_msg.channels={1500,1500,1000,1500,1500,1500,1500,1500};
  	//phone_msg.channels={my_roll,my_pitch,my_throttle,my_yaw,1500,1500,1500,1500};
   	//main_pub.publish(phone_msg);
   	//arming_client.call(arm_cmd);
     	if(arming_client.call(arm_cmd) &&arm_cmd.response.success)
   	{       	
   	        arm=false;
   	        disarm=true;
     		armflag=100;
     		
        }
        
        
     
  }
  

  ////////////////////control///////////////////////////////
 // throttle=controlthrottle;
  if (follow==false)
  {
  	pitch=controlpitch;
  	roll=controlroll;
  	yaw=controlyaw;
  	throttle=controlthrottle;
  	phone_msg.channels={roll,pitch,throttle,yaw,1500,1500,1500,1500};//4=yaw
        main_pub.publish(phone_msg);
  }
  else if(follow==true)
  {
  	pitch=yolopitch;
  	roll=yoloroll;
  	yaw=yoloyaw;
  	throttle=controlthrottle;
  	phone_msg.channels={roll,pitch,throttle,yaw,1500,1500,1500,1500};//3 throttle
        main_pub.publish(phone_msg);
  	
  }
 
  
    ///////control overridercin
  // uint16_t my_pitch=1500;
  // uint16_t my_row=1500;
  //uint16_t my_yaw=1500;
  // uint16_t my_throttle=1300;
  /*
   if(x==2&&i==true)
   {
 	 
        my_throttle=1800;
   	phone_msg.channels={my_roll,my_pitch,my_throttle,my_yaw,1500,1500,1500,1500};
   	main_pub.publish(phone_msg);
   	ROS_INFO("my_throttle=1800");
   	
   	
   
   }
   else if (x==3&&i==true)

   {
   	
	my_throttle=1200;
   	phone_msg.channels={my_roll,my_pitch,my_throttle,my_yaw,1500,1500,1500,1500};
   	main_pub.publish(phone_msg);
   	ROS_INFO("my_throttle=1200");
   	
   	       
   }
   
  */ 
  
   print();
   /////////////////////time/////////////////////////
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

  if(clockstart==true&&(double) abs((end-start))>=450000)
  {
  
  control=false;
  }
  flag = false;
  loop_rate.sleep(); 
   
}

  

  return 0;
}
void testCallback(const std_msgs::Int64MultiArray::ConstPtr& msg)
{ 

   int num=7 ;
   flag=true ;
   clockstart=true;
  

  // cout<<msg->data[4]<<endl;
 /////////////////////////////////////control/////////////////////////////////////////
  controlroll=msg->data[2]+1500;//raw
  controlpitch=msg->data[3]+1500;//pitch
  controlthrottle=((msg->data[4]+148)*3)+1069;//throttle
  controlyaw=msg->data[5]+1500;//yaw
  
   ////////////////////arm = 1    disarm =0////////////////////////////////////////////
  if(msg->data[0]==1)     
  {     
        armflag = 1;
        i=true;
  } 
  else if(msg->data[0]==0)
  {
  	armflag = 0;
  	i=false;
  }   
  else 
  {
	armflag = 100;  
  }

  /////////////////////////////////////////////MODE///////////////////////////////////////////////////////
  if(msg->data[1]==1)
  {
  	stateflag=1;
  	
  	
  }
  else if(msg->data[1]==2)
  {
  	stateflag=2;
  	
  }
   else if(msg->data[1]==3)
  {
  	stateflag=3;
  	
  }
   else if(msg->data[1]==4)
  {
  	stateflag=4;
  	
  }
  else if(msg->data[1]==5)
  {
   	follow=true;
  }
  else if (msg->data[1]==6)
  {     
  	stateflag=2;
  	follow=false;
  	fol=false;
  }

  ///////////////////////////////////////////FOLLOW//////////////////////////////////////////////////////
   
  
  
}


void yoloCallback(const geometry_msgs::Twist msg)
{
 	yoloyaw = msg.linear.y;
	yolopitch = msg.linear.z;
 	yoloroll = msg.linear.x;
 	object = msg.angular.x;//1 or 0



}

void print()
{
	cout << "\033[2J\033[1;1H";  
	//if(sta==true)
	if(sta==true)
	{
		ROS_INFO("mode=Stabilize");
		sta=false;
		ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
		if(arm==true && disarm==false)
		{
			ROS_INFO("state =ARMED");
		}
		else if(disarm==true && arm==false)
		{
			ROS_INFO("state =DISARMED");
		}
		ROS_INFO("follow=%d",fol);
		fol=false;
		
	}
	//else if (loi==true||fol==true)
	else if (loi==true||fol==true)
	{
		ROS_INFO("mode=Loiter");
		loi=false;
		ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
			if(arm==true && disarm==false)
		{
			ROS_INFO("state =ARMED");
		}
		else if(disarm==true && arm==false)
		{
			ROS_INFO("state =DISARMED");
		}
		ROS_INFO("follow=%d",fol);
		fol=false;
	}
	else if (cir==true)
	{
		ROS_INFO("mode=Circle");
		cir=false;
		ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
		if(arm==true && disarm==false)
		{
			ROS_INFO("state =ARMED");
		}
		else if(disarm==true && arm==false)
		{
			ROS_INFO("state =DISARMED");
		}
		ROS_INFO("follow=%d",fol);
		fol=false;
	}
/*
	else if(fol==true)
	{
		ROS_INFO("mode=FOLLOW");
		fol=false;
		ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
		if(arm==true && disarm==false)
		{
			ROS_INFO("state =ARMED");
		}
		else if(disarm==true && arm==false)
		{
			ROS_INFO("state =DISARMED");
		}
		
	}
*/
	else if(land == true)
	{
	        if(object==0)
	  {
		ROS_INFO("mode=no object Land");
		land=false;
	        ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
			if(arm==true && disarm==false)
			{
				ROS_INFO("state =ARMED");
			}
			else if(disarm==true && arm==false)
			{
				ROS_INFO("state =DISARMED");
			}
		ROS_INFO("follow=%d",fol);
		fol=false;	
	  }
	  	else if(control==false)
	  {
	  	ROS_INFO("mode=no control Land");
		land=false;
	        ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
			if(arm==true && disarm==false)
			{
				ROS_INFO("state =ARMED");
			}
			else if(disarm==true && arm==false)
			{
				ROS_INFO("state =DISARMED");
		
			}
			
		ROS_INFO("follow=%d",fol);
		fol=false;
	
	
	 }
	 	else
	 {
		ROS_INFO("mode= Land");
		land=false;
	        ROS_INFO("yaw =%d",yaw);
		ROS_INFO("pitch = %d ", pitch);
		ROS_INFO("roll = %d ", roll);
		ROS_INFO("throttle = %d ", throttle);
			if(arm==true && disarm==false)
			{
				ROS_INFO("state =ARMED");
			}
			else if(disarm==true && arm==false)
			{
				ROS_INFO("state =DISARMED");
			}
			
	 	ROS_INFO("follow=%d",fol);
	 	fol=false;
	 }
	
	
      }
}	
	





/*


void state_cb(const mavros_msgs::State::ConstPtr& msg){
    cout << current_state.armed<<endl;
    
}



*/










