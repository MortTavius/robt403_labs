#include "ros/ros.h"
#include "std_msgs/Float64.h"

#include <math.h>
float x = 0;
float prev = 0;
float t = 0;
void jointCallback(const std_msgs::Float64 msg) {
	x = msg.data;
	//Task 1
	/*if(prev <= x){
	prev = x;
	}
	else{
	x = prev;
	}
	*/
}


int main(int argc, char **argv){
ros::init(argc, argv, "rotate");
ros::NodeHandle nh;

//Task 2
//ros::Publisher pub5 = nh.advertise<std_msgs::Float64>("/robot/joint5_position_controller/command", 100);
ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 100);

//Task 1 & 3
//ros::Publisher pub4 = nh.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 100);

ros::Subscriber sub1 = nh.subscribe("/robt403_des_joint4_angle", 1000, jointCallback);



ros::Rate loop_rate(10);
int i = 0;
ros::Time startTime = ros::Time::now();

	while (ros::ok()){
		std_msgs::Float64 msg_to_send;
		
		//Task 3
		t = ros::Time::now().toSec();
		msg_to_send.data = sin(t);
		pub1.publish(msg_to_send);
		//pub5.publish(msg_to_send);
		
		
		//Task 1
		//msg_to_send.data = x;
		//pub4.publish(msg_to_send);
		
		//Task 2
		//pub1.publish(msg_to_send);
		//pub5.publish(msg_to_send);
		
		ROS_INFO("moving joint 4");
		ros::spinOnce();
		
		loop_rate.sleep();
	}
}