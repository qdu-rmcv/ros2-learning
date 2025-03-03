import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/navi/learn_ros2/publisher_3.3/install/metric_system'
