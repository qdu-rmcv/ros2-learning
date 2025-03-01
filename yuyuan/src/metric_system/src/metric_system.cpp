/*
 *  1. metric_system 功能包中的节点订阅/inch 话题，将接收到的英寸值转换为米(1英尺=12 英寸，1英尺=0.3048米)
 *  2. 并将结果以浮点数形式发布到/meter 话题，保留3位小数,
 *  3. 如果接收到的英寸值小于0，则忽略该数据并记录警告信息.
 */

#include <rclcpp/rclcpp.hpp>
#include "randomInch.hpp"
#include "my_msg/msg/mymsg.hpp"

class inch_sub : public rclcpp::Node
{
private:
    rclcpp::Publisher<my_msg::msg::Mymsg>::SharedPtr pub_;
    rclcpp::Subscription<my_msg::msg::Mymsg>::SharedPtr sub_;

    void inch_callback(const my_msg::msg::Mymsg::SharedPtr message)
    {
        Inch inch;
        int random=message->inch;
        float metre = inch.inch2metre(random);// 通过randomInch.hpp中的Inch类实现单位转换
        if (metre >= 0)
        {
            auto message = my_msg::msg::Mymsg(); 
            message.metre = metre;
            pub_->publish(message);
            RCLCPP_INFO(this->get_logger(), "metre:%.3f",metre);
        }
        else
        {
            RCLCPP_WARN(this->get_logger(), "warning,接收到的英寸值小于0,已忽略");
        }
    };

public:
    inch_sub() : Node("inch_listener")
    {
        RCLCPP_INFO(this->get_logger(), "node is running");
        pub_ = this->create_publisher<my_msg::msg::Mymsg>("/meter", 10);
        sub_ = this->create_subscription<my_msg::msg::Mymsg>(
            "/inch",
            10,
            std::bind(&inch_sub::inch_callback, this, std::placeholders::_1));
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<inch_sub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
