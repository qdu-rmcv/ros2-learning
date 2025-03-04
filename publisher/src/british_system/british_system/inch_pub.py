import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import random
class InchPub(Node):
    def __init__(self):
        super().__init__('inch_publisher')
        self.publisher_ = self.create_publisher(Int32, '/inch', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)    #10hz
        self.get_logger().info('British_System Online')

    def timer_callback(self):
        inch_value = random.randint(0,100)
        msg = Int32()
        msg.data = inch_value
        self.publisher_.publish(msg)
        self.get_logger().debug(f'publish inch msg:{inch_value}')

def main():
    rclpy.init()
    node = InchPub()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()