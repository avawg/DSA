import queue  # 采用堆存储

def huffman_coding(nums):
    que = queue.PriorityQueue()
    n = len(nums)
    weights = [0 for _ in range(2 * n - 1)]
    parents = [-1 for _ in range(2 * n - 1)]
    for i in range(n):
        que.put((nums[i], i))
        weights[i] = nums[i]

    sum = 0
    # 每次从堆中弹出两个最小值，求和后，压入堆中。时间复杂度nlog(n)
    id = n
    while id < 2 * n - 1:
        val1, id1 = que.get()
        val2, id2 = que.get()
        weights[id] = val1 + val2
        parents[id1] = parents[id2] = id
        que.put((weights[id], id))
        sum += weights[id]
        id += 1
    print(weights)
    print(parents)
    return sum


if __name__ == "__main__":
    nums = [3, 4, 8, 98, 100]
    sum = huffman_coding(nums)
    print(sum)
