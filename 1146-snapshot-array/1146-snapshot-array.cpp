class SnapshotArray {
    
    
public:
    map<int,map<int,int>>mp;
    
    int cnt;
    SnapshotArray(int length) {
    
        cnt=0;
        

        
    }
    
    void set(int index, int val) {
        mp[index][cnt]=val;
        
        
    }
    
    int snap() {
        cnt++;
        int id=cnt-1;
        
        return id;

        
    }
    
    int get(int index, int snap_id) {
        //sabse recent cnt nikalo
        auto it=mp[index].upper_bound(snap_id);
        return (it==begin(mp[index])? 0 : prev(it)->second);
          
        
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */