#include "rclcpp/rclcpp.hpp"
#include "my_msg/msg/mymsg.hpp" //用自己的消息接口



class metric: public rclcpp::Node{
    public:
    metric(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"metric节点已启动"); //打印信息,表示metric节点已启动
        pub_ = this->create_publisher<my_msg::msg::Mymsg>("/meter", 10); //创建发布者，发布数据到/meter话题
        sub_ = this->create_subscription<my_msg::msg::Mymsg>("/inch",10,std::bind(&metric::sub_callback,this,std::placeholders::_1));
        //创建订阅者，订阅/inch话题用于接受英寸值，并绑定sub_callback函数，用于处理和发布数据到/meter话题
    }

    private:
    rclcpp::Publisher<my_msg::msg::Mymsg>::SharedPtr pub_; //声明发布者
    rclcpp::Subscription<my_msg::msg::Mymsg>::SharedPtr sub_; //声明订阅者
    
    void sub_callback(const my_msg::msg::Mymsg::SharedPtr mess){
        int random=mess->suijishu; //将接收到的数据保存到random变量中
        if(random>=0){//if..else..判断英寸值是否小于0
            float meter=random*0.3048; //数据转化
            RCLCPP_INFO(this->get_logger(),"转化成米为:%.3f,已发布到/meter话题",meter); //输出INFO信息
            auto mess=my_msg::msg::Mymsg(); 
            mess.zhuanhuanzhi=meter;
            pub_->publish(mess); //通过pub_进行发布
        }else{
            RCLCPP_WARN(this->get_logger(), "接收到的英寸值小于0,已忽略"); //如果英寸值小于0输出警告信息并自动忽略此数据
        }

        
    }


};

int main(int argc,char **argv){
    rclcpp::init(argc,argv); //ROS2初始化
    auto node=std::make_shared<metric>("metric_node"); //指向metric类的智能指针
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}