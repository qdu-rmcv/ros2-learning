#include "rclcpp/rclcpp.hpp"
#include "my_msg/msg/mymsg.hpp" //用自己的消息接口
#include <cstdlib>


class british: public rclcpp::Node{
    public:
    british(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"british节点已启动"); //打印信息，表示british节点启动
        std::srand(114); //设置随机数种子
        pub_ = this->create_publisher<my_msg::msg::Mymsg>("/inch", 10); //创建发布者，发布到"/inch"话题
        timer_ = this->create_wall_timer(std::chrono::milliseconds(100),std::bind(&british::timer_callback, this));
        //创建定时器，速度10Hz，绑定timer_callback回调函数
    }
    private:
    rclcpp::Publisher<my_msg::msg::Mymsg>::SharedPtr pub_; //声明发布者
    rclcpp::TimerBase::SharedPtr timer_; //声明定时器
    
    void timer_callback(){
        auto mess=my_msg::msg::Mymsg();
        mess.suijishu=std::rand()%101;
        RCLCPP_INFO(this->get_logger(),"发布英寸随机数：%d",mess.suijishu);
        pub_->publish(mess);
    } //定时器回调函数，产生0-100的随机数之后在通过pub_进行发布


};

int main(int argc,char **argv){
    rclcpp::init(argc,argv); //ROS初始化
    auto node=std::make_shared<british>("british_node"); //指向british类的智能指针
    rclcpp::spin(node); 
    rclcpp::shutdown();
    return 0;

}