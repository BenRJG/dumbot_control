#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"

//std_msgs::String button_pressed[] = {"Square","Triangle","Circle","X","L1","L2","R1","R2","Share","Options","Home","Touch Pad","L3","R3","Left","Up","Right","Down"};


class crontrollerData
{
public:
	crontrollerData()
	{
		ros::NodeHandle n;
		
		button_sub = n.subscribe("/joy", 1000, &proximity::chatterCallback, this);
		//controller_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

		//marker_pub.publish(marker);*/
	}

	void chatterCallback(const sensor_msgs::Joy::ConstPtr& input) // Change this variable for inputs
	{
		//convert array to int
		/*int buttonInput = 0;
		for (i = 0; i<4; i++)
		{
			buttonInput += input->buttons[i];
			buttonInput = buttonInput << 1;
		}*/

		ROS_INFO("Button Combo: %d %d %d %d", input->buttons[0], input->buttons[1], input->buttons[2], input->buttons[3]);
	}

protected:
	ros::Publisher controller_pub;
	ros::Subscriber button_sub;
	sensor_msgs::Joy joy;
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "dumbot_control_node");
	
	crontrollerData dumbot;

	ros::spin();

	return 0;
}
