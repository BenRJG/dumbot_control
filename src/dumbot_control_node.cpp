#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"
#include "sensor_msgs/JoyFeedbackArray.h"
#include "std_msgs/UInt8.h"
#include "ds4_driver/Status.h"
#include "std_msgs/Float32MultiArray.h"

/*float xxx;
float yyy;

ros::Publisher marker_pub;

uint8_t radius;*/

sensor_msgs::JoyFeedbackArray rumble;

sensor_msgs::Joy joy;

std_msgs::Float32MultiArray analogVal;

float max = 1.0;

int pubRate = 0;

class proximity
{
public:
	proximity()
	{
		ros::NodeHandle n;
		
		analog_sub = n.subscribe("/status", 1000, &proximity::controlFeedback, this);
		wheel_pub = n.advertise<std_msgs::Float32MultiArray>("wheelControl",1);

		analogVal.layout.dim.push_back(std_msgs::MultiArrayDimension());
		analogVal.layout.dim[0].label = "wheel values";		
		analogVal.layout.dim[0].size = 2;
		analogVal.layout.dim[0].stride = 2;
		analogVal.layout.data_offset = 0;
		std::vector<float> vec(2,0);
		vec[0] = 0.0;
		vec[1] = 0.0;
		analogVal.data = vec;
		wheel_pub.publish(analogVal);
	}

	void controlFeedback(const ds4_driver::Status::ConstPtr& msg) // Change this variable for inputs
	{		
	if (pubRate>=10){	
		float leftWheel = 0.0;
		float rightWheel = 0.0;
		leftWheel = (msg->axis_r2 - msg->axis_l2)-msg->	axis_right_x;
		rightWheel = (msg->axis_r2 - msg->axis_l2)+msg->axis_right_x;	
		if (leftWheel>1.0){leftWheel = 1.0;}
		if (rightWheel>1.0){rightWheel = 1.0;}



		analogVal.data[0] = leftWheel;
		analogVal.data[1] = rightWheel;	
		wheel_pub.publish(analogVal);
		ROS_INFO("DATA: %f %f",analogVal.data[0],analogVal.data[1]);
		pubRate = 0;
	}
	pubRate++;
	}

	

protected:
	ros::Publisher wheel_pub;
	ros::Subscriber analog_sub;	
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "dumbot_control_node");
	
	proximity test;

	ros::spin();

	return 0;
}
