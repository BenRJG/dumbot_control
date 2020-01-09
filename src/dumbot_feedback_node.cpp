#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Joy.h"
#include "sensor_msgs/JoyFeedbackArray.h"
#include "std_msgs/UInt8.h"
#include "ds4_driver/Feedback.h"
#include "std_msgs/Int8MultiArray.h"

#define gotoxy(x,y) printf("\033[%d;%df", (y), (x))
#define clear() printf("\033[H\033[J")

/*float xxx;
float yyy;

ros::Publisher marker_pub;

uint8_t radius;*/

sensor_msgs::JoyFeedbackArray rumble;

sensor_msgs::Joy joy;
ds4_driver::Feedback controllerFeedback;
//std_msgs::String button_pressed = {"Square","Triangle","Circle","X","L1","L2","R1","R2","Share","Options","Home","Touch Pad","L3","R3","Left","Up","Right","Down"};


class proximity
{
public:
	proximity()
	{
		ros::NodeHandle n;
		
		//button_sub = n.subscribe("/joy", 1000, &proximity::chatterCallback, this);
		sensor_sub = n.subscribe("/chatter", 1000, &proximity::chatterCallback, this);
		controller_pub = n.advertise<ds4_driver::Feedback>("set_feedback",1);
		ROS_INFO("Running");

		controllerFeedback.set_led = true;
		controllerFeedback.led_r = 0.0;
		controllerFeedback.led_g = 0.0;
		controllerFeedback.led_b = 1.0;

		controllerFeedback.set_led_flash = true;
		controllerFeedback.led_flash_on = 0.0;
		controllerFeedback.led_flash_off = 0.0;

		controllerFeedback.set_rumble = true;
		controllerFeedback.rumble_duration = 0.0;
		controllerFeedback.rumble_small = 0.0;
		controllerFeedback.rumble_big = 0.0;
		controller_pub.publish(controllerFeedback);
	}

	void chatterCallback(const std_msgs::Int8MultiArray::ConstPtr& msg) // Change this variable for inputs
	{		
		
		controllerFeedback.set_led = true;
		controllerFeedback.led_r = 1.0 * (1-(msg->data[0]/255.0));
		controllerFeedback.led_g = 1.0 * (msg->data[0]/255.0);
		controllerFeedback.led_b = 0.0;
		if(msg->data[0] < 40)
		{
			//rumble.data[] = 1;			
			//controller_pub.publish(rumble);

			controllerFeedback.set_led_flash = true;
			controllerFeedback.led_flash_on = 0.2;
			controllerFeedback.led_flash_off = 0.2;
			
			if (rumbleStart == false){
				controllerFeedback.set_rumble = true;
				controllerFeedback.rumble_duration = 60;
				controllerFeedback.rumble_small = 1.0;
				controllerFeedback.rumble_big = 0.0;
				rumbleStart = true;
			}
			controller_pub.publish(controllerFeedback);
		}else{
			/*controllerFeedback.set_led = true;
			controllerFeedback.led_r = 0.0;
			controllerFeedback.led_g = 1.0;
			controllerFeedback.led_b = 0.0;*/

			controllerFeedback.set_led_flash = true;
			controllerFeedback.led_flash_off = 0.0;

			if (rumbleStart = true){			
				controllerFeedback.set_rumble = true;
				controllerFeedback.rumble_duration = 0.0;
				controllerFeedback.rumble_small = 0.0;
				controllerFeedback.rumble_big = 0.0;
				rumbleStart = false;
			}

			controller_pub.publish(controllerFeedback);

		}
		printf("%d\n\r",msg->data[0]);
	}

protected:
	ros::Publisher controller_pub;
	ros::Subscriber sensor_sub;
	bool rumbleStart = false;	
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "dumbot_control_node");
	
	proximity test;
	clear();
	printf("\n\r");
	printf("                      *** ### ### ***\n\r");
	printf("                  *##                 ##*\n\r");
	printf("              *##                         ##*\n\r");
	printf("           *##                               ##*\n\r");
	printf("         *##                                   ##*\n\r");
	printf("       *##                                       ##*\n\r");
	printf("      *##                                         ##*\n\r");
	printf("     *##                                           ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("    *##                                             ##*\n\r");
	printf("     *##                                           ##*\n\r");
	printf("      *##                                         ##*\n\r");
	printf("       *##                                       ##*\n\r");
	printf("         *##                                   ##*\n\r");
	printf("           *#                                ##*\n\r");
	printf("              *##                         ##*\n\r");
	printf("                  *##                 ##*\n\r");
	printf("                      *** ### ### ***\n\r");
	gotoxy(29,1);
	printf("x1x");

	gotoxy(52,6);
	printf("x2x");

	gotoxy(57,14);
	printf("x3x");

	gotoxy(52,22);
	printf("x4x");

	gotoxy(29,27);
	printf("x5x");

	gotoxy(6,22);
	printf("x6x");

	gotoxy(1,14);
	printf("x7x");

	gotoxy(6,6);
	printf("x8x");

	gotoxy(26,1);
	printf("\n\r");
	ros::spin();

	return 0;
}
