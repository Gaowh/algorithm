#include<stdio.h>

#ifndef INT_MAX

#define INT_MAX 2147483647

#endif

#ifndef INT_MIN

#define INT_MIN -2147483648 

#endif



void insert_sort(int a[], int n);

void pop_sort(int a[], int n);

void merge_sort(int a[], int n);
void recursive_mergesort(int a[], int l, int r);
void merge(int a[],int l, int m, int r);

void quick_sort(int a[], int n);
void recursive_quicksort(int a[], int l, int r);
int  partition(int a[], int l, int r);

void heap_sort(int a[], int n);
void build_maxheap(int a[], int n);
void max_heapify(int a[], int i, int heapsize);

void choose_sort(int a[], int n);
void swap(int *a, int *b);
void show(int a[], int n);

int main()
{
	int a[10] = {2,3,1,4,5,9,7,8,0,6};
	//pop_sort(a, 10);
	//insert_sort(a, 10);
	//merge_sort(a, 10);
	//quick_sort(a, 10);
	heap_sort(a, 10);
	//choose_sort(a, 10);
	show(a, 10);


}

void show(int a[], int n){

	int i;
	
	for(i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
/*
 插入排序

 	特点： 稳定，不占用额外内存

	复杂度： 当输入数组已经排好序复杂度为o(n),当输入数据时逆序为o(n^2)
	
	证明算法正确性：
	 
	 1、循环不变式： 在每次循环开始前 A[0...i-1]包含了原来A[0...i-1]的元素，并且已经排好序
	 2、初始：i=1， A[0...1]已排序，成立
	 3、保持：在迭代开始前，A[0...i-1]已排序，目的是将A[i]插入其中，使得A[0..i]排好序，
	    下一轮迭代开始前i++，因此下一轮A[0...i-1]已排好序，循环式保持不变。
	 4、终止：最后i=n， 使得A[0...n-1]已排好序，结束
 
*/
void insert_sort(int a[], int n){

	if(n < 2 ) return ;

	int 	i,j;
	int 	key;
	for( i=1; i<n; i++){
		key = a[i];
		j = i-1;
		/*将A[i] 插入到已排好序的A[0...i-1]当中*/
		
		/*大于A[i]的元素往后移*/
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		/*将A[i] 插入到正确位置*/
		a[j+1] = key;
	}
	return; 
}

/*
  冒泡排序：
   
   特点： 稳定的排序， 不占用额外内存
   思想： 通过两两交换，将大的元素不断的网上移动
   运行时间： 最坏 = 最好：O(n^2)

   比较： 插入排序至少要比冒泡排序速度快
 * */
void pop_sort(int a[], int n){
	
	int i,j;
	for(i = 0; i<n-1; i++){
		for( j=0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				int tmp = a[j];
				a[j] =a[j+1];
				a[j+1] = tmp;
			}
		}
	
	}
	return;
}

/*
 	选择排序：
	    
	    特点：不占用额外空间，不稳定排序
	    思想：每次找一个最小值
	    时间复杂度：好坏都是O(n^2)
*/

void choose_sort(int a[], int n){
	int i,j;
	for(i=0; i<n-1; i++){
		int min = i;
		for(j=i+1; j<n; j++){
			if(a[min] > a[j]) min = j;
		}
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
	return;
}


/*
 	归并排序：
	
	    特点：稳定，占用额外空间
	    思想：采用分治方法解决排序问题
	    时间复杂度：好坏都是O(nlgn)

 */

void merge_sort(int a[], int n){

	recursive_mergesort(a, 0, n-1);
}

/*
 	拆分问题
*/
void recursive_mergesort(int a[], int l, int r){

	if(l < r){
		int m = (l+r)/2;
		recursive_mergesort(a, l, m);
		recursive_mergesort(a, m+1, r);
		merge(a, l, m, r);
	}
}

/*
 	合并：
		用两个数组来保存两边的数据，将两个数组中的数据按大小保存在A[]中
 */
void merge(int a[], int l, int m, int r){
	
	int i,j,k;
	int len1 = m-l+1;
	int len2 = r-m;
	int L[len1+1],R[len2+1];
	for(i=0; i<len1; i++){
		L[i] = a[l+i];
	}

	/*1、这一步很关键， 必须将两个数组的最后一个数据设置成最大的int值*/
	L[i] = INT_MAX;
	for(i=0; i<len2;i++){
		R[i] = a[m+i+1];
	}
	R[i] = INT_MAX;

	/*将两个数组的数据合并起来放在A[]中，按从小到大的顺序*/
	for(i=0,j=0,k=l; k<=r; k++){
		if(L[i] < R[j]) a[k] = L[i++];
		else a[k] = R[j++];
	}
	return;
}


/*
 	快速排序:
		特点：不稳定，不占用额外空间
		最坏运行时间：当数组输入为已经排好序时为O(n^2)
		最佳运行时间：O(nlgn)
		思想：也是分治
			每次调用partition（）将数组划分成两个部分，返回下标k，
			经过一次划分后下标k前面的数据A[x] < A[k],k后的数据A[Y]>=A[k]
			再对下标k前后的数据调用partition（），递归调用


		note：只要partition的划分比列是常数，则效率依然是O(nlgn)
 */

void quick_sort(int a[], int n){

	recursive_quicksort(a, 0, n-1);

}

void recursive_quicksort(int a[], int l, int r){

	if(l<r){
		/*
		 * partition()返回一个key值， 下标key前的数据都比A[key]小，下标key后的数据都大于等于A[key]
		 * A[key]已经排在了最终排序的位置上
		*/

		int key = partition(a, l, r);

		/*对key下标前的数据递归排序*/
		recursive_mergesort(a, l, key-1);
		/*对key下标后的数据递归排序*/
		recursive_mergesort(a, key+1, r);
	}
}

int partition(int a[], int l, int r){
	
	/*key是用来作为划分的元素*/
	int key = a[r];
	
	/*下标i的后一个数据是比key大的数据（如果存在比key大的数据）*/
	int i = l-1, j;
	for(j = l; j<r; j++){
		
		/*
		  当前数据小于key值，则交换下标i后的数据和当前数据
		  因为i后的值大于等于key
		*/
		if(a[j] < key){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	/*将key值（划分值）放到正确的位置上*/
	swap(&a[i+1], &a[r]);

	/*返回划分的下标*/
	return i+1;
}



/*
 	堆排序：
		特性： 不稳定， 不占用额外空间
		时间复杂度：都是O(nlgn)
		思想：利用了最小堆，最大堆这些数据结构，该结构还可以用来实现优先队列
		      优先队列用于进程间调度，任务调度等
		      堆数据结构应用于Dijkstra/Prim算法
*/

/*由于数组下标是从0开始，所以对于求左右孩子的方法和对的heapsize稍作调整*/

void heap_sort(int a[], int n){
	
	/*首先将数据排成一个最大堆的数据结构*/
	build_maxheap(a, n);

	/*	heapsize用来标记堆内最后一个数据的下标
		数组下标是从0开始， 注意处理好这个heapsize*/
	int heapsize = n-1;
	int i;
	
	for(i = n-1; i>0; i--){
		swap(&a[0], &a[i]);
		heapsize--;
		max_heapify(a, 0, heapsize);
	}

}
	
void build_maxheap(int a[], int n){
	/* 用到了堆的一个比较关键的性质：字数组A[|_n/2_|]中的元素都是叶子节点，
	   所以对于这些叶子节点来说他们已经是最大堆的根，从这些节点之前的节点往前调整堆*/
	int i = n/2 - 1 ;
	int heapsize = n-1;
	for(; i>=0; i--){
		max_heapify(a, i, heapsize);
	}
}

void max_heapify(int a[], int i, int heapsize){

	/*  递归的调整堆，判断当前节点和左右孩子的大小(前提是堆中有左右孩子的存在)
	    将当前节点与较大的那个孩子节点交换，并递归调整被交换的孩子节点
	*/
	int largest = i;
	if(i*2+1 <= heapsize && a[i*2+1] > a[largest]) largest =i*2+1;
	if(i*2 +2 <= heapsize && a[i*2+2] > a[largest]) largest = i*2+2;
	if(largest != i){
		swap(&a[largest], &a[i]);
		max_heapify(a, largest, heapsize);
	}
}


void swap(int *a, int *b){
	
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
