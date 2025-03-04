from setuptools import setup

setup(
    name='british_system',
    version='0.0.0',
    packages=['british_system'],
    install_requires=['setuptools'],
    entry_points={
        'console_scripts': [
            # 格式：可执行名 = 包名.模块名:主函数
            'inch_publisher = british_system.inch_pub:main',
        ],
    },
)