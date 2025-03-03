import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32, Float64

class MeterConverter(Node):
    def __init__(self):
        super().__init__('meter_converter')
        self.subscription = self.create_subscription(Int32, '/inch', self.inch_callback, 10)
        self.publisher_ = self.create_publisher(Float64, '/meter', 10)
        self.get_logger().info('Metric System is running')

    def inch_callback(self, msg):
        inch_value = msg.data
        if inch_value < 0:
            self.get_logger().warn(f'收到无效英寸值: {inch_value}')
            return

        # 转换公式: 1英寸 = 0.3048 / 12 = 0.0254 米
        meter_value = round(inch_value * 0.0254, 3)
        result_msg = Float64()
        result_msg.data = meter_value
        self.publisher_.publish(result_msg)
        self.get_logger().debug(f'转换结果: {inch_value} 英寸 = {meter_value} 米')

def main():
    rclpy.init()
    node = MeterConverter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
