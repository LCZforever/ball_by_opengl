
#include"snake1.h"
//��꺯��������(x,y)��ʹ����ƶ���ָ��λ��
void Pos(int x,int y)
{   
    COORD pos={x,y};    
        
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);    
} 
//�ڶ������캯������(x,y)����ʼ��
snake::snake(GLdouble X, GLdouble Y, GLdouble Z)
{
	NODE *p = new NODE;
	p->x = X;
	p->y = Y;
	p->z = Z;
	p->next = nullptr;
	head = p;
}
//���������캯������ʼ������ͷ*��ַ*
snake::snake(NODE*b)
{
	if (b == nullptr)
	{
		NODE*p = new NODE;
		head = p;
    }
	else
	{
		head = b;
	}
		
}
//��������ɾ����
snake::~snake()
{
	NODE *p = head;
	while (head)
	{
		p = head;
	    head = head->next;
	    delete(p);
	}

}
//���iλ�õ�X����
int snake::GetX(int i)
{
	NODE*p = head;
	int j = 0;
	while (p &&  j != i)
	{
		p = p->next;
		j++;
	}
	if (p == nullptr)return -1;
	return p->x;	
}
//���iλ�õ�Y����
int snake::GetY(int i)
{
	NODE*p = head;
	int j = 0;
	while (p &&  j != i)
	{
		p = p->next;
		j++;
	}
	if (p == nullptr)return -1;
	return p->y;
}
//������(x,y)�����Ҳ����ص�һ�γ��ֵ�λ��
int snake::search(int X, int Y)
{
	NODE *p = head;
	int i = 0;
	while (p != nullptr)
	{
		if (p->x == X && p->y == Y)
			return i;	
			i++;
		p = p->next;
	
	}
	return -1;
}
//������b���ӵ�a����
void snake::LinkAllin(NODE *b)
{
	NODE *t = head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=b;
}
//�������һ��NDOE�����ﲻ�����κε�ַ��Ϣ�����������滻����
void snake::CopyNODEin(NODE*b)
{
	if (head == nullptr)
	{
		NODE *w = new NODE;
		head = w;
	}
	NODE *p;
	NODE *r = head;	
	p = (NODE*)new NODE;
	r->x = b->x;
	r->y = b->y;
	r->next = nullptr;
	b = b->next;
	while (b != nullptr)
	{
		p = (NODE*)new NODE;
		p->x = b->x;
		p->y = b->y;
		p->next = nullptr;
		r->next = p;
		r = r->next;
		b = b->next;
	}
}
void CopyNODEin(snake*s)
{
}
//�������һ��NDOE�����ﲻ�����κε�ַ��Ϣ���������ݲ��������iΪ����λ��
void snake::CopyNODEin(int i, NODE*b)
{
	NODE *in, *p, *r;
	int j = 0;
	in = head;
	if (i == 0)
	{
		r = new NODE;
		r->x = b->x;
		r->y = b->y;
		r->next = nullptr; 
		head= r;
		b = b->next;
		while (b != nullptr)
		{
			p = (NODE*)new NODE;
			p->x = b->x;
			p->y = b->y;
			p->next = nullptr;
			r->next = p;
			r = r->next;
			b = b->next;
		}
		r->next = in;
		return;
	}
	while (in &&j < i - 1)
	{
		in = in->next;
		j++;
	}
	if (in == nullptr)  return;
	r = in;
	while (b != nullptr)
	{
		p = (NODE*)new NODE;
		p->x = b->x;
		p->y = b->y;
		p->next = nullptr;
		r->next = p;
		r = r->next;
		b = b->next;
	}
	r->next = in->next;
	return;
}

void snake::CopyNODEout(NODE*b)//�������NODE�����ﲻ�����κε�ַ��Ϣ�����ݿ����������NODE������
{
	if (head == nullptr)return;
	NODE*p;
	NODE*t = head;
	NODE*r;
	NODE*e;
	p = new NODE;
	p->x = head->x;
	p->y = head->y;
	p->next = nullptr;
	e = p;

	while (t != nullptr)
	{
		r = new NODE;
		r->x = t->x;
		r->y = t->y;
		r->next = nullptr;
		p->next = r;
		p = p->next;
		t = t->next;
	}
	*b = *e;
}
//�ѵ�ǰ�����������������ݺ�*��ַ*��ȡ����
void snake::GetNODE(NODE*b)
{
	if (head == nullptr)return;
	
	b->x = head->x;
	b->y = head->y;
	b->next = head->next;
	
}
//����һ������Ԫ�أ�x,y)��λ��i��
void snake::InsertOnein(int i, GLdouble X, GLdouble Y, GLdouble Z, GLdouble BLUE,GLdouble GREEN,GLdouble RED,GLdouble R)
{
	NODE *in = head, *on;
	int j = 0;
	if (i == 0)
	{
		on = new NODE;
		on->x = X;
		on->y = Y;
		on->z = Z;
		on->blue = BLUE;
		on->green = GREEN;
		on->red = RED;
		on->radius = R;
		on->next = in;
		head = on;
		return ;
	}
	while (in &&j < i - 1)
	{
		in = in->next;
		j++;
	  }
	if (in == nullptr)
		return;
	on = (NODE*)new NODE[1];
	on->x = X;
	on->y = Y;
	on->z = Z;
	on->blue = BLUE;
	on->green = GREEN;
	on->red = RED;
	on->radius = R;
	on->next = in->next;
	in->next = on;
	return;
}
void snake::InsertOnein(int i, GLdouble X, GLdouble Y, GLdouble Z)
{
	NODE *in = head, *on;
	int j = 0;
	if (i == 0)
	{
		on = new NODE;
		on->x = X;
		on->y = Y;
		on->z = Z;
		on->next = in;
		head = on;
		return;
	}
	while (in &&j < i - 1)
	{
		in = in->next;
		j++;
	}
	if (in == nullptr)
		return;
	on = (NODE*)new NODE[1];
	on->x = X;
	on->y = Y;
	on->z = Z;
	on->next = in->next;
	in->next = on;
	return;
}
//��ӡ���������е�������Ϣ
void snake::PrintInfofsanke()
{
	NODE*q = head;

		while(q!=NULL)
		{
			cout <<"The radius is:"<< q->radius << endl;
			cout << "The position is:"<<"(" << q->x << "," << q->y <<","<< q->z << ")    " << endl;
			cout <<"The color is:"<< "(" << q->blue << "," << q->red << "," << q->green << ")  " << endl;

			q=q->next;		
		}
}


//��λ��i��ɾ��һ������
void snake::DeleteOne(int i)
{
	NODE*p = head, *s;
	int j = 0;
	if (i == 0)
	{
		head = head->next;
		delete p;
		p = nullptr;
		return;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == nullptr)
		return;
	s = p->next;
	p->next = p->next->next; 
	delete s;
	s = nullptr;
	return;

}
//��λ��i������һ�����굽����*e��
void snake::DeleteOne(int i, NODE*e)
{
	NODE*p = head;
	int j = 0;
	if (i == 0)
	{
		e->x = p->x;
		e->y = p->y;
		head = head->next;
		delete p;
		p = nullptr;
		return;
	}
	while (p&&j < i - 1)
	{
		j++;
		p = p->next;
	}
	if (p == nullptr)
		return;
	e->x = p->next->x;
	e->y = p->next->y;
	p->next = p->next->next;
	return;


}
//�ϵ��ĺ���������ɾ��
int snake::TakeOnePlace(int i, int X, int Y)
{
	NODE *p = head;
	int j=0;
	if (i == 0)
	{
		p->x = X;
		p->y = Y;
		return-2;
	}
	while (p&&j <i)
	{
		p = p->next;
		j++;
	}
	if (j < i ) return -1;

	p->x = X;
	p->y = Y;
	return-2;
}
//�����ª����һ�仰"this->head=in"
void snake::TakeAllPlace(NODE*in)
{

	this->head = in;
}
void snake::BeNullhead()
{
	head = nullptr;
}
int snake::Lenthofsnake()
{

	//if (head == nullptr)return 0;
	NODE*pp = head;
	int len = 0;
	while (pp != nullptr)
	{
		len++;
		pp = pp->next;
	}
	return len;
}

void snake::DeleteNODE()
{
	NODE *p = head;
	while (head)
	{
		head = head->next;
		delete (p);
		p = head;
	}
}
double Rand(double L, double R)
{
	return L + (R - L) * rand() * 1.0 / RAND_MAX;
}
double LiangDianJuLi(double x1, double y1, double z1, double x2, double y2, double z2 )
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);
}