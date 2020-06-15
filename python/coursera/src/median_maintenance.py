import heapq


def median_maintenance(data):
    median_sum = 0
    median = 0
    max_heap = []
    min_heap = []
    # first 2 elements
    heapq.heappush(max_heap, -min(data[:2]))
    median = -max_heap[0]
    median_sum = median
    heapq.heappush(min_heap, max(data[:2]))
    median = min_heap[0]#(min_heap[0] - max_heap[0])//2
    median_sum += median

    for i in range(2, len(data)):
        y = -max_heap[0]
        z = min_heap[0]

        if data[i] < y:
            heapq.heappush(max_heap, -data[i])
        elif data[i] > z:
            heapq.heappush(min_heap, data[i])
        else:
            # value can be saved in any heap
            heapq.heappush(min_heap, data[i])

        
        if (i+1)%2 == 0: # i starts from zero
            # rebalancing in even round
            if len(max_heap) != len(min_heap):
                if len(max_heap) > len(min_heap):
                    max_elem = -heapq.heappop(max_heap)
                    heapq.heappush(min_heap, max_elem)
                else: 
                    min_elem = heapq.heappop(min_heap)
                    heapq.heappush(max_heap, -min_elem)
            median = -max_heap[0]#(min_heap[0] - max_heap[0]) // 2
        else:
            # get heap with most elements
            if len(max_heap) > len(min_heap):
                median = -max_heap[0]
            else:
                median = min_heap[0]
        
        median_sum += median

    print(median_sum)
    return median_sum


def alg(test_file):
    with open(test_file) as file:
        data = [ int(elem) for elem in file.readlines()]
    
    #return median_maintenance(data)%10000
    media, media_sum = 0,0
    sorted_data = []
    for i, e in enumerate(data, start=0):
        sorted_data.append(e)
        sorted_data.sort()
        media = sorted_data[i//2]
        media_sum += media
    return media_sum%10000

if __name__ == "__main__":
    print(alg("./src/Median.txt"))