
class Router:
    def __init__(self, memoryLimit: int):
        self.mySet = set()                               # uniqueness check
        self.myQ = deque()                               # FIFO for eviction
        self.destMap = defaultdict(SortedList)           # destination → sorted timestamps
        self.currentNoOfPackets = 0
        self.memoryLimit = memoryLimit

    # Helper to make a unique key for duplicates
    def makeKey(self, source: int, destination: int, timestamp: int) -> str:
        return f"{source}_{destination}_{timestamp}"

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        holder = self.makeKey(source, destination, timestamp)
        storingPacket = [source, destination, timestamp]

        # Duplicate check
        if holder in self.mySet:
            return False

        # If full, evict oldest packet
        if self.currentNoOfPackets >= self.memoryLimit:
            oldest = self.myQ.popleft()
            oldHolder = self.makeKey(oldest[0], oldest[1], oldest[2])
            self.mySet.remove(oldHolder)
            self.destMap[oldest[1]].remove(oldest[2])
            self.currentNoOfPackets -= 1

        # Add new packet
        self.myQ.append(storingPacket)
        self.mySet.add(holder)
        self.destMap[destination].add(timestamp)
        self.currentNoOfPackets += 1
        return True

    def forwardPacket(self):
        if not self.myQ:
            return []  # no packet to forward
        discardedPacket = self.myQ.popleft()
        self.currentNoOfPackets -= 1
        holder = self.makeKey(discardedPacket[0], discardedPacket[1], discardedPacket[2])
        self.mySet.remove(holder)
        self.destMap[discardedPacket[1]].remove(discardedPacket[2])
        return discardedPacket

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.destMap:
            return 0

        timestamps = self.destMap[destination]
        left = timestamps.bisect_left(startTime)
        right = timestamps.bisect_right(endTime)
        return right - left
