#ifndef __DLIST_H__
#define __DLIST_H__


/**********************************************************
 * INSTRUCTOR NOTE: Do not modify the class declarations! *
 * The class Dlist is a class template.                   *
 *********************************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  // Maintenance methods

  Dlist();                                // constructor
  Dlist(const Dlist &l);                  // copy constructor
  Dlist &operator=(const Dlist &l);       // assignment
  ~Dlist();                               // destructor

  // Operational methods

  // EFFECTS: returns true if list is empty, false otherwise
  bool IsEmpty() const;

  // MODIFIES: this
  // EFFECTS: inserts o at the front of the list
  void InsertFront(const T &o);

  // MODIFIES: this
  // EFFECTS: inserts o at the back of the list
  void InsertBack(const T &o);

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveFront();

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveBack();

 private:
  // A private type

  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  // Private member variables 

  node   *first; // The pointer to the first node (nullptr if none)
  node   *last;  // The pointer to the last node (nullptr if none)

  // Private utility methods

  // EFFECTS: called by constructors to establish empty list invariant
  void MakeEmpty();

  // EFFECTS: called by copy constructor/operator= to copy nodes
  //          from a source instance l to this instance
  void CopyAll(const Dlist &l);
    
  // EFFECTS: called by destructor and operator= to remove and destroy
  //          all list nodes
  void RemoveAll();
};

// Constructor
template <typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
}

// Copy constructor
template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  MakeEmpty();
  CopyAll(l);
}

// Assignment operator
template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist<T> &l) {
  if (this != &l) {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

// Destructor 
template <typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/**********************************************************
 * INSTRUCTOR NOTE: Implement the member functions below. *
 * These member functions are all function templates.     * 
 *********************************************************/

/* 
	*****PSEUDOCODE*****
		IsEmpty Algorithm
	
	if pointer to first node is null
		list it empty
	else list is not empty
		
	*****COMMENTS*****
 The Logic behind this operational method is very simple
If the pointer to the first node is null, that means that nothing is in the list.
This is also true if the pointer the last node is null, but not necessary here
Else the list is not empty, as the first pointer is pointing to something

*/

// EFFECTS: returns true if list is empty, false otherwise
template <typename T>
bool Dlist<T>::IsEmpty() const {
  // Implement this function.
	if (first == NULL)//If the pointer to the first node is null
	{
		return true;
	}
	else//list not empty
	{
		return false;
	}
}

/* 
	*****PSEUDOCODE*****
      InsertFront Algorithm

  Create a new node with a temporary pointer
  temp pointer = o
  temp pointer next = first
  temp pointer prev = null

  If list not empty
    first nodes prev = temp
  else
    last node = temp
  first node = prev node


	*****COMMENTS*****
  Create a new node with a temporary pointer to be used later.
Temp points at o, and equal to o. This is how the node to be inserted is stored.
the next pointer for temp is equal to first node because we are inserting before the first node.
The previous pointer for temp is null because o will become the first node.

When the list is not empty, using the IsEmpty method, first node's previous equal temp. 
This places temp as the first nodes previous adress.
Else the list must be empty, so the last node is equal to temp.
After the conditional statments, first node is set equal to temp to insert o in front of the list.
*/
// MODIFIES: this
// EFFECTS: inserts o at the front of the list
template <typename T>
void Dlist<T>::InsertFront(const T& o) {
  // Implement this function.
	node* temp = new node;
  temp->o = o;//node to be inserted
  temp->next = first;//first is 2nd node
  temp->prev = NULL;//prev not defined for front insert
	
	if(IsEmpty() == false)//if list not empty
	{
		first-> prev = temp;//first node's previous equal temp
	}
	else
	{
		last = temp;//list must be empty
	}
	first = temp;	//insert o in front of the list
}

/* 
	*****PSEUDOCODE*****
      Insert Back Algorithm
  Create a new node with a temporary pointer
  temp pointer = o
  temp pointer prev = last
  temp pointer next = null

  if list is not empty
    last nodes next = temp
  else
    first node = temp
  last node = temp
    
	*****COMMENTS*****
  Create a new node with a temporary pointer to be used later.
Temp points at o, and equal to o. This is how the node to be inserted is stored.
the previous pointer for temp is equal to first node because we are inserting after the last node.
The next pointer for temp is null because o will become the last node.

When the list is not empty, using the IsEmpty method, last nodes next equals temp 
This places temp as the last nodes next adress.
Else the list must be empty, so the first node is equal to temp.
After the conditional statments, last node is set equal to temp to insert o in back of the list.
*/
// MODIFIES: this
// EFFECTS: inserts o at the back of the list
template <typename T>
void Dlist<T>::InsertBack(const T& o) {
  // Implement this function.
	node*temp = new node;
	temp->o = o;//node to be inserted
	temp->prev = last;//prev is 2nd to last node
  temp->next = NULL;//next is null bc o is last in last

	 if(IsEmpty() == false)//if list not empty
        {
                last-> next = temp;//last node's next equal temp.
        }
        else
        {
                first = temp;//list must be empty
        }
        last = temp;//insert o at back of list
}


/* 
	*****PSEUDOCODE*****
        Remove Front Algorithm
  if list is not empty
    pointer del = first
    first = del's next pointer
      nested if first = null
        last = null
      else
        first's prev = null
  template target = del pointing at o
  delete del
  return target

	*****COMMENTS*****
  First must check if list is empty, if not then method can proceed
  Set node del to first node. This points to the node that will be deleted
  First in the list is then the next node after deletion

  Next compare statments must be nested because you cant delete from an empty list.
  If first is null, then list is empty after delete, so last is also null.
  Else, first isnt null, list isnt empty after delete, so set first's previous pointer to null.

  Templated target variable for different data types equals del pointing at o.
  Node is then deleted, then return target that was deleted.
*/

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveFront() {
  // Implement this function.
	if(IsEmpty() == false)//if list is empty
	{
		node* del = first;
		first = del-> next;//points to the node to be deleted

		if(first == NULL)//if empty after delete
		{
			last = NULL;//list empty
		}
		else//not empty after delete
		{
			first -> prev = NULL;//update list pointers
		}
		T target = del->o;//set target to delete
		delete del;
		return target;
	}
  
}


/* 
	*****PSEUDOCODE*****
        Remove Back Algorithm
   if list is not empty
    pointer del = last
    last = del's next pointer
      nested if last = null
        first = null
      else
        last's next = null
  template target = del pointing at o
  delete del
  return target

	*****COMMENTS*****
  First must check if list is empty, if not then method can proceed
  Set node del to last node. This points to the node that will be deleted
  last in the list is then the prev node after deletion

  Next compare statments must be nested because you cant delete from an empty list.
  If last is null, then list is empty after delete, so first is also null.
  Else, last isnt null, list isnt empty after delete, so set last's next pointer to null.

  Templated target variable for different data types equals del pointing at o.
  Node is then deleted, then return target that was deleted.
*/

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveBack()
{// Implement this function.
  if(IsEmpty() == false)//if list is empty
	{
  
  	node*del = last;
    last = del-> prev;//points to the node to be deleted
  
    if(last == NULL)//if empty after delete
    {
      first = NULL;//list empty
    }
    else//not empty after delete
    {
      last -> next = NULL;//update list pointers
    }
    T target = del->o;//set target to delete
    delete del;
    return target;
    }
}


/* 
	*****PSEUDOCODE*****
        Make empty Algorithm
  first and last nodes are pointing to null

	*****COMMENTS*****
  since first and last nodes are pointing to null, this will produce a empty list.
  This is the same logic that method Isempty uses to check if list is empty.
*/

// EFFECTS: called by constructors to establish empty list invariant
template <typename T>
void Dlist<T>::MakeEmpty() {
  // Implement this function.
	first = NULL;
	last = NULL;
}

/* 
	*****PSEUDOCODE*****
        Copy all Algorithm
  set new node pointer temp equal to the first node in l

  while temp isnt empty
    templated variable copy = temp pointing at o
    Insertback method using copy
    temp = temp's next node

	*****COMMENTS*****
  New pointer temp created to save adress of first node in l
  create templated variable copy in order to be used later. 
  Loop through list and each time insert the copy using the insert back method.
  This adds a node to the copied list each time the loop runs. 
  temp points at the next node in the original list.
  
*/
// EFFECTS: called by copy constructor/operator= to copy nodes
//          from a source instance l to this instance
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l) {
  // Implement this function.

	node* temp = l.first;//save adress of first node in l

	do
	{
		T copy = temp->o;
		InsertBack(copy);//add nodes to copied list
		temp = temp->next;//increment nodes
	}
	while(temp!= NULL);//list not empty
}

/* 
	*****PSEUDOCODE*****
        Remove all Algorithm
  while list not empty
    remove front

	*****COMMENTS*****
  A loop is created and will run as long as list isnt empty.
  Each time the loop runs the front node will be removed.
  This results in an empty list after the loop is finished.
*/

// EFFECTS: called by destructor and operator= to remove and destroy
//          all list nodes
template <typename T>
void Dlist<T>::RemoveAll() {
  // Implement this function.
	do
	{
		RemoveFront();//front node will be removed.
	}
	while(IsEmpty() == false);//list not empty
}

/**** INSTRUCTOR NOTE: DO NOT DELETE #endif FROM END OF FILE. ****/
#endif /* __DLIST_H__ */
