#include <iostream>
#include <stdlib.h>
#include <math.h>

class poly {
    private:
    int coeff;
    int exp;
    poly* next;
    poly* prev;
    public:
    poly* Insert(int,int,poly*);
    void Display(poly*);
    poly* Create(poly*);
    poly* Add(poly*,poly*);
    poly* Sort(poly*);
    poly* Copy(poly*);
    poly* Mul(poly*,poly*);
    poly* Remove(poly*);
};

poly* poly::Insert(int x,int n,poly* head) {
    poly* temp = new poly();
    temp->coeff = x;
    temp->exp = n;
    temp->next = temp->prev = NULL;
    if(head == NULL) {head = temp;head->next = head->prev = head;return head;}
    poly* curr = head->prev;
    curr->next = temp;
    temp->prev = curr;
    temp->next = head;
    head->prev = temp;
    return head;
}

poly* poly::Create(poly* head) {
    while(1) {
        int x,n;
        std::cout << "Coeff: ";
        std::cin >> x;
        std::cout << "Expo: ";
        std::cin >> n;
        if(n == -1) break;
        if(x == 0) continue;
        head = Insert(x,n,head);
    }
    head = Remove(Sort(head));
    return head;
}

poly* poly::Add(poly* head1,poly* head2) {
    poly* i = head1;
    poly* j = head2;
    poly* list = NULL;
    poly* end1 = head1->prev;
    poly* end2 = head2->prev;
    end1->next = end2->next = NULL;
    while(i != NULL && j != NULL) {
        if(j->exp > i->exp) {
            list = Insert(j->coeff,j->exp,list);
            j = j->next;
        }
        else if(i->exp > j->exp) {
            list = Insert(i->coeff,i->exp,list);
            i = i->next;   
        }
        else {
            list = list->Insert(i->coeff+j->coeff,i->exp,list);
            i = i->next;
            j = j->next;
        }
    } 
    while(i != NULL) {
        list = list->Insert(i->coeff,i->exp,list);i = i->next;
    }
    while(j != NULL) {
        list = list->Insert(j->coeff,j->exp,list);j = j->next;
    } 
    end1->next = head1;end2->next = head2;
    return list;
}

poly* poly::Mul(poly* head1,poly* head2) {
    poly* i = head1;
    poly* list = NULL;
    do {
        poly* j = head2;
        do {
            int prod = i->coeff * j->coeff;
            int exp = i->exp + j->exp;
            list = list->Insert(prod,exp,list);
            j=j->next;
        } while(j != head2);
        i=i->next;
    } while(i != head1);
    list->Sort(list);
    list->Remove(list);
    list->Display(list);
}

poly* poly::Remove(poly* head) {
    poly* i = head;
    do {
        poly* j = i->next;
        do {
            if(i->exp == j->exp){
                poly* temp = j;
                i->coeff += j->coeff;
                i->next = j->next;
                j->next->prev = i;
                j = j->next;
                delete(temp);
                continue;
            }
            j=j->next;
            
        } while(j != head);
        i=i->next;
    } while(i->next != head);
    return head;
}

poly* poly::Sort(poly* head) {
    poly* i = head;
    do {
        poly* j = i->next;
        do {
            if(i->exp < j->exp){
                int x = i->exp;
                i->exp = j->exp;
                j->exp = x;
                int y = i->coeff;
                i->coeff = j->coeff;
                j->coeff = y;
            }
            j=j->next;
        } while(j != head);
        i=i->next;
    } while(i->next != head);
    return head;
}

void poly::Display(poly* head){
    if(head == NULL) return;
    poly* curr = head;
    std::cout << "Polynomial: ";
    do {
        if(curr->exp == 0) {std::cout << abs(curr->coeff);}
        else if(curr->exp == 1 && curr->coeff != 1) {std::cout << abs(curr->coeff) << "X";}
        else if(curr->coeff == 1) std::cout << "X" << curr->exp;
        else if(curr == head && curr->coeff < 0) std::cout << " - " << abs(curr->coeff) << "X" << curr->exp;
        else std::cout << abs(curr->coeff) << "X" << curr->exp;
        if(curr->next != head && curr->next->coeff > 0) std::cout << " + ";
        if(curr->next != head && curr->next->coeff < 0) std::cout << " - ";
        curr = curr->next;
    } while(curr != head);
    std::cout << std::endl;
    return;
}

int main() {
    poly p;
    poly* sum;
    poly* mul;
    poly* poly1 = NULL;
    poly* poly2 = NULL;
    std::cout << "Poly 1" << std::endl;
    poly1 = p.Create(poly1);
    std::cout << "Poly 2" << std::endl;
    poly2 = p.Create(poly2);
    std::cout << std::endl;

    p.Display(poly1);
    p.Display(poly2);

    sum = p.Add(poly1,poly2);
    p.Display(sum);
    mul = p.Mul(poly1,poly2);
}