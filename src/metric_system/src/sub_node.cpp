/*
 * @Author: BandieraRosa 3132716198@qq.com
 * @Date: 2025-02-27 14:31:48
 * @LastEditors: BandieraRosa 3132716198@qq.com
 * @LastEditTime: 2025-02-27 23:28:34
 * @FilePath: /ros2_learning/src/metric_system/src/sub_node.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"rclcpp/rclcpp.hpp"
#include"msgs/msg/inch_to_meter.hpp"
#include<bits/stdc++.h>

using namespace rclcpp;

class meter_listener : public Node { // 订阅者节点，订阅发自/inch话题的inch，转换为meter并发布到/meter话题
public:
    meter_listener() : Node("meter_listener") {
        RCLCPP_INFO(this->get_logger(), "meter_listener node is running!");
        publisher_ = this->create_publisher<msgs::msg::InchToMeter>("/meter", 10); // 发布者，话题为/meter
        subscription_ = this->create_subscription<msgs::msg::InchToMeter>("/inch", 10, // 订阅者，从/inch话题订阅消息
            [this](const msgs::msg::InchToMeter::SharedPtr msg) { // lambda处理消息
                int8_t inch = msg->random;
                if (msg->random < 0) { // 若收到的inch为负数，警告并返回
                    RCLCPP_WARN_STREAM(get_logger(), "收到inch为负数");
                    return;
                }
                float meter = inch * 0.0254;

                RCLCPP_INFO(this->get_logger(), "Heard Inch: %hhd, Meter: %.3f", inch, meter);
                meter = round(meter * 1000) / 1000; // 保留三位小数（但topic echo时会有明显误差）
                msg->meter = meter;
                publisher_->publish(*msg); // 发布转换后的meter至/meter话题
            }
        );
    }

private:
    Subscription<msgs::msg::InchToMeter>::SharedPtr subscription_; // 订阅者
    Publisher<msgs::msg::InchToMeter>::SharedPtr publisher_; // 发布者
};

int main(int argc, char * argv[]) {
    init(argc, argv);
    spin(std::make_shared<meter_listener>());
    shutdown();
    return 0;
}