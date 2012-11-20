#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>


int main(int argc, char** argv)
{
	ros::init(argc, argv, "koushik_test_node");
	printf("Node Started \n");
	ros::NodeHandle nh;
	ros::Publisher vel_pub;
	int i,j;
	geometry_msgs::Twist cmdvel;
	vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
	printf("Connected to topic");
	cmdvel.linear.y=0;
	cmdvel.linear.z=0;
	cmdvel.angular.x=0;
	cmdvel.angular.y=0;
	cmdvel.angular.z=0;
	for(i=0;i<10;i++)
	{
		printf("Started to publish \n");
		cmdvel.linear.x=0.5;
		scanf("%d",&j);
		cmdvel.angular.z=j/20;
		vel_pub.publish(cmdvel);
		printf("Message published \n");
		
	}
	ros::spin();
}
