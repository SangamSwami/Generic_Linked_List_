#include<iostream>
using namespace std;


#pragma pack(1)

// structure for Singly linked list
template<class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};


// structure for Doubly linked list
template<class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

/////// Singly Linear Linked List /////////

template<class T>
class SinglyLL
{
    public:
       struct nodeS <T>* Head;
       int Count;

       SinglyLL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();

};

template<class T>
SinglyLL<T> :: SinglyLL()
{
    Head = NULL;
    Count = 0;  
}

template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
 
 
 
    Count++;
}

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;   
}

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int Pos)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    struct nodeS <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T> :: DeleteAtPos(int Pos)
{
    struct nodeS <T>* temp1 = Head;
    struct nodeS <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    Count--;    
}

template<class T>
void SinglyLL<T> :: Display()
{
    struct nodeS <T>* temp = Head;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<< " |->";
        temp = temp->next;
    }
    cout<<"NULL\n";   
}



///////// Singly Circular Linked List ////////

template<class T>
class SinglyCL
{
    public:
        int Count;
        struct nodeS <T>* Head;
        struct nodeS <T>* Tail;

    SinglyCL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();
        
};

template<class T>
SinglyCL <T> :: SinglyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCL <T> :: InsertFirst(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL )
    {
        Head = Tail = newn;
        Tail->next = Head;
    }
    else
    {
        newn->next = Head;
        Head = newn;
        Tail->next = Head;
    }
    Count++;   
}


template<class T>
void SinglyCL <T> :: InsertLast(T no)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
        (Tail)->next = Head;
    }
    else
    {
        (Tail)->next = newn;
        Tail = newn;
        (Tail)->next = Head;
    }
    Count++;    
}


template<class T>
void SinglyCL<T> :: Display()
{
    struct nodeS<T>* temp = Head;
    
    cout<<"<-";
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    } while (temp != Tail->next);
    cout<<"\n";   
}

template<class T>
void SinglyCL <T> :: DeleteFirst()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        Tail->next = Head;
        delete temp;
    }
    Count--;    
}

template<class T>
void SinglyCL <T>:: DeleteLast()
{
    struct nodeS <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != Head)
        {
            temp = temp->next;
        }
        Tail->next = Head;
        Tail = temp;
        delete temp->next;
    }
    Count--;    
}

template<class T>
void SinglyCL <T> :: InsertAtPos(T no, int Pos)
{
    struct nodeS <T>* newn = new struct nodeS <T>;

    struct nodeS <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyCL <T> :: DeleteAtPos(int Pos)
{
    struct nodeS <T>* temp1 = Head;
    struct nodeS <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
    Count--;      
}


///////// Doubly Linear Linked List ////////

template<class T>
class DoublyLL
{
    public:
        int Count;
        struct nodeD <T>* Head;

    DoublyLL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();
};

template<class T>
DoublyLL <T>:: DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL <T> :: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head -> prev = newn;
        Head = newn;
        Head->prev = NULL;
    }
    Count++;
}

template<class T>
void DoublyLL <T>:: InsertLast(T no)
{  
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head; 

    newn->data = no;
    newn->next = NULL;
    newn->prev0 = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyLL <T> :: Display()
{
    struct nodeD <T>* temp = Head;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template<class T>
void DoublyLL <T>:: DeleteFirst()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        Head = temp->next;
        delete temp;
    }
    Count--;   
}

template<class T>
void DoublyLL <T>:: DeleteLast()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;       
}

template<class T>
void DoublyLL <T>:: InsertAtPos(T no, int Pos)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyLL <T>:: DeleteAtPos(int Pos)
{

    struct nodeD <T>* temp1 = Head;
    struct nodeD <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    Count--;     
}

///////// Doubly Circukar Linked List ////////

template<class T>
class DoublyCL
{
    public:
        struct nodeD <T>* Head;
        struct nodeD <T>* Tail;
        int Count;

    DoublyCL();

    void InsertFirst(T no);
    void InsertLast(T no);

    void DeleteFirst();
    void DeleteLast();

    void InsertAtPos(T no, int Pos);
    void DeleteAtPos(int Pos);

    void Display();   
};

template<class T>
DoublyCL <T> :: DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCL <T> :: InsertFirst(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;    
    newn->prev = NULL ;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }   
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;   
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

template<class T>
void DoublyCL <T> :: InsertLast(T no)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    newn->data = no;
    newn->next = NULL;    
    newn->prev = NULL ;

    if(Head == NULL && Tail == NULL)
    {
        Head = Tail = newn;
    }   
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;   
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count++;
}

template<class T>
void DoublyCL <T> :: DeleteFirst()
{
    struct nodeD <T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = temp->next;
        delete temp; 
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count--;
}

template<class T>
void DoublyCL <T> :: DeleteLast()
{
    struct nodeD <T>* temp = Tail;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = temp->prev;
        delete temp; 
    }
    Head->prev = Tail;
    Tail->next = Head;
    Count--;
}

template<class T>
void DoublyCL <T> :: InsertAtPos(T no, int Pos)
{
    struct nodeD <T>* newn = new struct nodeD <T>;

    struct nodeD <T>* temp = Head;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        InsertFirst(no);
    }
    else if(Pos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
    Count++;    
}

template<class T>
void DoublyCL <T> :: DeleteAtPos(int Pos)
{
    struct nodeD <T>* temp1 = Head;
    struct nodeD <T>* temp2 = NULL;

    if((Pos < 1) || (Pos > Count+1))
    {
        cout<<"Invalid Postion \n";
    }
    else if(Pos == 1)
    {
        DeleteFirst();
    }
    else if(Pos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        for(int i = 1; i < Pos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;
    }
    Count--;   
}

template<class T>
void DoublyCL <T> :: Display()
{
    struct nodeD <T>* temp = Head;

    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    } while (temp != Tail->next);
    cout<<"\n";    
}
