/*  tqueue.h

  template function header file for Proj8
*/

#ifndef _TQUEUE_H
#define _TQUEUE_H

namespace fsu
{
  template < typename T>
  class Queue
  {
    // Queue < T > API
  public:
    void     Push     (const T& t);
    T        Pop      ();
    T&       Front    ();
    const T& Front    () const;
    size_t   Size     () const;
    bool     Empty    () const;
    void     Clear    ();

    // extra goodies
    size_t   Capacity () const;
    void     Append   (const Queue& q);
    void     Release  ();

  public:
    Queue             ();              // default constructor
    Queue             (char ofc);      // sets output formatting character
    Queue             (const Queue& q);  // copy constructor
    ~Queue            ();              // destructor
    Queue& operator = (const Queue& q);  // assignment operator

  public:
    void     Display    (std::ostream& os) const; // output queue contents
                                                  // through os - depends on ofc
    void     SetOFC     (char ofc);         // sets output formatting character
    void     Dump       (std::ostream& os) const; // output all private data
                                                  // (for development use only)

  private:
    char    ofc_;

  private:
      class Link
      {
        Link ( const T& t ) : element_(t), nextLink_(nullptr) {}
        T      element_;
        Link * nextLink_;
        friend class Queue<T>;
      };
    Link * firstLink_;
    Link * lastLink_;
    T bad_return_;
  };
  template < typename T >
  std::ostream& operator << (std::ostream& os, const Queue<T>& q)
  {
    q.Display (os);
    return os;
  };
}

#endif

using namespace fsu;

template < typename T >
Queue<T>::Queue(): ofc_('\0'),firstLink_(0),lastLink_(0),bad_return_(T())
{
  //firstLink_->nextLink_ = lastLink_;
} // default constructor

template < typename T >
Queue<T>::Queue (char ofc): ofc_(ofc),firstLink_(0),lastLink_(0),bad_return_(T())
{
  //SetOFC(ofc_);
}      // sets output formatting character

template < typename T >
Queue<T>::Queue (const Queue& q):ofc_(q.ofc_),firstLink_(q.firstLink_),lastLink_(q.lastLink_),bad_return_(T())
{
  Append(q);
}  // copy constructor

template < typename T >
Queue<T>::~Queue()
{
  Release();
  delete firstLink_;
  delete lastLink_;
}              // destructor

template < typename T >
Queue<T>& Queue<T>::operator = (const Queue& q)
{
  firstLink_ = q.firstLink_;
  lastLink_ = q.lastLink_;
  ofc_ = q.ofc_;
  Append(q);
  return *this;
}  // assignment operator

template < typename T >
void Queue<T>::Push (const T& t)
{
  Queue::Link * newLink = new Queue::Link(t);
  if (!Empty())
  {
    lastLink_->nextLink_ = newLink;
    //  newLink->nextLink = lastLink_;
  }
  else
  {
    firstLink_ = newLink;
  }
  lastLink_ = newLink;
}

template < typename T >
T Queue<T>::Pop()
{
  if (Empty())
  {
    std::cout << "** Queue error: 'Pop()' called on Empty Queue";
    std::cout << '\n';
    return bad_return_;
  }
  else if (firstLink_ != lastLink_)
  {
    firstLink_=firstLink_->nextLink_;
    return firstLink_->element_;
  }
  else
  {
    T lastElement = firstLink_->element_;
    firstLink_= 0;
    lastLink_ = 0;
    return lastElement;
  }
}

template < typename T >
T& Queue<T>::Front()
{
  if (Empty())
  {
    std::cout << "** Queue error: 'Front()' called on Empty Queue";
    return bad_return_;
  }
  else
  {
    return firstLink_->element_;
  }
}

template < typename T >
const T& Queue<T>::Front() const
{
  if (Empty())
  {
    std::cout << "** Queue error: 'Front()' called on Empty Queue";
    return bad_return_;
  }
  else
  {
    return firstLink_->element_;
  }
}

template < typename T >
size_t Queue<T>::Size() const
{
  size_t count=0;
  Queue::Link * curLinkPtr = firstLink_;
  if (firstLink_ != 0)
  {
    while (curLinkPtr != lastLink_)
    {
      count += 1;
      curLinkPtr=curLinkPtr->nextLink_;
    }
    count +=1;
  }
  return count;
}

template < typename T >
bool Queue<T>::Empty() const
{
  if (firstLink_==0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template < typename T >
void Queue<T>::Clear()
{
  Release();
}

template < typename T >
size_t Queue<T>::Capacity() const
{
  return Size();
}

template < typename T >
void Queue<T>::Append(const Queue& q)
{
  Queue::Link *curLinkPtr = firstLink_->nextLink_;
  Queue::Link *endLinkPtr = lastLink_;
  if(curLinkPtr != 0)
  {
    for (size_t i = 1; i< q.Size()-2; ++i)
    {
      Push(curLinkPtr->element_);
      curLinkPtr = curLinkPtr->nextLink_;
      lastLink_=endLinkPtr;
    }
  }
}

template < typename T >
void Queue<T>::Release ()
{
  while(!Empty())
  {
    Pop();
  }
}

template < typename T >
void Queue<T>::Display (std::ostream& os) const
{
  if (firstLink_ != 0)
  {
  Queue::Link *curLinkPtr =firstLink_;
  while (curLinkPtr != lastLink_)
  {
    os << ofc_ << curLinkPtr->element_;
    curLinkPtr = curLinkPtr->nextLink_;
  }
  os << ofc_ << curLinkPtr->element_;
  }
} // output queue contents through os - depends on ofc

template < typename T >
void Queue<T>::SetOFC (char ofc)
{
  ofc_=ofc;
}       // sets output formatting character

template < typename T >
void Queue<T>::Dump (std::ostream& os) const
{
  Display(os);
} // output all private data (for development use only)
