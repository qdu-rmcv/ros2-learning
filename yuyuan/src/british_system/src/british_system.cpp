/*
 *  british_system 功能包中的节点应以10Hz的频率在/inch 话题上发布随机整数值，范围为[0, 100]
 */

#include <rclcpp/rclcpp.hpp>
#include "randomInch.hpp"
#include "my_msg/msg/mymsg.hpp"

class inch_pub : public rclcpp::Node
{
private:
    rclcpp::Publisher<my_msg::msg::Mymsg>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    void timer_callback()
    {
        auto message = my_msg::msg::Mymsg();
        Inch inch;                        // 使用randomInch.hpp中的Inch类实现随机整数值的生成
        int inch1 = inch.get_inch();
        message.inch = inch1;
        pub_->publish(message);
        RCLCPP_INFO(this->get_logger(), "inch:%d",inch1);
    };

public:
    inch_pub() : Node("inch_talker")
    {
        RCLCPP_INFO(this->get_logger(), "node is running");
        pub_ = this->create_publisher<my_msg::msg::Mymsg>("/inch", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&inch_pub::timer_callback, this));
    }
};

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);
    auto node = std::make_shared<inch_pub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
