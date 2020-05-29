template <typename T>
class Stack{
	T* theStack_;
	int capacity_;
	int used_;
	void grow(){
		T* temp = new T[capacity_*2];
		for(int i=0;i<capacity_;i++){
			temp[i]=theStack_[i];
		}
		delete [] theStack_;
		theStack_= temp;
		capacity_=capacity_*2;	
	}
public:
	Stack(int capacity=4){
		theStack_=new T[capacity];
		capacity_=capacity;
		used_=0;
	}
	void push(const T& data){
		if(used_==capacity_){
			grow();
		}
		theStack_[used_]=data;
		used_++;
	}
	void pop(){
		used_=used_-1;
	}
	T top() const{
		return theStack_[used_-1];
	}
	bool isEmpty(){
		return used_==0;
	}
};