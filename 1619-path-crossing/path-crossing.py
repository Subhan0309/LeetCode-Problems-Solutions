class Solution:
   def isPathCrossing(self, path: str) -> bool:
    coordinates = [0, 0]
    mySet = set()
    mySet.add(tuple(coordinates))
    for point in path:
        if point == 'N':
            coordinates[1] += 1
        elif point == 'E':
            coordinates[0] += 1
        elif point == 'W':
            coordinates[0] -= 1
        elif point == 'S':
            coordinates[1] -= 1

        if tuple(coordinates) in mySet:
            return True
        mySet.add(tuple(coordinates))

    return False
