import queue  # 采用堆存储

def huffmanCoding(nums):
    que = queue.PriorityQueue()
    n = len(nums)
    tree = [0] * (2 * n - 1)
    parents = [-1 for _ in range(2 * n - 1)]
    for i in range(n):
        que.put((nums[i], i))
        tree[i] = nums[i]

    s = 0
    # 每次从堆中弹出两个最小值，求和后，压入堆中。时间复杂度nlog(n)
    i = n
    while i < 2 * n - 1:
        val1, id1 = que.get()
        val2, id2 = que.get()
        tree[i] = val1 + val2
        parents[id1] = parents[id2] = i
        que.put((tree[i], i))
        s += tree[i]
        i += 1
    print(tree)
    print(parents)
    return s


if __name__ == "__main__":
    nums = [3, 4, 8, 98, 100]
    s = huffmanCoding(nums)
    print(s)
