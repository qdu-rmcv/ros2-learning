#include"rclcpp/rclcpp.hpp"
#include"std_msgs/msg/int8.hpp"
#include"std_msgs/msg/float32.hpp"
#include<bits/stdc++.h>

using namespace rclcpp;
using namespace std_msgs;

class meter_listener : public Node { // 订阅者节点，订阅发自/inch话题的inch，转换为meter并发布到/meter话题
public:
    meter_listener() : Node("meter_listener") {
        RCLCPP_INFO(this->get_logger(), "meter_listener node is running!");
        publisher_ = this->create_publisher<msg::Float32>("/meter", 10); // 发布者，话题为/meter
        subscription_ = this->create_subscription<msg::Int8>("/inch", 10, // 订阅者，从/inch话题订阅消息
            [this](const msg::Int8::SharedPtr msg) { // lambda处理消息
                int8_t inch = msg->data;
                if (msg->data < 0) { // 若收到的inch为负数，警告并返回
                    RCLCPP_WARN_STREAM(get_logger(), "收到inch为负数");
                    return;
                }
                float meter = inch * 0.0254;

                RCLCPP_INFO(this->get_logger(), "Heard Inch: %hhd, Meter: %.3f", inch, meter);
                msg::Float32 message;
                meter = round(meter * 1000) / 1000; // 保留三位小数（但topic echo时会有明显误差）
                message.data = meter;
                publisher_->publish(message); // 发布转换后的meter至/meter话题
            }
        );
    }

private:
    Subscription<msg::Int8>::SharedPtr subscription_; // 订阅者
    Publisher<msg::Float32>::SharedPtr publisher_; // 发布者
};

int main(int argc, char * argv[]) {
    init(argc, argv);
    spin(std::make_shared<meter_listener>());
    shutdown();
    return 0;
}