/*
    fstack.cpp

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <tstack.h>

void DisplayMenu ();
void CopyTest    ();
void AssignTest  ();
void ConstTest   ();

fsu::Stack<int,100> stack(b,0);
fsu::Stack<int,100> s3(b,0);
char ofc;
int dir;

int main()
{
  char selection;
  fsu::Stack<int> * sptr = &stack;
  DisplayMenu();
  do
  {
    std::cout << "Enter [command][argument] (\'M\' for menu, \'Q\' to quit): ";
    std::cin >> selection;
    switch(selection)
    {
      case '+': case '1':
        int tval;
        std::cin >> tval;
        sptr->Push(tval);
        break;
      case '-': case '2':
        sptr->Pop();
        break;
      case 'c': case 'C':
        sptr->Clear();
        break;
      case 't': case 'T':
        std::cout << "Top of Stack: " << sptr->Top();
        std::cout << '\n';
        break;
      case 'e': case 'E':
        if (sptr->Empty())
        {
          std::cout << "Stack is empty";
        }
        else
        {
          std::cout << "Stack is not empty";
        }
        std::cout << '\n';
        break;
      case 's': case 'S':
        std::cout << "Stack size     = " << sptr->Size();
        std::cout << '\n';
        break;
      case '=':
        CopyTest();
        AssignTest();
        ConstTest();
        std::cout << '\n';
        break;
      case 'd': case 'D':
        std::cout << "Stack contents:   ";
        sptr->Display(std::cout);
        std::cout << '\n';
        break;
      case 'o': case 'O':
        std::cin >> ofc;
        if(ofc == '0')
        {
          ofc = '\0';
        }
        else if (ofc == 'b' || ofc == 'B')
        { 
          ofc = ' ';
        }
        else if (ofc == 't' || ofc == 'T')
        {
          ofc = '\t';
        }
        else if (ofc == 'n' || ofc == 'N')
        {
          ofc = '\n';
        }
        else
        {
          std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
          break;
        }
        sptr->SetOFC(ofc);
        break;
      case '<':
        dir = +1;
        sptr->SetDIR(+1);
        break;
      case '>':
        dir = -1;
        sptr->SetDIR(-1);
        break;
      case 'u': case 'U':
        std::cout << "Stack Dump():" << '\n';
        sptr->Dump(std::cout);
        break;
      case 'm': case 'M':
        DisplayMenu();
        break;
      case 'q': case 'Q':
        selection = 'Q';
        break;
      default:
        std::cout << "  command not found\n";
    }
  }
  while (selection != 'Q');
  std::cout <<'\n'<< "Have a nice day.\n";
  return 0;
}

void DisplayMenu()
{
  std::cout << "This is a Stack < char >\n"
            << "Push(Tval)  .............  + tval or 1 tval\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Top()  ..................  T\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copy tests  .............  =\n"
            << "Display()  ..............  D\n"
            << "SetOFC(ofc)  ............  O 0|b|t|n\n"
            << "SetDIR(+1)  .............  < (horizontal -->)\n"
            << "SetDIR(-1)  .............  > (vertical   ^  )\n"
            << "Dump()  .................  U\n"
            << "Display this menu  ......  M\n";
}

void CopyTest()
{
  fsu::Stack<int,100> s2(stack);
  s2.SetOFC(ofc);
  s2.SetDIR(dir);
  std::cout << "CopyTest:\n";
  std::cout << "Copied object       size: " << s2.Size() << '\n'
            << "                contents: ";
  s2.Display(std::cout);
  std::cout << "\n";
}

void AssignTest()
{
  s3 = stack;
  s3.SetOFC(ofc);
  s3.SetDIR(dir);
  std::cout << "AssignTest:\n"
            << "Original object     size: " << stack.Size() << '\n'
            << "                contents: ";
  stack.Display(std::cout);
  std::cout << '\n';

  std::cout << "Assignee object     size: " << s3.Size() << '\n'
            << "                contents: ";
  s3.Display(std::cout);
  std::cout << '\n';
}

void ConstTest()
{
  if (stack.Size()==0)
  {
    std::cout << "ConstTest: inactive on empty stack";
  }
  else
  {
    const int t = stack.Top();
    int t2 = stack.Top();
    if (t2 == t)
    {
    std::cout << "ConstTest: OK";
    }
    else
    {
      std::cout << "ConstTest: NOT OK";
    }
  }
}
