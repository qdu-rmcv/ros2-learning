from setuptools import setup

setup(
    name='metric_system',
    version='0.0.0',
    packages=['metric_system'],  # 确保声明包名
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/metric_system']),
        ('share/metric_system', ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    entry_points={
        'console_scripts': [
            # 格式：可执行名 = 包名.模块名:主函数
            'meter_converter = metric_system.meter_converter:main',
        ],
    },
)