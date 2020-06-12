/*
PROBLEM:
Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/


class RandomizedSet {
    HashMap<Integer,Integer> map;
    ArrayList<Integer> v;
    Random random=new Random();
    /** Initialize your data structure here. */
    public RandomizedSet() {
        map=new HashMap<Integer,Integer>();
        v=new ArrayList<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        Integer i=map.get(val);
        if(i==null){
            map.put(val,v.size());
            v.add(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        Integer i=map.get(val);
        if(i!=null){
            v.set(i,v.get(v.size()-1));
            map.put(v.get(i),i);
            v.remove(v.size()-1);
            map.remove(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        return v.get(random.nextInt(v.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
