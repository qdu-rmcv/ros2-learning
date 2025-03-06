#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <cstdlib>
#include <chrono>


using namespace std::chrono_literals;// 简化时间单位写法

class BritishNode:public rclcpp::Node{
public:
    BritishNode():Node("british_node"){
        // 创建发布器
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("/inch",10);
        
        timer_ = create_wall_timer(100ms, std::bind(&BritishNode::timer_callback, this));
        srand(time(nullptr));
    }
    private:
    void timer_callback(){
        auto message = std_msgs::msg::Int32();
        message.data = rand()%101;      //0-100
        publisher_->publish(message);       //发布到/inch话题


    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;//不能带括号




};


int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);                 
    rclcpp::spin(std::make_shared<BritishNode>()); 
    rclcpp::shutdown();
    return 0;
}
