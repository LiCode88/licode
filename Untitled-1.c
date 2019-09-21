#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int  maxi = 100;

int n;

typedef struct
{
	char name[20];//姓名
	char num[20];//成绩
	char id[20];//学号
} information;

typedef struct
{
	information data[100];
	int size_;
} sequence_list;

//初始化
void init(sequence_list *p)
{
	p = (sequence_list *)malloc(sizeof(sequence_list));
	p->size_ = 0;
}

//输入
void cin(sequence_list *p)
{
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%s%s", p->data[i].name, p->data[i].num, p->data[i].id);
		p->size_++;
	}
}

//插入
void insert(sequence_list *p, int pos, char name[], char num[], char id[])
{
	if (p->size_ == 100)
	{
		printf("表是满的");
	}
	if (pos<1 || pos>(p->size_+1))
	{
		printf("插入的位置不存在");
	}
	for (int i = p->size_; i >= pos; i--)
	{
		strcpy(p->data[i+1].name, p->data[i].name);
		strcpy(p->data[i+1].num, p->data[i].num);
		strcpy(p->data[i+1].id, p->data[i].id);
	}
	strcpy(p->data[pos].name, name); //复制赋值
	strcpy(p->data[pos].num, num);
	strcpy(p->data[pos].id, id);
	p->size_++;
}

//删除
void delete(sequence_list *p, int pos)
{
	if (p->size_ == 0)
	{
		printf("表是空的");
	}
	if (pos < 1 || pos >p->size_)
	{
		printf("删除位置不存在");
	}
	for (int i = pos; i < p->size_; i++)
	{
		strcpy(p->data[i].name, p->data[i + 1].name);
		strcpy(p->data[i].num, p->data[i + 1].num);
		strcpy(p->data[i].id, p->data[i + 1].id);
	}
	p->size_--;
}

//查找在表中的位置
int find(sequence_list *p, char name[], char num[], char id[])
{
	int i;
	for ( i = 1; i <= p->size_; )
	{
		if (strcmp(p->data[i].name, name)==0 && strcmp(p->data[i].num, num)==0 &&strcmp(p->data[i].id, id)==0)
		
			break;
		
		else  i++; 
	}	
	
	 	if (i>p->size_)
	 {
	 	
		 	return -1;
		 }
	 	else
		  return i;
				
}

//输出
void print(sequence_list *p, int pos)
{
	if (pos < 1 || pos > p->size_)
	{
		printf("无法输出，表内无此结点");
	}
	else
	{
		printf("%s ", p->data[pos].name);
		printf("%s ", p->data[pos].num);
		printf("%s ", p->data[pos].id);
	}
}

int main()
{
    char x='y';//判断是否进行循环
    while(x!='n'&&x!='N'){
	printf("请输入人数\n");
	scanf("%d", &n);
	sequence_list *p;
	init(p);
	printf("输入信息\n");
	cin(p);
	printf("输出第二个人的信息\n");
	print(p, 2);
	printf("\n输出插入新数据后第二个人的信息\n");
	char insert_name[50] = "wxc", insert_num[20] = "15", insert_id[20] = "110";
	insert(p, 2, insert_name, insert_num, insert_id);
	print(p, 2);
	printf("\n输出被查找人的位置\n");
	char find_name[20] = "wxc", find_num[20] = "15", find_id[20] = "110";
	int ans = find(p, find_name, find_num, find_id);
	if (ans != -1)
		printf("信息是第%d个人的\n", ans);
	else
		printf("信息不存在");
	printf("输出删除后第二个人的信息\n");
	delete(p, 2);
	print(p, 2);
	printf("\n输出最后一个人\n");
	print(p,3);

    printf("是否继续操作?\n输入Y 或 N");
    
    scanf("%c",&x);
   
    }
	return 0;
}