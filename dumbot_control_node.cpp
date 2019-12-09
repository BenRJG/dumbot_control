#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"
//#include "std/Vector.h"

/*float xxx;
float yyy;

ros::Publisher marker_pub;

uint8_t radius;

visualization_msgs::Marker marker;*/

sensor_msgs::Joy joy;
//std_msgs::String button_pressed[] = {"Square","Triangle","Circle","X","L1","L2","R1","R2","Share","Options","Home","Touch Pad","L3","R3","Left","Up","Right","Down"};


class proximity
{
public:
	proximity()
	{
		ros::NodeHandle n;
		
		button_sub = n.subscribe("/joy", 1000, &proximity::chatterCallback, this);
		

		


		//controller_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

		/*xxx = 0.0;
		yyy = 0.0;

		radius = 3;
		uint32_t shape = visualization_msgs::Marker::SPHERE;

		//vizualization_msgs::Marker marker;

		//Set frame ID and Timestamp (look at TF tutorials
		marker.header.frame_id = "/map";
		marker.header.stamp = ros::Time::now();

		//declare namespace and id
		marker.ns = "basic_shapes";
		marker.id = 0;
	
		//Set type of marker
		marker.type = shape;

		//Action for marker, ADD, DELETE or DELETEALL
		 marker.action = visualization_msgs::Marker::ADD;

		//Set position
		marker.pose.position.x = xxx;
		marker.pose.position.y = yyy;
		marker.pose.position.z = 0.0;
		marker.pose.orientation.x = 0;
		marker.pose.orientation.y = 0;
		marker.pose.orientation.z = 0;
		marker.pose.orientation.w = 1.0;

		//Colour
		marker.color.r = 0.0f;
		marker.color.g = 1.0f;
		marker.color.b = 0.0f;
		marker.color.a = 1.0f;

		//Scale
		marker.scale.x = 0.25;
		marker.scale.y = 0.25;
		marker.scale.z = 0.25;

		//How long the marker exists for
		marker.lifetime = ros::Duration();
		marker_pub.publish(marker);*/
	}

	void chatterCallback(const sensor_msgs::Joy::ConstPtr& input) // Change this variable for inputs
	{
	//conver array to int
	/*int buttonInput = 0;
	for (i = 0; i<4; i++)
	{
		buttonInput += input->buttons[i];
		buttonInput = buttonInput << 1;
	}*/
		
	ROS_INFO("Button Combo: %d %d %d %d", input->buttons[0], input->buttons[1], input->buttons[2], input->buttons[3]);



	/*float distance = sqrt(((msg->pose.position.x - xxx)*(msg->pose.position.x - xxx))+((msg->pose.position.y - yyy)*(msg->pose.position.y - yyy)));
				
		if(distance <= 0.1)
		{
			xxx = radius - (static_cast<float> (rand())/static_cast<float>(RAND_MAX/(radius*2)));
			yyy = radius - (static_cast<float> (rand())/static_cast<float>(RAND_MAX/(radius*2)));

			marker.pose.position.x = xxx;
			marker.pose.position.y = yyy;

			marker_pub.publish(marker);
		}*/
	}

protected:
	ros::Publisher controller_pub;
	ros::Subscriber button_sub;

	//float xxx;
	//float yyy;	
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "dumbot_control_node");
	
	proximity test;

	ros::spin();

	return 0;
}
