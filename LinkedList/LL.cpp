#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

Node *LLinput()
{

    int n;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    int x;
    cout << "Enter the head node: ";
    cin >> x;
    Node *head = new Node(x);
    Node *ptr = head;
    int i = 1;
    while (i < n)
    {

        cout << "Enter the next node: ";
        cin >> x;
        Node *temp = new Node(x);
        ptr->next = temp;
        ptr = temp;
        i++;
    }

    return head;
}

void LLprint(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
}

void LLprintR(Node *head)
{

    if (head == NULL)
        return;

    cout << head->data << " -> ";
    LLprintR(head->next);
}

int LLcount(Node *head)
{

    if (head == NULL)
        return 0;
    int cnt = 1;
    cnt += LLcount(head->next);
    return cnt;
}

Node *LLith(Node *head, int i)
{

    Node *temp = head;

    int cnt = 1;

    while (temp != NULL)
    {

        if (cnt == i)
            break;
        temp = temp->next;
        cnt++;
    }
    return temp;
}

void LLinsert(Node *head, int i, int x)
{

    Node *temp = head;

    int cnt = 1;

    while (temp != NULL)
    {

        if (cnt == i - 1)
            break;
        temp = temp->next;
        cnt++;
    }

    Node *newNode = new Node(x);
    newNode->next = temp->next;
    temp->next = newNode;
}

void LLinsertR(Node *head, int i, int x)
{

    if (head == NULL)
        return;

    if (i == 2)
    {
        Node *newNode = new Node(x);
        newNode->next = head->next;
        head->next = newNode;
    }

    LLinsertR(head->next, i - 1, x);
}

void LLdelete(Node *head, int i)
{

    Node *temp = head;
    int cnt = 1;

    while (temp != NULL)
    {

        if (cnt == i - 1)
            break;
        temp = temp->next;
        cnt++;
    }

    Node *targetNode = temp->next;
    temp->next = temp->next->next;
    delete (targetNode);
}

Node *LLReverse(Node *head)
{

    Node *ptr = new Node(head->data);
    head = head->next;
    while (head != NULL)
    {

        Node *newNode = new Node(head->data);
        newNode->next = ptr;
        ptr = newNode;
        head = head->next;
    }
    return ptr;
}

bool isPalindrome(Node *head)
{

    int midcnt = ceil(LLcount(head) / 2);
    Node *midhead = head;
    while (midcnt > 0)
    {

        midhead = midhead->next;
        midcnt--;
    }

    Node *rmidhead = LLReverse(midhead);

    while (head != NULL && rmidhead != NULL)
    {

        if (head->data != rmidhead->data)
            return false;

        head = head->next;
        rmidhead = rmidhead->next;
    }

    return true;
}

Node *ReverseLLR(Node *head, Node *rhead)
{

    if (!head)
        return rhead;
    Node *newNode = new Node(head->data);
    newNode->next = rhead;
    rhead = newNode;
    return ReverseLLR(head->next, rhead);
}

Node *SwapLL(Node *head, int i, int j)
{

    Node *ans;

    if ((i == 0 || j == 0) && abs(i - j) == 1)
    {

        Node *c1 = head;
        Node *c2 = head->next;
        c1->next = c2->next;
        c2->next = c1;
        ans = c2;
    }

    else if (abs(i - j) == 1)
    {

        Node *temp = head;
        int first = i < j ? i : j;

        while (temp != NULL)
        {

            if (first == 1)
            {
                Node *p1 = temp;
                Node *c1 = p1->next;
                Node *c2 = c1->next;
                c1->next = c2->next;
                p1->next = c2;
                c2->next = c1;
                ans = head;
                break;
            }
        }
    }

    else if (i == 0 || j == 0)
    {

        Node *temp = head;
        Node *c1 = head;
        Node *p2;
        Node *c2;
        int nz = i == 0 ? j : i;
        while (temp != NULL)
        {

            if (nz == 1)
            {
                p2 = temp;
                c2 = p2->next;
                Node *t = c2->next;
                c2->next = c1->next;
                p2->next = c1;
                c1->next = t;
                ans = c2;
                break;
            }
            temp = temp->next;
            nz--;
        }
    }

    else
    {
        int first = i < j ? i : j;
        int second = i > j ? i : j;
        Node *temp = head;
        Node *p1, *p2, *c1, *c2;

        while (temp != NULL)
        {

            if (first == 1)
            {

                p1 = temp;
                c1 = p1->next;
            }

            if (second == 1)
            {

                p2 = temp;
                c2 = p2->next;
                break;
            }
            temp = temp->next;
            first--;
            second--;
        }

        Node *t = c2->next;
        c2->next = c1->next;
        c1->next = t;
        p1->next = c2;
        p2->next = c1;
        ans = head;
    }

    return ans;
}

Node *getTail(Node *head)
{
    while(head->next!=NULL)
        head = head->next;
    return head;
}

Node *kReverse(Node *head, int k) 
{
    Node *temp = head;
    int noofNodes = LLcount(head);
    int cnt = 1;
    Node *h1, *t1, *h2, *t2, *ans, *nextHead;

    while(temp!=NULL)
    {
        if(cnt == k) {
            cnt = 1;
            break;
        }
        temp = temp->next;
        cnt++;
    }

    t1 = temp;
    nextHead = t1->next;
    t1->next = NULL;
    h1 = LLReverse(head);
    ans = h1;
    t1 = getTail(h1);
    temp = nextHead;
    h2 = nextHead;

    while(temp!=NULL) {

        if(cnt == k) {

            t2 = temp;
            nextHead = t2->next;
            t2->next = NULL;
            Node *rh = LLReverse(h2);
            Node *rt = getTail(rh);
            t1->next = rh;
            h2 = nextHead;
            t1 = rt;
        }
        cnt++;
        temp = temp->next;
    }


    Node *rh = LLReverse(h2);
    t1->next = rh;

    return ans;

}

Node *krev(Node *head, int k) {

    int noOfNodes = LLcount(head);
    int kdivs = noOfNodes/k;
    Node *h1, *t1, *h2, *t2, *nxt;
    h1 = head;
    t1 = LLith(h1,k);
    h1 = t1->next;
    t1->next = NULL;
    Node *ansHead = LLReverse(head);
     t2 = getTail(ansHead);

    for(int i=2;i<=kdivs;i++) {

        t1 = LLith(h1,k);
        nxt = t1->next;
        t1->next = NULL;
        h2 = LLReverse(h1);
        t2->next = h2;
        t2 = getTail(h2);
        h1 = nxt;
    }

    return ansHead;
}

Node* KthNode(Node *head, int k,int size) {

    //Size technique
    // if(head == NULL)
    //     return NULL;
    
    // Node* ans = KthNode(head->next,k,size-1);
    // if(k == size) {
    //     ans = head;
    // }

    // return ans;

    //Running Technique

    Node *p1, *p2;

    Node *temp = head;
    p1 = head;
    int cnt = k;

    while(temp) {

        if(cnt == 1) {
            p2 = temp;
            break;
        }
        cnt--;
        temp = temp->next;
    }

    while(p2->next != NULL) {
        p1= p1->next;
        p2= p2->next;
    }

    return p1;
 
}

int main()
{

    Node *head = LLinput();
    // LLprintR(head);
    // cout<<"\nNo. of nodes = "<<LLcount(head);
    // LLinsert(head,5,9);
    // LLinsertR(head,3,9);
    // LLdelete(head,3);
    int cnt = LLcount(head);
    cout<<KthNode(head,3,cnt)->data;
}