//
// Created by Dan Jiang on 2020/4/26.
//

#include "data_structure_linklist.h"
#include <cstdio>
#include <stack>

struct ListNode {
    int m_nValue;
    ListNode *m_pNext;
};

void AddToTail(ListNode **pHead, int value) {
    ListNode *pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if (pHead == nullptr || *pHead == nullptr) {
        *pHead = pNew;
    } else {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != nullptr) {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode **pHead, int value) {
    if (pHead == nullptr || *pHead == nullptr) {
        return;
    }

    ListNode *pToBeDeleted = nullptr;
    if ((*pHead)->m_nValue == value) {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    } else {
        ListNode *pNode = *pHead;
        ListNode *pNextNode = (*pHead)->m_pNext;
        while (pNextNode != nullptr) {
            if (pNextNode->m_nValue == value) {
                pToBeDeleted = pNextNode;
                pNode->m_pNext = pNextNode->m_pNext;
                break;
            }
            pNode = pNode->m_pNext;
            pNextNode = pNextNode->m_pNext;
        }
    }
    if (pToBeDeleted != nullptr) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

void PrintLinkList(ListNode *pHead) {
    if (pHead == nullptr) {
        printf("empty link list\n");
        return;
    }
    ListNode *pNode = pHead;
    while (pNode != nullptr){
        printf("%d ", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

void PrintListReverseIteratively(ListNode *pHead) {
    std::stack<ListNode*> nodes;
    ListNode *pNode = pHead;
    while (pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while (!nodes.empty()) {
        pNode = nodes.top();
        printf("%d ", pNode->m_nValue);
        nodes.pop();
    }
    printf("\n");
}

void PrintListReverseRecursively(ListNode *pHead) {
    if (pHead != nullptr) {
        if (pHead->m_pNext != nullptr) {
            PrintListReverseRecursively(pHead->m_pNext);
        }
    }
    printf("%d ", pHead->m_nValue);
}

ListNode* FindMiddleNode(ListNode *pHead) {
    ListNode *fast = pHead;
    ListNode *slow = pHead;
    while (fast != nullptr &&
           fast->m_pNext != nullptr &&
           fast->m_pNext->m_pNext != nullptr) {
        fast = fast->m_pNext->m_pNext; // two steps
        slow = slow->m_pNext; // one step
    }
    return slow;
}

ListNode* IntersectSorted(ListNode *first, ListNode *second) {
    ListNode *pHead = nullptr;
    ListNode *pNode = nullptr;
    ListNode *pFirst = first;
    ListNode *pSecond = second;
    while (pFirst != nullptr && pSecond != nullptr) {
        if (pFirst->m_nValue == pSecond->m_nValue) {
            ListNode *pNew = new ListNode();
            pNew->m_nValue = pFirst->m_nValue;
            if (pNode == nullptr) {
                pNode = pNew;
                pHead = pNode;
            } else {
                pNode->m_pNext = pNew;
                pNode = pNode->m_pNext;
            }
            pFirst = pFirst->m_pNext;
            pSecond = pSecond->m_pNext;
        } else if (pFirst->m_nValue > pSecond->m_nValue) {
            pSecond = pSecond->m_pNext;
        } else {
            pFirst = pFirst->m_pNext;
        }
    }
    return pHead;
}

void TestListNode() {
    ListNode *pHead = nullptr;
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 6);
    AddToTail(&pHead, 7);
    PrintLinkList(pHead);
//    RemoveNode(&pHead, 6);
//    PrintLinkList(pHead);
//    RemoveNode(&pHead, 5);
//    PrintLinkList(pHead);
//    RemoveNode(&pHead, 3);
//    PrintLinkList(pHead);
//    RemoveNode(&pHead, 7);
//    PrintLinkList(pHead);

    PrintListReverseIteratively(pHead);
    PrintListReverseRecursively(pHead);
    printf("\n");

    ListNode *middleNode = FindMiddleNode(pHead);
    printf("middle = %d\n", middleNode->m_nValue);
    AddToTail(&pHead, 8);
    AddToTail(&pHead, 9);
    AddToTail(&pHead, 10);
    PrintLinkList(pHead);
    middleNode = FindMiddleNode(pHead);
    printf("middle = %d\n", middleNode->m_nValue);

    ListNode *pFirst = nullptr;
    AddToTail(&pFirst, 1);
    AddToTail(&pFirst, 2);
    AddToTail(&pFirst, 8);
    AddToTail(&pFirst, 10);
    AddToTail(&pFirst, 12);
    PrintLinkList(pFirst);
    ListNode *pSecond = nullptr;
    AddToTail(&pSecond, 2);
    AddToTail(&pSecond, 3);
    AddToTail(&pSecond, 8);
    AddToTail(&pSecond, 10);
    AddToTail(&pSecond, 14);
    AddToTail(&pSecond, 16);
    PrintLinkList(pSecond);
    ListNode *intersectNode = IntersectSorted(pSecond, pFirst);
    PrintLinkList(intersectNode);
}