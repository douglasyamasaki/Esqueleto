#pragma once
template <class T>
class List {
private:
	template<class T>
	class Element {
	private:
		Element<T>* pNext;
		Element<T>* pPrev;
		T* data;
	public:
		Element<T>* getNext() { return pNext; }
		Element<T>* getPrev() { return pPrev; }
		T* getData() { return data; }
		void setData(T* data) { this->data = data; }
		void setNext(Element<T>* next) { this->pNext = next; }
		void setPrev(Element<T>* prev) { this->pPrev = prev; }
		Element() { pNext = nullptr; pPrev = nullptr; data = nullptr; }
		~Element() { pNext = nullptr; pPrev = nullptr; data = nullptr; }
	};
	Element<T>* current;
	Element<T>* last;
	Element<T>* first;
	int size = 0;
public:
	template<class T>
	class Iterator {
	private:
		Element<T>* info;
	public:
		//void first() { info = getFirst(); }
		~Iterator(){ info = nullptr; }
		T* operator* () { return (&(info->getData())); }
		void operator++(int ) { info= info ->getNext();}
		void operator--() { info = info->getPrev(); }
		bool operator!= (Element<T>* ele) { return !(ele == info); }
		void operator= (Element<T>* ele) { info = ele; }
		void operator-() {
			if (info == nullptr)
				//printf("erro na lista op-");
			if (info->getPrev() == nullptr) {
				info->getNext()->setPrev(nullptr);
				first = info->getNext();
				delete info;
			}
			else if (info->getNext() == nullptr) {
				info->getPrev()->setNext(nullptr);
				last = info->getPrev();
				delete info;
			}
			else {
				info->getNext()->setPrev(info->getPrev());
				info->getPrev()->setNext(info->setNext());
				delete info;
			}
		}
		
		public:

			Element<T>* getInfo() { return info; }
	};
	Element<T>* getCurrent() { return current; }
	Element<T>* getLast() { return last; }
	Element<T>* getFirst() { return first; }
	int getSize() { return size; }
	void setCurrent(Element<T>* current) { this->current = current; }
	void setLast(Element<T>* last) { this->last = last; }
	void setFirst(Element<T>* first) { this->first = first; }
	void add(T* data) {
		Element<T>* pNew = new Element<T>();
		pNew->setData(data);
		size++;
		if (first == nullptr)
			current = first = pNew;
		else {
			current->setNext(pNew);
			pNew->setPrev(current);
			current = pNew;
			//last = pNew;
		}
	}
	void clean() {
		Element<T>* it;
		Element<T>* saveIt;
		it = saveIt = first;
		while (it != nullptr) {
			saveIt = saveIt->getNext();
			delete it;
			it = saveIt;
		}
		first = nullptr;
		last = nullptr;
		current = nullptr;
		size = 0;
	}
	List(){}
	~List() {}
};
