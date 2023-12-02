#include <bits/stdc++.h>
using namespace std;

class poly
{
public:
    int coeff;
    int expo;
    poly *next;

    poly(int coeff, int expo)
    {
        this->coeff = coeff;
        this->expo = expo;
        this->next = NULL;
    }
};

void insert(poly *&head, int coeff, int expo)
{
    poly *newpoly = new poly(coeff, expo);
    if (head == NULL || expo < head->expo)
    {
        newpoly->next = head;
        head = newpoly;
        return;
    }
    else if (expo == head->expo)
    {
        head->coeff += coeff;
        return;
    }
    else
    {
        poly *curr = head;
        while (curr->next != NULL && curr->next->expo <= expo)
        {
            curr = curr->next;
        }
        newpoly->next = curr->next;
        curr->next = newpoly;
    }
}

void create(poly *&head)
{
    cout << "enter the number of elements" << endl;
    int n;
    cin >> n;
    int cof, expo;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the coeff " << i + 1 << endl;
        cin >> cof;
        cout << "enter the expo " << i + 1 << endl;
        cin >> expo;
        insert(head, cof, expo);
    }
}

void display(poly *head)
{
    if (head == NULL)
    {
        cout << "No polynomial" << endl;
    }
    else
    {
        poly *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << "x^" << temp->expo;
            if (temp->next != NULL)
            {
                cout << " + ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

poly *addPolynomials(poly *poly1, poly *poly2)
{
    poly *result = NULL;

    while (poly1 != NULL || poly2 != NULL)
    {
        if (poly1 == NULL)
        {
            insert(result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
        else if (poly2 == NULL)
        {
            insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else if (poly1->expo > poly2->expo)
        {
            insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        }
        else if (poly2->expo > poly1->expo)
        {
            insert(result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
        else
        {
            insert(result, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    return result;
}

poly *multiplyPolynomials(poly *poly1, poly *poly2)
{
    poly *result = NULL;

    while (poly1 != NULL)
    {
        poly *temp = poly2;
        while (temp != NULL)
        {
            int newCoeff = poly1->coeff * temp->coeff;
            int newExpo = poly1->expo + temp->expo;
            insert(result, newCoeff, newExpo);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

int main()
{
    poly *poly1 = NULL;
    poly *poly2 = NULL;

    cout << "Enter the first polynomial:" << endl;
    create(poly1);

    cout << "Enter the second polynomial:" << endl;
    create(poly2);

    poly *sum = addPolynomials(poly1, poly2);
    cout << "Sum of the polynomials:" << endl;
    display(sum);

    poly *product = multiplyPolynomials(poly1, poly2);
    cout << "Product of the polynomials:" << endl;
    display(product);

    return 0;
}
