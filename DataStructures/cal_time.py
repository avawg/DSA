import time
# 定义一个装饰器
def calTime(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print("{} running time: {:.10f} secs.".format(func.__name__, end - start)) # 输出时间
        return result
    return wrapper



