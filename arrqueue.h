template <typename T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	int front_;
	int back_;
public:
	Queue(int capacity=100);{
		theQueue_=new T[capacity];
		capacity_=capacity;
		used_=0;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_ == capcity){
			grow();
		}
		theQueue_[back_]=data;
		back_++;
		if(back_==capacity_){
			back_=0;
		}
		used_++;
	}
	void dequeue(){
		front_=(front_+1)%capacity_;
		used_--;
	}
	T front() const{
		return theQueue_[front_];
	}
	bool isEmpty(){
		return used_==0;
	}
};