class segmentTree{
	vector<int>seg;
public:
	segmentTree(int n){
		seg.resize(4 * n + 1);
	}

	void build(int ind , int low , int high , vector<int>&arr){
		if(low == high){
			seg[ind] = arr[low];
			return ;
		}
		int mid = low + (high - low)/2 ;
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind + 2 , mid + 1 , high , arr);
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}

	int query(int ind , int low , int high , int l , int r){
		//no overlap
		if(low > r || high < l)
			return inf ;

		if(low >= l && high <= r)
			return seg[ind];

		int mid = low + (high - low)/2 ;
		int left = query(2 * ind + 1 , low , mid , l , r);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r);

		return min(left , right);
	}

	void update(int ind , int low , int high , int i , int val){
		if(low == high){
			seg[ind] = val ;
			return ;
		}
		int mid = low + (high - low)/2 ;
		if(i <= mid){
			update(2 * ind + 1 , low , mid , i , val);
		}else{
			update(2 * ind + 2 , mid + 1 , high , i , val);
		}

		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
};
class lazyProgatioin{
	vector<int>seg;
	vector<int>lazy ;
public:
	lazyProgatioin(int n){
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}

	void build(int ind , int low , int high , vector<int>&arr){
		if(low == high){
			seg[ind] = arr[low];
			return;
		}
		int mid = low + (high - low)/2 ;
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind  + 2, mid + 1, high , arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}

	void update(int ind , int low , int high , int l , int r , int val){
		//update the previous remaining updates 
		//propgate down
		if(lazy[ind] != 0){
			seg[ind] += (high - low + 1) * lazy[ind];
			//progate the remainging lazy updates down for remaining nodes
			if(low != high){
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind] ;
			}
			lazy[ind] = 0 ;
		}
		//no overlap
		//will do nothing just return 
		//low high l r and l r low high
		if(high < l || r < low)
			return ;
		//complete overlap
		if(low >= l && high <= r){
			seg[ind] += (high - low + 1)  * val; 
			// if low not equal to high than its not a leaf and we can propgate 
			if(low != high){
				lazy[2 * ind + 1] += val ;
				lazy[2 * ind + 1] += val ;
			}
			return ;
		}
		//no overlap
		int mid = low + (high - low)/2 ;
		update(2 * ind + 1 , low  , mid , l , r , val);
		update(2 * ind  + 2 , mid + 1 , high , l , r , val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
	int query(int ind , int low , int high , int l , int r){

		// if there are updates remaining in lazy just update them 
		//propgate downwords
		if(lazy[ind] != 0){
			seg[ind] += (high - low + 1) * lazy[ind];
			//progate the remainging lazy updates down for remaining nodes
			if(low != high){
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind] ;
			}
			lazy[ind] = 0 ;
		}
		//no overlarp
		if(high < l || r < low)
			return 0 ;
		//complete overlap
		if(low >= l && high <= r)
			return seg[ind];

		int mid = low + (high - low)/2 ;
		int left = query(2 * ind + 1 , low , mid , l , r);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r);
		return left + right ;
	}
};
class lazyProgatioinmin{
	vector<int>seg;
	vector<int>lazy ;
public:
	lazyProgatioinmin(int n){
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}

	void build(int ind , int low , int high , vector<int>&arr){
		if(low == high){
			seg[ind] = arr[low];
			return;
		}
		int mid = low + (high - low)/2 ;
		build(2 * ind + 1 , low , mid , arr);
		build(2 * ind  + 2, mid + 1, high , arr);
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}

	void update(int ind , int low , int high , int l , int r , int val){
		//update the previous remaining updates 
		//propgate down
		if(lazy[ind] != 0){
			seg[ind] += lazy[ind];
			//progate the remainging lazy updates down for remaining nodes
			if(low != high){
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind] ;
			}
			lazy[ind] = 0 ;
		}
		//no overlap
		//will do nothing just return 
		//low high l r and l r low high
		if(high < l || r < low)
			return ;
		//complete overlap
		if(low >= l && high <= r){
			seg[ind] +=  val; 
			// if low not equal to high than its not a leaf and we can propgate 
			if(low != high){
				lazy[2 * ind + 1] += val ;
				lazy[2 * ind + 1] += val ;
			}
			return ;
		}
		//no overlap
		int mid = low + (high - low)/2 ;
		update(2 * ind + 1 , low  , mid , l , r , val);
		update(2 * ind  + 2 , mid + 1 , high , l , r , val);
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
	int query(int ind , int low , int high , int l , int r){

		// if there are updates remaining in lazy just update them 
		//propgate downwords
		if(lazy[ind] != 0){
			seg[ind] += lazy[ind];
			//progate the remainging lazy updates down for remaining nodes
			if(low != high){
				lazy[2 * ind + 1] = lazy[ind];
				lazy[2 * ind + 2] = lazy[ind] ;
			}
			lazy[ind] = 0 ;
		}
		//no overlarp
		if(high < l || r < low)
			return INT_MAX ;
		//complete overlap
		if(low >= l && high <= r)
			return seg[ind];

		int mid = low + (high - low)/2 ;
		int left = query(2 * ind + 1 , low , mid , l , r);
		int right = query(2 * ind + 2 , mid + 1 , high , l , r);
		return min(left , right);
	}
};
