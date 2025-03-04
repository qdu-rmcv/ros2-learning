/*
 * @Author: BandieraRosa 3132716198@qq.com
 * @Date: 2025-02-27 14:30:45
 * @LastEditors: BandieraRosa 3132716198@qq.com
 * @LastEditTime: 2025-02-27 23:28:55
 * @FilePath: /ros2_learning/src/british_system/src/pub_node.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "rclcpp/rclcpp.hpp"
#include "msgs/msg/inch_to_meter.hpp"
#include<bits/stdc++.h>

using namespace rclcpp;
using namespace std::chrono_literals; // 包含时间单位

class inch_talker: public rclcpp::Node{ // 发布者节点，发布随机inch到/inch话题，由meter_listener节点订阅
public:
    inch_talker():Node("inch_talker"){
        RCLCPP_INFO(this->get_logger(),"inch_talker node is running!");
        publisher_ = this->create_publisher<msgs::msg::InchToMeter>("/inch",10); //创建发布者，使用自定义接口，话题为/inch
        timer_ = this->create_wall_timer(100ms,  // 创建定时器，回调函数为了简洁使用了lambda表达式
            [this]() {
            std::random_device rd; // 随机数生成器
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int8_t> dis(0, 100);
            int8_t random = dis(gen);

            msgs::msg::InchToMeter message;
            message.random = random;

            publisher_->publish(message); // 发布消息
            RCLCPP_INFO(this->get_logger(), "Inch:%hhd", message.random);
            }
        );
    }

private:
    Publisher<msgs::msg::InchToMeter>::SharedPtr publisher_; // 发布者
    TimerBase::SharedPtr timer_; // 定时器
};


int main(int argc, char * argv[]){
    init(argc,argv);
    spin(std::make_shared<inch_talker>());
    shutdown();
    return 0;
}

