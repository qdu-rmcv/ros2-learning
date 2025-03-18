#include "rclcpp/rclcpp.hpp"
#include "zidingyi_xiaoxijiekou/msg/huati.hpp"
#include <iostream>

//节点类
class jiedian: public rclcpp::Node{
    public:
    jiedian(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"订阅数据的节点启动!");
        subscription_=this->create_subscription<zidingyi_xiaoxijiekou::msg::Huati>("topic1",10,std::bind(&jiedian::callback,this,std::placeholders::_1));
    }//构造函数，创建订阅者节点，接受到话题消息的时候，调用callback函数
    private:
    rclcpp::Subscription<zidingyi_xiaoxijiekou::msg::Huati>::SharedPtr subscription_;
    void callback(const std::shared_ptr<zidingyi_xiaoxijiekou::msg::Huati> mess){
        RCLCPP_INFO(this->get_logger(),"接收到客户端发布的数据，为：%d",mess->num_result);
    }//callback函数，用于将接收到的消息打印出来
};
int main(int argc,char **argv){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<jiedian>("node");//创建节点的共享指针
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}