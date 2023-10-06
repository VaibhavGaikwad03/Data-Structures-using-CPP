class Array
{
	int *Arr;
	int size;
	int len;

	void swap(int &p1, int &p2);
	void copy(int *src);
	void copy(Array &refObj);

public:
	Array();
	Array(int size);
	~Array();
	void display();
	void add_element(int x);
	void insert_element(int index, int x);
	void delete_element(int index);
	int search_element(int key);
	int get(int index);
	void set(int index, int x);
	int max();
	int min();
	int sum();
	float avg();
	void reverse();
	void insert_sort(int x);
	bool is_sorted();
	void rearrange();
	int length();
	Array *merge(Array &refObj);
	Array *union_merge(Array &refObj);
	Array *intersection(Array &refObj);
	Array *difference(Array &refObj);
};