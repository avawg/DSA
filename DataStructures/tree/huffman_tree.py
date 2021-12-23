import queue  # 采用堆存储

def huffmanCoding(weights):
    que = queue.PriorityQueue()
    for weight in weights:
        que.put(weight)  # 建最小堆
    weight_sum = 0
    # 每次从堆中弹出两个最小值，求和后，压入堆中。时间复杂度nlog(n)
    for _ in range(len(weights) - 1):
        min_weight1 = que.get()
        min_weight2 = que.get()
        weight_sum += min_weight1 + min_weight2
        que.put(min_weight1 + min_weight2)
    return weight_sum


if __name__ == "__main__":
    weights = [3, 4, 8, 98, 100]
    min_weight_sum = huffmanCoding(weights)
    print(min_weight_sum)
    