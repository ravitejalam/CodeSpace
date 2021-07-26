class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def func(point1 : List[int], point2 : List[int]):
            if point1[0]*point1[0]+point1[1]*point1[1] > point2[0]*point2[0]+point2[1]*point2[1]:
                return -1
            return 1
        return sorted(points, key = lambda point: point[0]*point[0]+point[1]*point[1])[:k]