
class SegmentTree {
public:
    SegmentTree(const vector<int>& nums) : nums(nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
     }

    void update(int index, int value) {
        update(0, 0, n - 1, index,value);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

private:
    vector<int> nums;
    vector<int> tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            if(mid+2<=end && nums[mid] < nums[mid+1] && nums[mid+1] > nums[mid+2]) tree[node]+=1;
            if(mid-1>=start && mid+1 <= end && nums[mid-1]<nums[mid] && nums[mid] > nums[mid+1]) tree[node]+=1;
        }
    }

    void update(int node, int start, int end, int idx,int value) {
        if (start == end) {
            if(start==idx){
                nums[idx] = value;
            }
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx,value);
            } else {
                update(2 * node + 2, mid + 1, end, idx,value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
            if(mid+2<=end && nums[mid] < nums[mid+1] && nums[mid+1] > nums[mid+2]) tree[node]+=1;
            if(mid-1>=start && mid+1<=end && nums[mid-1]<nums[mid] && nums[mid] > nums[mid+1]) tree[node]+=1;
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        int ans = 0;
        if(mid+2<=end && mid+2<=r && mid>=l && nums[mid] < nums[mid+1] && nums[mid+1] > nums[mid+2]) ans+=1;
        
        if(mid-1>=start && mid+1<=end && mid-1>=l && mid+1<=r && nums[mid-1]<nums[mid] && nums[mid] > nums[mid+1]) ans+=1;

        return left + right + ans;
    }
};