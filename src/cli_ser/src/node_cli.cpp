#include "rclcpp/rclcpp.hpp"
#include "zidingyi_xiaoxijiekou/srv/fuwu.hpp"
#include "zidingyi_xiaoxijiekou/msg/huati.hpp"

class node_test: public rclcpp::Node{
    public:
    node_test(std::string name):Node(name){
        RCLCPP_INFO(this->get_logger(),"客户端启动!");
        clicent_=this->create_client<zidingyi_xiaoxijiekou::srv::Fuwu>("cli_ser1");
        pub_=this->create_publisher<zidingyi_xiaoxijiekou::msg::Huati>("topic1",10);
    }//构造函数，创建客户端和发布者

    //发送函数，从主函数里面调用，发送两个数num1和num2给服务端进行计算
    void send(int a,int b){
        while (!clicent_->wait_for_service(std::chrono::seconds(1)))
        {
            if(!rclcpp::ok()){
                RCLCPP_INFO(this->get_logger(),"ROS2爆!");
                return;
            }
            RCLCPP_INFO(this->get_logger(),"等待服务端上线");
        }//等待服务端上线

        //发送数据给服务端，同时接收服务端的计算结果，接收时调用cli_callback回调函数
        auto request=std::make_shared<zidingyi_xiaoxijiekou::srv::Fuwu::Request>();
        request->num1=a;
        request->num2=b;
        RCLCPP_INFO(this->get_logger(),"发送数据%d和%d",request->num1,request->num2);
        clicent_->async_send_request(request,std::bind(&node_test::cli_callback,this,std::placeholders::_1));

    }
    private:
    rclcpp::Client<zidingyi_xiaoxijiekou::srv::Fuwu>::SharedPtr clicent_;
    rclcpp::Publisher<zidingyi_xiaoxijiekou::msg::Huati>::SharedPtr pub_;
    void cli_callback(rclcpp::Client<zidingyi_xiaoxijiekou::srv::Fuwu>::SharedFuture future){
        auto request=future.get();
        zidingyi_xiaoxijiekou::msg::Huati mess;
        mess.num_result=request->sum;
        pub_->publish(mess);
    }//回调函数，发送数据到topic话题上，方便node_pub订阅并打印数据


};

int main(int argc,char **argv){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<node_test>("cli01");//创建共享指针
    node->send(12,7);//调用发送函数
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}