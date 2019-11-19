#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define BUFF 50

typedef struct pointer
{
	double X, Y, Z, sum;
	struct pointer *next;
}pointer;

typedef struct header
{
	struct pointer *head;
	int amount;
}header;

header *createList();
void destroyList(header *aList);

pointer *createPointer();
void addPointer(header *aList);
void deletePointer(header *aList);

pointer *swapList(pointer *prev, pointer *thisone);
void printList(header *aList);

//================================================================

int main()
{
	system("chcp 1251 & cls");
	
	int n, num;
	header *List = createList();
    printf("������ ������\n");
	
	if(List)
	do{
		printf("\n1. ������ ����������\n2. ���������� ��� ��������\n");
		printf("3. ���������� ������\n4. ������� �������\n");
		printf("5. ������� ��� ��������\n6. ��������� ������\n\n�������: ");
		scanf("%d", &num);
		
		switch(num)
		{
		case 1:
			do{
				printf("���������� ����� ��� �����: ");
				scanf("%d", &n);
			}while(n < 1);
			
			for(int i = 0; i < n; i++)
				addPointer(List);
			break;
			
		case 2:
			if(List->head)
				printList(List);
			else
				printf("������ ����\n");
			break;
			
		case 3:
			if(List->head)
				List->head = swapList(NULL, List->head);
			else
				printf("������ ����\n");
			break;
			
		case 4:
			if(List->head)
			{
				do{
					printf("���������� ����� ��� ��������: ");
					scanf("%d", &n);
				}while(n < 0);
				
				for(int i = 0; i < n; i++)
					deletePointer(List);
				printf("\n������� �������.\n");
			}
			else
				printf("������ ����\n");
			break;
			
		case 5:
			if(List->head)
			{
				for(int i = 0; i < List->amount; i++)
					deletePointer(List);
				printf("������ ������� �����.\n");
			}
			else
				printf("������ ����\n");
			break;
			
		case 6:
			if(List)
			{
				destroyList(List);
				printf("������ ������� �����.\n\n");
			}
			break;
			
		default:
			printf("���������.\n");
			break;
		}
	}while(num != 6);
	
	system("pause");
	return 0;
}

//================================================================

header *createList()
{
    header *aList = (header *)malloc(sizeof(header));
	
    if(aList)
    {
        aList->amount = 0;
        aList->head = NULL;
    }
    return aList;
}

void destroyList(header *aList)
{
    if(aList)
    {
	    if(aList->head)
	    {
	        pointer *aNode = aList->head;
			
	        while(aNode)
	        {
	            pointer *toDelete = aNode;
	            aNode = aNode->next;
	            free(toDelete);
	        }
	    }
	    free(aList);
    }
}

pointer *createPointer()
{
    double x, y, z;
    printf("\n������� ���������� X: ");
    scanf("%lf", &x);
    printf("������� ���������� Y: ");
    scanf("%lf", &y);
    printf("������� ���������� Z: ");
    scanf("%lf", &z);
    
	pointer *tmp = (pointer *)malloc(sizeof(pointer *));
	if(tmp)
	{
		tmp->X = x;
		tmp->Y = y;
		tmp->Z = z;
		tmp->sum = myPow(x, y, z);
		tmp->next = NULL;
		printf("������ ������\n");
	}
	else
		exit(1);
	return tmp;
}

void addPointer(header *aList)
{
    if(aList)
    {
        pointer *aNode = createPointer();
		
        if(aNode)
        {
            if(!aList->head)			//������
                aList->head = aNode;
            else
            {
            	if(aNode->sum < aList->head->sum)	//������
            	{
					aNode->next = aList->head;
					aList->head = aNode;
            	}
            	else
            	{
            		pointer *tmp = aList->head;
	            	while(tmp->next && aNode->sum > tmp->next->sum)
	            		tmp = tmp->next;
					
					if(tmp->next)	//��������
					{
						aNode->next = tmp->next;
						tmp->next = aNode;
					}
					else			//�����
						tmp->next = aNode;
				}
			}
            aList->amount++;
        }
        else
        	printf("������\n");
    }
}

void deletePointer(header *aList)
{
	if(aList->head)
	{
		pointer *tmp = aList->head;
		aList->head = aList->head->next;
		free(tmp);
		aList->amount--;
	}
}

double myPow(double aX, double aY, double aZ)
{
	aX *= aX;
	aY *= aY;
	aZ *= aZ;
	return (double)sqrt((double)aX + (double)aY + (double)aZ);
}

pointer *swapList(pointer *prev, pointer *thisone)
{
	if(thisone->next)
	{
		pointer *tmp = thisone->next;
		thisone->next = prev;
		return swapList(thisone, tmp);
	}
	else
	{
		thisone->next = prev;
		return thisone;
	}
}

void printList(header *aList)
{
	if(aList->head)
	{
		pointer *tmp = aList->head;
		while(tmp)
		{
			printf("Point(%lg, %lg, %lg)\n", tmp->X, tmp->Y, tmp->Z);
			tmp = tmp->next;
		}
	}
}
