/*
 * @Author: BandieraRosa 3132716198@qq.com
 * @Date: 2025-02-27 14:31:48
 * @LastEditors: BandieraRosa 3132716198@qq.com
 * @LastEditTime: 2025-03-19 15:22:16
 * @FilePath: /ros2_learning/src/metric_system/src/sub_node.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"rclcpp/rclcpp.hpp"
#include"msgs/msg/inch_to_meter.hpp"
#include<bits/stdc++.h>

using namespace rclcpp;

int num = 0;
class meter_listener : public Node {
public:
    meter_listener() : Node("meter_listener") {
        RCLCPP_INFO(this->get_logger(), "订阅端节点已创建");
        subscription_ = this->create_subscription<msgs::msg::InchToMeter>("sub", 10, // 创建一个订阅者，订阅名为"sub"的话题，消息类型为上次作业复用的InchToMeter
            [this](const msgs::msg::InchToMeter::SharedPtr msg) { 
                int number = msg->num;
                number += num; // 将消息中的num字段值累加到number上
                RCLCPP_INFO(this->get_logger(), "订阅端接收到服务端信息:%d", number);
            }
        );
    }

private:
    Subscription<msgs::msg::InchToMeter>::SharedPtr subscription_; 
};

int main(int argc, char * argv[]) {
    if(argc>1){ // 如果在启动时命令行中有额外的数字参数，将其累加到num中。此为废案
        for(int i = 1; i < argc; i++) {
            num+=atoi(argv[i]);
        }
    }
    init(argc, argv);
    spin(std::make_shared<meter_listener>());
    shutdown();
    return 0;
}