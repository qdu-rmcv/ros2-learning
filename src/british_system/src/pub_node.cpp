#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int8.hpp" // 因为题目要求的随机数在0-100之间，所以使用Int8,貌似能节省空间带宽并提高效率（？）
#include<bits/stdc++.h>

using namespace rclcpp;
using namespace std_msgs;
using namespace std::chrono_literals; // 包含时间单位

class inch_talker: public rclcpp::Node{ // 发布者节点，发布随机inch到/inch话题，由meter_listener节点订阅
public:
    inch_talker():Node("inch_talker"){
        RCLCPP_INFO(this->get_logger(),"inch_talker node is running!");
        publisher_ = this->create_publisher<msg::Int8>("/inch",10); //创建发布者，话题为/inch
        timer_ = this->create_wall_timer(100ms,  // 创建定时器，回调函数为了简洁使用了lambda表达式
            [this]() {
            std::random_device rd; // 随机数生成器
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int8_t> dis(0, 100);
            int8_t random = dis(gen);

            msg::Int8 message;
            message.data = random;

            publisher_->publish(message); // 发布消息
            RCLCPP_INFO(this->get_logger(), "Inch:%hhd", message.data);
            }
        );
    }

private:
    Publisher<msg::Int8>::SharedPtr publisher_; // 发布者
    TimerBase::SharedPtr timer_; // 定时器
};


int main(int argc, char * argv[]){
    init(argc,argv);
    spin(std::make_shared<inch_talker>());
    shutdown();
    return 0;
}

