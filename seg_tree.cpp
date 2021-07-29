void build(long long seg[], vector<long long>a, int st, int end, int pos) {

    if(st == end) {
        seg[pos] = a[st];
    }

    else {
        int mid = (st+end)/2;
        build(seg, a, st, mid, 2*pos+1);
        build(seg, a, mid+1, end, 2*pos+2);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }
}

long long getSum(long long seg[], int l, int r, int st, int end, int pos) {
    if(l <= st && r >= end)
        return seg[pos];
    else if(l > end || r < st)
        return 0;
    else {
        int mid = (st+end)/2;
        long long leftSum = getSum(seg, l, r, st, mid, 2*pos+1);
        long long rightSum = getSum(seg, l, r, mid+1, end, 2*pos+2);
        return leftSum + rightSum;
    }
}

void update(long long seg[], vector<long long> a, int x, long long val, int st, int end, int pos) {
    if(st == end) {
        a[st] = val;
        seg[pos] = val;
    }
    else {
        int mid = (st+end)/2;
        if(x <= mid)
            update(seg, a, x, val, st, mid, 2*pos+1);
        else
            update(seg, a, x, val, mid+1, end, 2*pos+2);
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }
}