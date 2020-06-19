template <typename T>
class Queue{
	T* theQueue_;
	int capacity_;
	int used_;
	int front_;
	int back_;
	void grow(){
		T* temp = new T[capacity_*2];
		int j=front_;
		for(int i=0;i<used_;i++){
			temp[i]=theQueue_[j];
			j=(j+1)%capacity_;
		}
		delete [] theQueue_;
		theQueue_= temp;
		capacity_=capacity_*2;	
		front_=0;
		back_=used_;
	}
public:
	Queue(int capacity=100){
		theQueue_=new T[capacity];
		capacity_=capacity;
		used_=0;
		front_=0;
		back_=0;
	}
	void enqueue(const T& data){
		if(used_ == capacity_){
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