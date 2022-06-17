// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o calc calc.cpp; ./calc < calc_test1.in

#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply 
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero {};
class badInput {};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/*******************************************************
 * INSTRUCTOR NOTE: Implement the functions below.     *
 * You may throw exception classes emptyList, divZero, *
 * or badInput from these functions as needed.         *
 ******************************************************/



/*
	******Pseudocode******
		additon Algotithm

	if stack not empty
		addend1 = pop front

		if stack not empty after pop
			addend2 = pop front
			sum = addend1
			sum = addend1 + addend2
			push front sum
		else
			push front addend1
			throw empty list
	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need two numbers for addition
	If list isnt empty, the first number is what is popped from the front of the stack
	
	Next we must check that the list isnt empty after popping one element, i.e. there is at least 2 numbers
	If that is the case, the second number is what is popped from the new front of the list
	sum is defined at the first number, then defined as the first + second number.
	This is then pushed onto the stack as the sum of two numbers.
	Else , there isnt two numbers in the stack, so push the first number and print to user invalid number of operands
	

*/
// EFFECTS: performs + operation
void DoAdd(Dlist<double> &stack) {
  // Implement this function. 
	if(stack.IsEmpty() == false)//list is not empty
	{
		double addend1 = stack.RemoveFront();//first number

		if(stack.IsEmpty() == false)//list isnt empty after popping one element
		{
			
			double addend2 = stack.RemoveFront();//second number
			double sum = addend1;
			sum = addend1 + addend2;//perform addition
			//std::cout << sum << "\n";
			stack.InsertFront(sum);//return sum to stack
		}
		else//list is empty after popping one elem
		{
			stack.InsertFront(addend1);//return first number to stack
			throw emptyList();
		}
					
	}
	else//list is empty
	{
		throw emptyList();	
	}

}



/*
	******Pseudocode******
		Subtract Algotithm

	if stack not empty
		sub1 = pop front

		if stack not empty after pop
			sub2 = pop front
			diff = sub1
			diff = sub1 + sub2
			push front diff
		else
			push front sub1
			throw empty list
	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need two numbers for subtraction
	If list isnt empty, the first number is what is popped from the front of the stack
	
	Next we must check that the list isnt empty after popping one elements, i.e. there is at least 2 numbers
	If that is the case, the second number is what is popped from the new front of the list
	Diff is defined at the first number, then defined as the first - second number.
	This is then pushed onto the stack as the diff of two numbers.
	Else , there isnt two numbers in the stack, so push the first number and print to user invalid number of operands

*/
// EFFECTS: performs - operation
void DoSub(Dlist<double> &stack) {
  // Implement this function.
  
	if(stack.IsEmpty() == false)//list is not empty
	{
		//std::cout << "hi";
		double sub1 = stack.RemoveFront();//first number
		
		if(stack.IsEmpty() == false)//list isnt empty after popping one element
		{
			double sub2 = stack.RemoveFront();//second number
			double diff = sub1;
			diff = sub2 - sub1;//perform subtraction
			//std::cout << diff << "\n";
			stack.InsertFront(diff);//return diff to stack
		}
		else
		{
			stack.InsertFront(sub1);//return first number to stack
			throw emptyList();
		}
	}
	else
	{
		throw emptyList();	
	}
	
}



/*
	******Pseudocode******
		Multiply Algotithm

	if stack not empty
		fact1 = pop front

		if stack not empty after pop
			fact2 = pop front
			prod = fact1
			prod = fact1 + fact2
			push front prod
		else
			push front fact1
			throw empty list
	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need two numbers for Multiplication
	If list isnt empty, the first number is what is popped from the front of the stack
	
	Next we must check that the list isnt empty after popping one elements, i.e. there is at least 2 numbers
	If that is the case, the second number is what is popped from the new front of the list
	Prod is defined at the first number, then defined as the first * second number.
	This is then pushed onto the stack as the product of two numbers.
	Else , there isnt two numbers in the stack, so push the first number and print to user invalid number of operands
	
*/
// EFFECTS: performs * operation
void DoMult(Dlist<double> &stack) {
  // Implement this function.

	if(stack.IsEmpty() == false)//list is not empty
	{
		//std::cout << "hi";
		double fact1 = stack.RemoveFront();//first number
		
		if(stack.IsEmpty() == false)//list isnt empty after popping one element
		{
			double fact2 = stack.RemoveFront();//second number
			double prod = fact1;
			prod = fact1 * fact2;//perform multiplication
			//std::cout << prod << "\n";
			stack.InsertFront(prod);//return prod to stack
		}
		else//list is empty after popping one elem
		{
			stack.InsertFront(fact1);//return first number to stack
			throw emptyList();
		}
	}
	else//list is empty
	{
		throw emptyList();	
	}
}



/*
	******Pseudocode******
		Divide Algotithm

	if stack not empty
		fact1 = pop front

		if stack not empty after pop
			fact2 = pop front
			quot = fact1
			quot = fact1 + fact2
			push front quot
		else
			push front fact1
			throw empty list
	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need two numbers for division
	If list isnt empty, the first number is what is popped from the front of the stack
	
	Next we must check that the list isnt empty after popping one elements, i.e. there is at least 2 numbers
	If that is the case, the second number is what is popped from the new front of the list
	Quot is defined at the first number, then defined as the first / second number.
	This is then pushed onto the stack as the quotient of two numbers.
	Else , there isnt two numbers in the stack, so push the first number and print to user invalid number of operands
	
*/
// EFFECTS: performs / operation
void DoDiv(Dlist<double> &stack) {
  // Implement this function.
	if(stack.IsEmpty() == false)//list is not empty
	{
		//std::cout << "hi";
		double fact1 = stack.RemoveFront();//first number
		
		if(stack.IsEmpty() == false)//list isnt empty after popping one element
		{
			double fact2 = stack.RemoveFront();//second number
			double quot = fact1;
			quot = fact1 / fact2;//perform division
			//std::cout << Quot << "\n";
			stack.InsertFront(quot);//return quotient to stack
		}
		else//list is empty after popping one elem
		{
			stack.InsertFront(fact1);//return first number to stack
			throw emptyList();
		}
	}
	else//list is empty
	{
		throw emptyList();	
	}
	
}



/*
	******Pseudocode******
		Inverse Algotithm

	if stack not empty
		neg = pop front
		neg = neg * -1
		push front neg

	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need one number to inverse
	If list isnt empty, the number is what is popped from the front of the stack
	the number is then defined again as itself times negative 1, for the inverse
	the result is then pushed onto the stack to be saved
	Else , the list is empty,so print to user invalid number of operands
	
*/
// EFFECTS: performs n operation
void DoNeg(Dlist<double> &stack) {
  // Implement this function.
	if(stack.IsEmpty() == false)//list is not empty
        {
		double neg = stack.RemoveFront();//number to inverse
		neg = neg * -1;//make inverse
		stack.InsertFront(neg);//return neg to stack
	}
	else//list is empty
	{
		throw emptyList();
	}
}



/*
	******Pseudocode******
		Duplicate Algotithm

	if stack not empty
		copy1 = pop front
		push front copy 1
		push front copy 1

	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need one number to inverse
	If list isnt empty, the number to be copied is what is popped from the front of the stack
	Push the original to the front, and the copy after that.
	Else , the list is empty,so print to user invalid number of operands
*/
// EFFECTS: performs d operation
void DoDup(Dlist<double> &stack) {
  // Implement this function.
	if(stack.IsEmpty() == false)//list is not empty
	{
		//std::cout << "hi";
		double copy1 = stack.RemoveFront();//number to copy
		//double copy2 = copy1;
		stack.InsertFront(copy1);//push number 
        stack.InsertFront(copy1);//push copy of number
		
	}
	else//list is empty
	{
		throw emptyList();	
	}
}



/*
	******Pseudocode******
		reverse Algotithm

	if stack not empty
		rev1 = pop front

		if stack not empty after pop
			rev2 = pop front
			push front rev 1
			push front rev 2
		else
			push front rev1
			throw empty list
	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need two numbers for division
	If list isnt empty, the first number is what is popped from the front of the stack
	else the list is emtpy and print to user invalid number of operands
	Next we must check that the list isnt empty after popping one elements, i.e. there is at least 2 numbers
	If that is the case, the second number is what is popped from the new front of the list
	The two numbers are the pushed onto stack in reversed order.
	Else , there isnt two numbers in the stack, so push the first number and print to user invalid number of operands
*/
// EFFECTS: performs r operation
void DoRev(Dlist<double> &stack) {
  // Implement this function.
	if(stack.IsEmpty() == false)//list is not empty
    {
		double rev1 = stack.RemoveFront();//first number
		
		if(stack.IsEmpty() == false)//list isnt empty after popping one element
        {
			double rev2 = stack.RemoveFront();//second number
			stack.InsertFront(rev1);//push in reverse order
			stack.InsertFront(rev2);
        }
        else//list is empty after popping one elem
        {
			stack.InsertFront(rev1);//return first number to stack
            throw emptyList();
        }
	
	}
	else//list is empty
        {
                throw emptyList();
        }
}



/*
	******Pseudocode******
		Print Algotithm

	if stack not empty
		p = pop front
		print p
		push front p

	else
		throw empty list

	*****Comments*****
	Must first check that the list is not empty, as we need one number to print
	If list isnt empty, the number is what is popped from the front of the stack
	Print thde popped number to the user
	Push the number to the front to restore the stack to its orginal setting
	Else , the list is empty,so print to user invalid number of operands
	
*/
// EFFECTS: performs p operation
void DoPrint(Dlist<double> &stack) {
  // Implement this function.
	if(stack.IsEmpty() == false)//list is not empty
	{
		double p = stack.RemoveFront();//number to print
		std::cout<< p << '\n';//print
		stack.InsertFront(p);//return to stack
	}
	else//list is empty
	{
		throw emptyList();
	}
}


/*
	******Pseudocode******
		clear Algotithm

	while stack not empty
		pop front

	

	*****Comments*****
While the stack is not empty, pop elements from the stack
This clears everything from the stack, and will always work regardless if empty.
	
*/
// EFFECTS: performs c operation
void DoClear(Dlist<double> &stack) {
  // Implement this function.
	while(stack.IsEmpty() == false)//do while list isnt empty
	{
		stack.RemoveFront();//clear each elem of stack
	}
	
}

/*
	******Pseudocode******
		Print all Algotithm

	while stack not empty
		val = pop front
		print val
	
		if val = pop front
			push back val
			
	print new line
	
	*****Comments*****
	Must first check that the list is not empty, as we need one number to print
	If list isnt empty, the value is what is popped from the front of the stack
	print this value to the user
	if the value is equal to the value popped from the front, push value to the back.
	This ensures that the loop doesnt continue to print the stack over and over.
*/
// EFFECTS: performs a operation
void DoPrintAll(Dlist<double> &stack) {
  // Implement this function.
	while(stack.IsEmpty() == false)//list is not empty
	{
		double val = stack.RemoveFront();//pop each elem
		//stack.InsertFront(val);
		std::cout << val << " " ;
		if(val == stack.RemoveFront())//stack hasnt repreated
		{
			//stack.InsertFront(copy);
			stack.InsertBack(val);//print done
		
		}
				 
	}
	 
	std::cout << '\n';//new line
	
	
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

bool DoOne(Dlist<double> &stack) {
  std::string s;
  double d;

  std::cin >> s;
  switch (s[0]) {
  case '+':
    DoAdd(stack);
    break;
  case '-':
    DoSub(stack);
    break;
  case '*':
    DoMult(stack);
    break;
  case '/':
    DoDiv(stack);
    break;
  case 'n':
    DoNeg(stack);
    break;
  case 'd':
	  DoDup(stack);
	  break;
  case 'r':
	  DoRev(stack);
	  break;
  case 'p':
	  DoPrint(stack);
	  break;
  case 'c':
	  DoClear(stack);
	  break;
  case 'a':
	  DoPrintAll(stack);
	  break;
  case 'q':
	  return true;
	  break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
	  d = std::atof(s.c_str());
    stack.InsertFront(d);
	  break;
  default:
	  badInput e;
	  throw e;
	  break;
  }
  return false;
}

int main() {
  Dlist<double> stack;

  bool done = false;
  while (!done) {
    try {
      done = DoOne(stack);
    } catch (emptyList e) {
      std::cout << "Not enough operands\n";
    } catch (divZero e) {
      std::cout << "Divide by zero\n";
    } catch (badInput e) {
      std::cout << "Bad input\n";
    }
  }
}
