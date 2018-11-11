#include<stdio.h>
void increment_date(int *y, int *m, int *d){
	if ((*m == 12) && (*d == 31)){
		*y += 1;
		*m = 1;
		*d = 1;
	}
	else
		if (((*m == 1)&& (*d == 31)) ||
			((*m == 3) && (*d == 31))||
			((*m == 5) && (*d == 31))||
			((*m == 7) && (*d == 31))||
			((*m == 8) && (*d == 31))||
			((*m == 10) && (*d == 31))||
			((*m == 12) && (*d == 31))||
			((*m == 4) && (*d == 30))||
			((*m == 6) && (*d == 30))||
			((*m == 9) && (*d == 30))||
			((*m == 11) && (*d == 30))||
			(((*y)%4!=0)&&(*m==2)&&(*d==28))||
			(((*y)%100==0)&&((*y)%400!=0)&& (*m == 2) && (*d == 28))||
			(((*y)%400==0)&&(*m==2)&&(*d==29))||
			((*y)%4==0)&&((*y)%100!=0)&&(*m==2)&&(*d==29))
		{
			*m += 1;
			*d = 1;
		}
		else		{
			*d += 1;
		}
	return;
}
void decrement_date(int *y, int *m, int *d){
	if ((*m == 1) && (*d == 1)){
		*y -= 1;
		*m = 12;
		*d = 31;
	}
	else
		if (((*m == 2) && (*d == 1)) ||
			((*m == 4) && (*d == 1)) ||
			((*m == 6) && (*d == 1)) ||
			((*m == 8) && (*d == 1)) ||	
			((*m == 9) && (*d == 1)) ||	
			((*m == 11) && (*d == 1)))
		{
			*m -= 1;
			*d = 31;
		}
		else
			if (((*m == 5) && (*d == 1)) ||
				((*m == 7) && (*d == 1)) ||
				((*m == 10) && (*d == 1)) ||
				((*m == 12) && (*d == 1)))
			{
				*m -= 1;
				*d = 30;
			}
			else
				if ((((*y) % 4 != 0) && (*m == 3) && (*d == 1)) ||
					(((*y) % 100 == 0) && ((*y) % 400 != 0) && (*m == 3) && (*d == 1)))
				{
					*m -= 1;
					*d = 28;
				}
				else
					if ((((*y) % 400 == 0) && (*m == 3) && (*d == 1)) ||
						((*y) % 4 == 0) && ((*y) % 100 != 0) && (*m == 3) && (*d == 1))
					{
						*m -= 1;
						*d = 29;
					}
					else 
					{
						*d -= 1;
					}
	return;
}
int main(void){
	int y, m, d;

	printf("input year month date:");
	scanf("%d %d %d",&y,&m,&d);

	decrement_date(&y, &m, &d);
	printf("decrement_date:%d %d %d\n",y,m,d);

	increment_date(&y, &m, &d);
	increment_date(&y, &m, &d);
	printf("increment_date:%d %d %d\n",y,m,d);

	return 0;
}

