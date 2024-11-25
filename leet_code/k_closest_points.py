

"""
K closese points

related to 347. Top K Frequent Elements
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 
"""





import heapq
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # find the distance between each point and the origin 
        # at each step , save the distances and save the point with its distance in a list
        # use max heap that automatically push max value at 1st item

        # using max heap : use negative input to push  heapq.heappush(max_heap,-input)
        #                : use negative input too to  search : ...if points_info[key]==-input:....

        #remove (pop) len(nums)-k element ---> we will end with having least k elements

        points_info_list=[]
        closest_points=[]
        max_heap=[]

        # base case (( very tricky point))
        if len(points)==k:
            return points

        for point in points:
            distance = sqrt((0-point[0])**2 + (0-point[1])**2)
            points_info_list.append([point,distance])
            heapq.heappush(max_heap,-distance)

        # to order the points efficiently , poping max value in each iteration
        for i in range(len(points)-k):
             -heapq.heappop(max_heap)

        # find associated list[list]
        for key,val in points_info_list:
            for dist in max_heap[0:k]:
                if val==-dist:
                    closest_points.append(key)
                    break
        
        return closest_points