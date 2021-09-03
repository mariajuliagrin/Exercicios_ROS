#include "ros/ros.h"
#include "std_msgs/String.h"

//função que será chamada quando uma nova mensagem chegar no tópico do chatter
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//O ROS chamará a função chatterCallback() sempre que uma nova mensagem chegar. O segundo argumento é o tamanho da fila, caso não consigamos processar as mensagens com rapidez suficiente. Nesse caso, se a fila atingir 1000 mensagens, começaremos a jogar fora as mensagens antigas à medida que novas chegarem

  
  ros::spin();

  return 0;
}
