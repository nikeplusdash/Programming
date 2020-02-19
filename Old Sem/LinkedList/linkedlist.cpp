#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Node
{
private:
  int data;
  Node *next;

public:
  void Display();
  void Insert(int n);
  void Delete(int n);
  void InsertAt(int k, int n);
  void DeleteAt(int k);
} *head = NULL;

void Node::Display()
{
  Node *start = new Node();
  start = head;
  if (start == NULL)
  {
    std::cout << "List is empty" << std::endl;
    return;
  }
  while (start != NULL)
  {
    std::cout << start->data << "\t";
    start = start->next;
  }
  std::cout << std::endl;
}

void Node::Insert(int n)
{
  Node *Insert = new Node();
  Insert->data = n;
  Insert->next = head;
  head = Insert;
}

void Node::Delete(int n)
{
  Node *del = new Node();
  Node *prev = new Node();
  del = head;
  if (del->data == n)
  {
    head = del->next;
    free(del);
    return;
  }
  while (del != NULL && del->data != n)
  {
    prev = del;
    del = del->next;
  }
  if (del == NULL)
  {
    std::cout << "Not found" << std::endl;
    return;
  }
  prev->next = del->next;
  free(del);
}

void Node::InsertAt(int k, int n)
{
  Node *next = new Node();
  Node *create = new Node();
  Node *prev = new Node();
  if (k == 1)
    Node::Insert(n);
  next = head;
  while (k > 1 && next != NULL)
  {
    prev = next;
    next = next->next;
    k--;
  }
  if (k > 1)
  {
    std::cout << "Invalid Entry" << std::endl;
    return;
  }
  prev->next = create;
  create->next = next;
  create->data = n;
}

void Node::DeleteAt(int k)
{
  Node *next = new Node();
  next = head;
  if (k == 0)
    return;
  while (k > 1 && next != NULL)
  {
    next = next->next;
    k--;
  }
  if (next == NULL)
  {
    std::cout << "Invalid Entry" << std::endl;
    return;
  }
  Node::Delete(next->data);
}

int main()
{
  Node n;
  n.Display();
  n.Insert(5);
  n.Insert(79);
  n.Insert(7);
  n.Insert(9);
  n.InsertAt(0, 69);
  n.Display();
  n.Delete(79);
  n.DeleteAt(1);
  n.Display();
}