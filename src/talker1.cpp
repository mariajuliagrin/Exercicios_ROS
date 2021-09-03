

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");//precisa dos argumentos argc e argv para aceitar quaisquer argumentos ROS. O terceiro argumento é o nome do nó

  
  ros::NodeHandle n;//principal ponto de acesso às comunicações com o sistema ROS

//advertise é a maneira de informar ao ROS que o nó deseja publicar em um determinado nome de tóico(chatter)
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//o nó master  notificara qualquer nó que estiver tentando se inscrever no nome deste tópico e, por sua vez, negociará uma conexão ponto a ponto com esse nó.
//advertise retorna um objeto Publisher que permite publicar mensagens sobre esse tópico por meio de uma chama Publish()

//segundo parÂmeto é o tamanho da fila de mensagens usada para publicar.
//Se as mensagens forem publicadas mais rapidamente do que podemos enviá-las, este número especifica quantas mensagens serao armazenadas em buffer antes de jogar fora algumas.
  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    
    std_msgs::String msg;//objeto de mensagem, o qual deve ser preenchid com dados e depois publicado

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);//A função publish serve para publicar a mensagem. o parâmetro é o objeto da mensagem. o tipo deste objeto deve concordar com o tipo fornecido no advertise().

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}

