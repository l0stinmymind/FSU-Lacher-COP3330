/*
    fqueue.cpp

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <tqueue.h>

void DisplayMenu ();
void CopyTest    ();
void AssignTest  ();
void ConstTest   ();

fsu::Queue<char> queue('\0');
char ofc;

int main()
{
  char selection;
  char tval;
  

  fsu::Queue<char> * qptr = &queue;
  DisplayMenu();
  do
  {
    std::cout << "Enter [command][argument] (\'M\' for menu, \'Q\' to quit): ";
    std::cin >> selection;
    switch(selection)
    {
      case '+': case '1':
        std::cin >> tval;
        qptr->Push(tval);
        break;
      case '-': case '2':
        qptr->Pop();
        break;
      case 'c': case 'C':
        qptr->Clear();
        break;
      case 'f': case 'F':
        std::cout << "Front of Queue: " << qptr->Front();
        std::cout << '\n';
        break;
      case 'e': case 'E':
        if (qptr->Empty())
        {
          std::cout << "Queue is empty";
        }
        else
        {
          std::cout << "Queue is not empty";
        }
        std::cout << '\n';
        break;
      case 's': case 'S':
        std::cout << "Queue size     = " << qptr->Size();
        std::cout << '\n';
        break;
      case '=':
        CopyTest();
        AssignTest();
        ConstTest();
        std::cout << '\n';
        break;
      case 'd': case 'D':
        std::cout << "Queue contents:   ";
        qptr->Display(std::cout);
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
        qptr->SetOFC(ofc);
        break;
      case 'u': case 'U':
        std::cout << "Queue Dump():";
        qptr->Dump(std::cout);
        std::cout << '\n';
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
  std::cout << "This is a Queue < char >\n"
            << "Push(Tval)  .............  + tval or 1 tval\n"
            << "Pop()  ..................  - or 2\n"
            << "Clear()  ................  C\n"
            << "Front()  ................  F\n"
            << "Empty()  ................  E\n"
            << "Size()  .................  S\n"
            << "Copy tests  .............  =\n"
            << "Display()  ..............  D\n"
            << "SetOFC(ofc)  ............  O 0|b|t|n\n"
            << "Dump()  .................  U\n"
            << "Display this menu  ......  M\n";
}

void CopyTest()
{
  fsu::Queue<char> q2(queue);
  std::cout << "CopyTest:\n";
  std::cout << "Copied object       size: " << q2.Size() << '\n'
            << "                contents: ";
  q2.Display(std::cout);
  std::cout << "\n";
}

void AssignTest()
{
  fsu::Queue<char> q3 = queue;
  q3.SetOFC(ofc);
  std::cout << "AssignTest:\n"
            << "Original object     size: " << queue.Size() << '\n'
            << "                contents: ";
  queue.Display(std::cout);
  std::cout << '\n';

  std::cout << "Assignee object     size: " << q3.Size() << '\n'
            << "                contents: ";
  q3.Display(std::cout);
  std::cout << '\n';
}

void ConstTest()
{
  if (queue.Size()==0)
  {
    std::cout << "ConstTest: inactive on empty queue";
  }
  else
  {
    const int t = queue.Front();
    int t2 = queue.Front();
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
