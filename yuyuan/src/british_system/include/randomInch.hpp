#include <ctime>
#include <cstdlib>

class Inch
{
private:
    int random_inch_;
    float random_metre_;

public:
    Inch() // 生成随机数
    {
        srand((unsigned int)time(NULL));
        random_inch_ = rand() % 101;
    }

    float get_inch()
    {
        return random_inch_;
    }

    float inch2metre(int i)
    {
        random_metre_ = i * 0.0254; // 英寸转米
        return random_metre_;
    }

    // 用于测试warning
    float warning_test()
    {
        return -1;
    }
};