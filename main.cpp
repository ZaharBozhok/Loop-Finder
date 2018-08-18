#include <iostream>
using namespace std;


template<class T>
class SimpleList
{
public:
    class Node
    {
    public:
        Node(const T & value):value(value),next(nullptr){}
        ~Node(){/* Destructing node */}
        const Node * Next()const {return this->next;}
        Node * Next(){return this->next;} // this function is used only in SimpleList
        const T & Value()const {return this->value;}
        void Next(Node * next){this->next = next;}
    private:
        T value;
        Node * next;
    };

    SimpleList():head(nullptr),tail(nullptr),size(0){}
    ~SimpleList();

    void append(const T & value);
    const Node *    Head()  const   {return this->head;}
    const size_t &  Size()  const   {return this->size;}

    const Node * operator[](const size_t & index)const;

private:
    Node * head;
    Node * tail;
    size_t size;
};

template<class T>
SimpleList<T>::~SimpleList() {
    Node * tmpHead = this->head;
    while(this->head)
    {
        Node * tmp = this->head->Next();
        delete this->head;
        this->head = tmp;
    }
    this->tail = nullptr;
}

template<class T>
void SimpleList<T>::append(const T &value)     {
    //First node appended
    if(this->head == nullptr && this->tail == nullptr) {
        this->head = new Node(value);
        this->tail = this->head;
    } else {//Normal case
        this->tail->Next(new Node(value));
        this->tail = this->tail->Next();
    }
    ++this->size;
}

template<typename T>
const typename SimpleList<T>::Node * SimpleList<T>::operator[](const size_t & index) const
{
    size_t counter = 0;
    for(Node *it = this->head; it!= nullptr; it = it->Next())
    {
        if(counter == index)
            return it;
    }
    return nullptr;
}

template<class T>
bool isSimpleLooping(const SimpleList<T> & list, const size_t & amount);


template<class T>
bool isLooping(const SimpleList<T> & list)
{
    if(list.Size() <= 1)
        return true;
    for(size_t i = 1; i<list.Size(); i++)
        if (isSimpleLooping(list,i))
            return true;
    return false;
}

template<class T>
bool isSimpleLooping(const SimpleList<T> & list, const size_t & amount)
{
    const typename SimpleList<T>::Node* start = list.Head();
    const typename SimpleList<T>::Node* comparableStart = start;
    for(size_t i=0; i<list.Size() - amount; i+=amount)
    {
        //Step over
        for(size_t j=0; j<amount; j++)
            if(!(comparableStart = comparableStart->Next()))
                return false;


        //Part equals
        const typename SimpleList<T>::Node* primary = start;
        const typename SimpleList<T>::Node* comparable = comparableStart;
        for(size_t j=0; j<amount; j++,primary=primary->Next(),comparable=comparable->Next())
            if(!primary || !comparable || primary->Value() != comparable->Value())
                return false;
    }
    return true;
}


int main() {

    SimpleList<char> list;
    char ch = 0;
    char stopper = 0;
    cout<<"Enter stop sign : ";
    cin>>stopper;
    while(true){
        cin>>ch;
        if(ch == stopper)
            break;
        list.append(ch);
    }
    cout<<isLooping(list);
    return 0;
}
