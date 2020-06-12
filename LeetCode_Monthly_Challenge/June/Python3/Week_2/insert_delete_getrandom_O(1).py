"""
PROBLEM:
Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
"""


class RandomizedSet:
    def __init__(self):
        self.map, self.arr={}, []

    def insert(self, val: int) -> bool:
        if val not in self.map:
            self.map[val]=len(self.arr)
            self.arr.append(val)
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.map:
            i, last = self.map[val], self.arr[-1]
            self.arr[i], self.map[last] = last, i
            self.arr.pop()
            self.map.pop(val)
            return True
        return False
            
    def getRandom(self) -> int:
        return random.choice(self.arr);
        
# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
